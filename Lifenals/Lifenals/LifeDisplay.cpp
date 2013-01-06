//
//  LifeDisplay.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#include "LifeDisplay.h"
#include "SpriteLife.h"


LifeDisplay::LifeDisplay()
{
    m_host = NULL;
    m_display = NULL;
}


LifeDisplay::~LifeDisplay()
{
    //TODO
}


void LifeDisplay::Create( SpriteLife* life )
{
    m_host = life;
    
    char* frameName = getLifeLookFileName();
    m_display = CCSprite::createWithSpriteFrameName( frameName );
    m_display->setPosition( ccp( 0, 0 ) );
}


CCSprite* LifeDisplay::GetDisplay()
{
    return m_display;
}


void LifeDisplay::Flicker()
{
    m_display->runAction( CCSequence::create( CCScaleTo::create( 0.7f, 1.0f, 1.2f ),
                            CCScaleTo::create( 0.7f, 1.0f, 1.0f ),
                            CCDelayTime::create( 0.5f ),
                            CCCallFunc::create( this, callfunc_selector(LifeDisplay::onDeactive) ), NULL ) );
}


char* LifeDisplay::getLifeLookFileName()
{
    char* fileName = "germ_000.png";
    
    ActionSlot* slot = m_host->GetActionSlot();
    if( slot->GetGeneCount() > 0 )
    {
        ActionGene* gene = slot->GetActionGene( 0 );
        
        //TODO 
    }
    
    return fileName;
}


void LifeDisplay::onDeactive()
{
    m_host->SetStatus( eAlive );
}


