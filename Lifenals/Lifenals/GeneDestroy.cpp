//
//  GeneDestroy.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#include "GeneDestroy.h"
#include "Incubator.h"
#include "SpriteLife.h"



GeneDestroy::GeneDestroy()
{
    m_type = eGeneDestroy;
}


GeneDestroy::~GeneDestroy()
{
}


void GeneDestroy::Start( SpriteLife* life )
{
    BasicGene::Start( life );
    
    int x, y;
    
    Incubator* incubator = life->GetContainer();
    incubator->GetRandomNeighbor( life, x, y );
    
    // no blank neighbor exist
    if( x == -1 )   // && y == -1
    {
        life->GetLifeDisplay()->Flicker();
    }
    // destory the neighbor 
    else
    {
        life->GetContainer()->RemoveLife( x, y );
        life->GetLifeDisplay()->Flicker();              //[TEMP]
        
        CCLog( "[GeneDestroy]: destory the neighbor at (%d,%d)", x, y );
    }
}

