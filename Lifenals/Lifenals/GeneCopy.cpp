//
//  GeneCopy.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#include "GeneCopy.h"
#include "SpriteLife.h"
#include "LifeDisplay.h"
#include "ActionSlot.h"


GeneCopy::GeneCopy()
{
    m_type = eGeneCopy;
}


GeneCopy::~GeneCopy()
{
}


void GeneCopy::Start( SpriteLife* life )
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
    // copy self to that grid 
    else
    {
        SpriteLife* cloneLife = new SpriteLife();
        cloneLife->GetActionSlot()->CloneFrom( life->GetActionSlot() );
        life->GetContainer()->AddLife( cloneLife, x, y );
        
        life->GetLifeDisplay()->Flicker();
        
        CCLog( "[GeneCopy]: Life be copy" );
    }
    
}

