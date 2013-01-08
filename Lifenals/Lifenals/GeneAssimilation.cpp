//
//  GeneAssimilation.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-8.
//
//

#include "GeneAssimilation.h"
#include "Incubator.h"
#include "SpriteLife.h"


GeneAssimilation::GeneAssimilation()
{
    m_type = eGeneAssimilation;
}


GeneAssimilation::~GeneAssimilation()
{
}


void GeneAssimilation::Start( SpriteLife* life )
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
        otherLife->GetActionSlot()->CloneFrom( life->GetActionSlot() );
        
        life->GetLifeDisplay()->Flicker();              //[TEMP]
    }
    
}



