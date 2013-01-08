//
//  LifeDisplay.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#include "LifeDisplay.h"
#include "SpriteLife.h"
#include "GameSettings.h"
#include "Common.h"
#include "GlobalWork.h"
#include "ActionGene.h"


static char* g_lifePic[] = { "germ_001.png", "germ_002.png", "germ_003.png",
                            "germ_004.png", "germ_005.png", "germ_006.png",
                            "germ_007.png", "germ_008.png", "germ_009.png",
                            "germ_010.png" };


LifeDisplay::LifeDisplay()
{
    m_host = NULL;
    m_display = NULL;
}


LifeDisplay::~LifeDisplay()
{
    delete m_display;
}


void LifeDisplay::Create( SpriteLife* life )
{
    m_host = life;
    
    char* frameName = getLifeLookFileName( life );
    m_display = CCSprite::createWithSpriteFrameName( frameName );
    m_display->setPosition( ccp( 0, 0 ) );
    m_display->setOpacity( 0 );
}


CCSprite* LifeDisplay::GetDisplay()
{
    return m_display;
}


void LifeDisplay::Flicker()
{
    m_display->runAction( CCSequence::create(
                            CCScaleTo::create( 0.7f, 1.0f, 1.2f ),
                            CCScaleTo::create( 0.7f, 1.0f, 1.0f ),
                            CCDelayTime::create( 0.5f ),
                            CCCallFunc::create( this, callfunc_selector(LifeDisplay::onDeactive) )
                                             , NULL ) );
}


void LifeDisplay::Appear()
{
    m_display->runAction( CCFadeIn::create( 1.0f ) );
}


void LifeDisplay::Disappear()
{
    //TODO 
}


void LifeDisplay::MoveTo( int x, int y )
{
    m_display->runAction( CCSequence::create(
                            CCJumpTo::create( 1.0f, POS( x*SPRITE_WID, y*SPRITE_HEI), 1.0f, 1 ),
                            CCDelayTime::create( 0.5f ),
                            CCCallFunc::create( this, callfunc_selector(LifeDisplay::onDeactive) )
                                             , NULL ) );
}


void LifeDisplay::onDeactive()
{
    m_host->SetStatus( eAlive );
}


char* LifeDisplay::getLifeLookFileName( SpriteLife* life )
{
    char* fileName = "germ_000.png";
    
    ActionSlot* slot = life->GetActionSlot();
    if( slot->GetGeneCount() > 0 )
    {
        int gene = slot->GetActionGene( 0 );
        fileName = g_lifePic[gene];
    }
    
    return fileName;
}


CCSprite* LifeDisplay::GetLifeSprite( SpriteLife* life )
{
    char* fileName = getLifeLookFileName( life );
    
    return CCSprite::createWithSpriteFrameName( fileName );
}



