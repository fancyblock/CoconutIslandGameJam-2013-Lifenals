//
//  GridSpace.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#include "GridSpace.h"


GridSpace::GridSpace()
{
    m_displayLayer = NULL;
    m_grids = NULL;
    m_curActiveLife = -1;
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
    int curActiveLife = getCurActiveLife();
    if( curActiveLife < 0 && lifeCnt > 0 )         // need to set a new one
    {
        m_curActiveLife++;
        m_curActiveLife %= lifeCnt;
        
        life = (SpriteLife*)m_lives->objectAtIndex( m_curActiveLife );
        life->SetStatus( eActive );
        life->onActive();
    }
    
    // update the life
    for( i = 0; i < lifeCnt; i++ )
    {
        life = (SpriteLife*)m_lives->objectAtIndex( i );
        life->onUpdate( elapsed );
    }
    
    // process the pending life ( remove || add new one )
    for( i = 0; i < m_pendingLives->count(); i++ )
    {
        life = (SpriteLife*)m_pendingLives->objectAtIndex( i );
        
        int status = life->GetStatus();
        int x, y;
        life->GetPosition( x, y );
        gridInfo* grid = getGridInfo( x, y );
        
        if( status == eAppear )
        {
            grid->_life = life;
            life->SetContainer( this );
            m_lives->addObject( life );
            life->SetDisplayLayer( m_displayLayer );
            life->onAdd();
            
            life->SetStatus( eAlive );
        }
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
    
}


void GridSpace::RemoveAllLives()
{
    //TODO 
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
            break;
        }
    }
    
    return idx;
}

