//
//  GeneDisable.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-8.
//
//

#include "GeneDisable.h"
#include "Incubator.h"
#include "SpriteLife.h"


GeneDisable::GeneDisable()
{
    m_type = eGeneDisable;
}


void GeneDisable::Start( SpriteLife* life )
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
    else
    {
        SpriteLife* otherLife = life->GetContainer()->GetLife( x, y );
        
        otherLife->GetActionSlot()->CleanAllGene();
        
        life->GetLifeDisplay()->Flicker();                              //[TEMP]
    }
}

