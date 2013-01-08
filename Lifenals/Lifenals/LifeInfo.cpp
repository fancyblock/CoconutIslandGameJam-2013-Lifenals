//
//  LifeInfo.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-8.
//
//

#include "LifeInfo.h"
#include "SpriteLife.h"
#include "LifeDisplay.h"
#include "ActionSlot.h"


LifeInfo::LifeInfo()
{
    m_life = NULL;
}


LifeInfo::~LifeInfo()
{
    //TODO
}


void LifeInfo::SetLife( SpriteLife* life )
{
    m_life = life;
    
    if( m_life == NULL )
    {
        if( m_life != NULL )
        {
            m_life->SetSelected( false );
        }
        
        this->removeAllChildrenWithCleanup( true );
        m_life = NULL;
    }
    else
    {
        CCSprite* spr = LifeDisplay::GetLifeSprite( life );
        ActionSlot* slot = life->GetActionSlot();
        
        //TODO 
        
        this->addChild( spr );
        m_life->SetSelected( true );
    }
}



