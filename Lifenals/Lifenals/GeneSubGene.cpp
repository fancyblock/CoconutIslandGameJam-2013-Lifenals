//
//  GeneSubGene.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-8.
//
//

#include "GeneSubGene.h"
#include "Incubator.h"
#include "SpriteLife.h"


GeneSubGene::GeneSubGene()
{
    m_type = eGeneSubGene;
}


void GeneSubGene::Start( SpriteLife* life )
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
        
        otherLife->GetActionSlot()->PopBackGene();
        
        life->GetLifeDisplay()->Flicker();                              //[TEMP]
    }
}


