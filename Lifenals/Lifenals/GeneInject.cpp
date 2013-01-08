//
//  GeneInject.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-8.
//
//

#include "GeneInject.h"
#include "Incubator.h"
#include "SpriteLife.h"
#include <cstdlib>

using namespace std;


GeneInject::GeneInject()
{
    m_type = eGeneInject;
}


GeneInject::~GeneInject()
{
}


void GeneInject::Start( SpriteLife* life )
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
        
        otherLife->GetActionSlot()->AddGene( random()%eGeneCount );     //[TEMP]
        
        life->GetLifeDisplay()->Flicker();                              //[TEMP]
    }
}



