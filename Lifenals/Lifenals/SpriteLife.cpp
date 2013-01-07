//
//  SpriteLife.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#include "SpriteLife.h"
#include "cocos2d.h"
#include "ActionGene.h"
#include "Common.h"
#include "GlobalWork.h"
#include "GeneManager.h"


USING_NS_CC;


SpriteLife::SpriteLife()
{
    m_container = NULL;
    m_lifeDisplay = NULL;
    
    m_x = 0;
    m_y = 0;
    m_status = eNone;
    m_curActionIdx = -1;
}


SpriteLife::~SpriteLife()
{
    //TODO
}


void SpriteLife::SetPosition( int x, int y )
{
    m_x = x;
    m_y = y;
}


void SpriteLife::GetPosition( int& x, int& y )
{
    x = m_x;
    y = m_y;
}


void SpriteLife::SetContainer( Incubator* container )
{
    m_container = container;
}


Incubator* SpriteLife::GetContainer()
{
    return m_container;
}


void SpriteLife::onAdd()
{
    // add to parent and then play some appear animation
    this->initDisplay();
    
    m_lifeDisplay->Appear();
    
    //TODO 
}


void SpriteLife::onRemove()
{
    // play some animation and then remove from parent
    m_lifeDisplay->Disappear();
    
    //TODO 
}


void SpriteLife::onMove()
{
    m_lifeDisplay->MoveTo( m_x, m_y );
}


void SpriteLife::onUpdate( float dt )
{
    //TODO 
}


void SpriteLife::onActive()
{
    CCLog( "[SpriteLife]: onActive" );
    
    int geneCnt = m_actionSlot.GetGeneCount();
    
    if( geneCnt == 0 )
    {
        // invoke the next life 
        m_lifeDisplay->Flicker();
    }
    else
    {
        m_curActionIdx++;
        m_curActionIdx %= geneCnt;
        
        int gene = m_actionSlot.GetActionGene( m_curActionIdx );
        GeneManager::sharedInstance()->GetGene( gene )->Start( this );
    }
}


void SpriteLife::onSlotChanged()
{
    //TODO 
}


int SpriteLife::GetStatus()
{
    return m_status;
}


void SpriteLife::SetStatus( int status )
{
    m_status = status;
}


void SpriteLife::SetDisplayLayer( CCNode* layer )
{
    m_displayLayer = layer;
}


ActionSlot* SpriteLife::GetActionSlot()
{
    return &m_actionSlot;
}


LifeDisplay* SpriteLife::GetLifeDisplay()
{
    return m_lifeDisplay;
}


void SpriteLife::initDisplay()
{
    // create the life display and add to the display layer
    m_lifeDisplay = new LifeDisplay();
    m_lifeDisplay->Create( this );
    
    CCSprite* spr = m_lifeDisplay->GetDisplay();
    spr->setPosition( POS( m_x*SPRITE_WID, m_y*SPRITE_HEI));
    m_displayLayer->addChild( spr );
}





