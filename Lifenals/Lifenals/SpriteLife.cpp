//
//  SpriteLife.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#include "SpriteLife.h"
#include "cocos2d.h"

USING_NS_CC;


SpriteLife::SpriteLife()
{
    m_container = NULL;
    
    m_x = 0;
    m_y = 0;
    m_status = eNone;
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
    //TODO
}


void SpriteLife::onRemove()
{
    //TODO
}


void SpriteLife::onMove()
{
    //TODO 
}


void SpriteLife::onUpdate( float dt )
{
    //TODO 
}


void SpriteLife::onActive()
{
    CCLog( "[SpriteLife]: onActive" );
    
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

