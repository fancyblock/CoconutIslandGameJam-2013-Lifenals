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
    
    grid->_life = life;
    life->SetContainer( this );
    life->SetPosition( posX, posY );
    
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
        //TODO 
    }
    
    return false;
}


