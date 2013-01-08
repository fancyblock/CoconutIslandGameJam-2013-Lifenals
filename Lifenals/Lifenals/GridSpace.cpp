//
//  GridSpace.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#include "GridSpace.h"
#include <cstdlib>

using namespace std;

#define DELAY_SILENCE_FRAME 2

static int g_offsetX[] = { 1, 0, -1, 0 };
static int g_offsetY[] = { 0, 1, 0, -1 };


GridSpace::GridSpace()
{
    m_displayLayer = NULL;
    m_lifeDisplayLayer = NULL;
    m_germDisplayLayer = NULL;
    m_grids = NULL;
    m_germs = NULL;
    m_curActiveLife = -1;
    m_silenceCnt = 0;
}


GridSpace::~GridSpace()
{
    // clean the grids && release memory
    if( m_grids != NULL )
    {
        //TODO
    }
    
    //TODO 
}


void GridSpace::Create( CCNode* layer )
{
    m_displayLayer = layer;
    m_lifeDisplayLayer = CCNode::create();
    m_germDisplayLayer = CCNode::create();
    m_lifeDisplayLayer->setPosition( ccp(0, 0));
    m_germDisplayLayer->setPosition( ccp(0, 0));
    m_displayLayer->addChild(m_germDisplayLayer, 0);
    m_displayLayer->addChild(m_lifeDisplayLayer, 1);
    
    // create && initial the grid infos
    m_grids = new gridInfo*[GRID_SIZE_WID];
    for( int i(0); i < GRID_SIZE_WID; i++ )
    {
        m_grids[i] = new gridInfo[GRID_SIZE_HEI];
        
        for( int j(0); j < GRID_SIZE_HEI; j++ )
        {
            m_grids[i][j]._life = NULL;
            m_grids[i][j]._nutrient = NULL;
        }
    }
    
    // create life list
    m_lives = CCArray::createWithCapacity(GRID_SIZE_WID*GRID_SIZE_HEI);
    m_lives->retain();
    m_pendingLives = CCArray::createWithCapacity(GRID_SIZE_WID*GRID_SIZE_HEI);
    m_pendingLives->retain();
    m_germs = CCArray::createWithCapacity(GRID_SIZE_WID*GRID_SIZE_HEI);
    m_germs->retain();
}


bool GridSpace::AddLife( SpriteLife* life, int posX, int posY )
{
    gridInfo* grid = getGridInfo( posX, posY );
    
    if( grid == NULL )
    {
        return false;
    }
    
    if( grid->_life != NULL )
    {
        return false;
    }
    
    // add to pending list
    life->SetStatus( eAppear );
    life->SetPosition( posX, posY );
    m_pendingLives->addObject( life );
    
    return true;
}


bool GridSpace::RemoveLife( SpriteLife* life )
{
    return removeLife( life );
}


bool GridSpace::RemoveLife( int posX, int posY )
{
    gridInfo* grid = getGridInfo( posX, posY );
    
    if( grid != NULL && grid->_life != NULL )
    {
        return removeLife( grid->_life );
    }
    
    return false;
}


SpriteLife* GridSpace::GetLife( int posX, int posY )
{
    gridInfo* grid = NULL;
    
    grid = getGridInfo( posX, posY );
    
    return grid->_life;
}


void GridSpace::Update( float elapsed )
{
    SpriteLife* life = NULL;
    int i;
    
    int lifeCnt = m_lives->count();
    
    // activite the life
    // ------------------------------------------------------------------------------------------------
    /**
     * @ limit this part to control the game speed 
     */
    int curActiveLife = getCurActiveLife();         // the index of the current active life ( >= 0 )
    if( curActiveLife < 0 )
    {
        m_silenceCnt++;
    }
    
    if( curActiveLife < 0 && lifeCnt > 0
        && m_silenceCnt > DELAY_SILENCE_FRAME )     // need to set a new one
    {
        m_curActiveLife++;
        m_curActiveLife %= lifeCnt;
        
        life = (SpriteLife*)m_lives->objectAtIndex( m_curActiveLife );
        life->SetStatus( eActive );
        life->onActive();
        
        m_silenceCnt = 0;
    }

    // ------------------------------------------------------------------------------------------------
    
    // update the life
    for( i = 0; i < lifeCnt; i++ )
    {
        life = (SpriteLife*)m_lives->objectAtIndex( i );
        life->onUpdate( elapsed );
    }
    
    // process the pending life ( remove || add new one )
    gridInfo* grid = NULL;
    int x, y;
    for( i = 0; i < m_pendingLives->count(); i++ )
    {
        life = (SpriteLife*)m_pendingLives->objectAtIndex( i );
        
        int status = life->GetStatus();
        life->GetPosition( x, y );
        grid = getGridInfo( x, y );
        
        // add life to the space 
        if( status == eAppear )
        {
            grid->_life = life;
            life->SetContainer( this );
            m_lives->addObject( life );
            life->SetDisplayLayer( m_lifeDisplayLayer );
            life->onAdd();
            
            life->SetStatus( eAlive );
        }
        // remove life from the space 
        else if( status == eDisappear )
        {
            life->SetContainer( NULL );
            m_lives->removeObject( life );
            grid->_life = NULL;
            life->onRemove();
            
            life->SetStatus( eDead );
        }
    }
    m_pendingLives->removeAllObjects();
    
    // update nutrient
    Nutrient* germ = NULL;
    CCArray* removeList = CCArray::create();
    for( i = 0; i < m_germs->count(); i++ )
    {
        germ = (Nutrient*)m_germs->objectAtIndex(i);
        
        germ->Update( elapsed, this );
        
        if( germ->IsValid() == false )
        {
            removeList->addObject( germ );
        }
    }
    
    // remove the invalid germ
    for( i = 0; i < removeList->count(); i++ )
    {
        germ = (Nutrient*)removeList->objectAtIndex(i);
        
        germ->GetPosition(x, y);
        grid = getGridInfo(x, y);
        grid->_nutrient = NULL;
        m_germs->removeObject( germ );
        
        germ->onRemove();
    }
    removeList->release();
    
}


void GridSpace::RemoveAllLives()
{
    //TODO 
}


void GridSpace::GetRandomBlankNeighbor( SpriteLife* life, int& x, int& y )
{
    int selfX, selfY;
    int neighborCnt = 0;
    
    life->GetPosition( selfX, selfY );
    
    // get all the blank neighbor
    int gridX[4];
    int gridY[4];
    for( int i(0); i < 4; i++ )
    {
        gridInfo* grid = getGridInfo( selfX + g_offsetX[i], selfY + g_offsetY[i] );
        
        if( grid != NULL && grid->_life == NULL )
        {
            gridX[neighborCnt] = selfX + g_offsetX[i];
            gridY[neighborCnt] = selfY + g_offsetY[i];
            
            neighborCnt++;
        }
    }
    
    // choose a random result
    if( neighborCnt > 0 )
    {
        int idx = rand() % neighborCnt;
        
        x = gridX[idx];
        y = gridY[idx];
    }
    else
    {
        x = -1;
        y = -1;
    }
}


void GridSpace::GetRandomNeighbor( SpriteLife* life, int& x, int& y )
{
    int selfX, selfY;
    int neighborCnt = 0;
    
    life->GetPosition( selfX, selfY );
    
    // get all neighbor
    int gridX[4];
    int gridY[4];
    for( int i(0); i < 4; i++ )
    {
        gridInfo* grid = getGridInfo( selfX + g_offsetX[i], selfY + g_offsetY[i] );
        
        if( grid != NULL && grid->_life != NULL )
        {
            gridX[neighborCnt] = selfX + g_offsetX[i];
            gridY[neighborCnt] = selfY + g_offsetY[i];
            
            neighborCnt++;
        }
    }
    
    // choose a random result
    if( neighborCnt > 0 )
    {
        int idx = rand() % neighborCnt;
        
        x = gridX[idx];
        y = gridY[idx];
    }
    else
    {
        x = -1;
        y = -1;
    }
    
}


bool GridSpace::AddGerm( int gene, int x, int y )
{
    gridInfo* grid = getGridInfo( x, y );
    
    if( grid->_nutrient == NULL )
    {
        Nutrient* germ = new Nutrient( gene );
        
        grid->_nutrient = germ;
        m_germs->addObject( germ );
        
        germ->SetPosition(x, y);
        germ->SetDisplayLayer( m_germDisplayLayer );
        germ->onAdd();
    }
    
    return false;
}


void GridSpace::MoveLife( SpriteLife* life, int x, int y )
{
    int orgX, orgY;
    
    life->GetPosition( orgX, orgY );
    
    gridInfo* grid = getGridInfo( orgX, orgY );
    grid->_life = NULL;
    
    grid = getGridInfo( x, y );
    grid->_life = life;
    life->SetPosition( x, y );
    
    life->onMove();
}


gridInfo* GridSpace::getGridInfo( int x, int y )
{
    gridInfo* grid = NULL;
    
    if( m_grids == NULL )
    {
        return NULL;
    }
    
    if( x < 0 || y < 0 || x >= GRID_SIZE_WID || y >= GRID_SIZE_HEI )
    {
        return NULL;
    }
    
    grid = &m_grids[x][y];
    
    return grid;
}


bool GridSpace::removeLife( SpriteLife* life )
{
    int x, y;
    life->GetPosition( x, y );
    
    gridInfo* grid = getGridInfo( x, y );
    
    if( grid != NULL )
    {
        // add to pending list
        life->SetStatus( eDisappear );
        m_pendingLives->addObject( life );
    }
    
    return false;
}


int GridSpace::getCurActiveLife()
{
    int idx = -1;
    
    for( int i(0); i < m_lives->count(); i++ )
    {
        SpriteLife* life = (SpriteLife*)m_lives->objectAtIndex( i );
        
        if( life->GetStatus() == eActive )
        {
            idx = i;
            m_curActiveLife = idx;
            
            break;
        }
    }
    
    return idx;
}

