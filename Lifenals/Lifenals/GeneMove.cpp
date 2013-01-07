//
//  GeneMove.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#include "GeneMove.h"
#include "Incubator.h"
#include "SpriteLife.h"


GeneMove::GeneMove()
{
    m_type = eGeneMove;
}


GeneMove::~GeneMove()
{
}


void GeneMove::Start( SpriteLife* life )
{
    BasicGene::Start( life );
    
    int x, y;
    
    Incubator* incubator = life->GetContainer();
    incubator->GetRandomBlankNeighbor( life, x, y );
    
    // no blank neighbor exist
    if( x == -1 )   // && y == -1
    {
        life->GetLifeDisplay()->Flicker();
    }
    // move self to that grid
    else
    {
        life->GetContainer()->MoveLife( life, x, y );
        
        CCLog( "[GeneCopy]: Life move to [%d, %d]", x, y );
    }
    
}

