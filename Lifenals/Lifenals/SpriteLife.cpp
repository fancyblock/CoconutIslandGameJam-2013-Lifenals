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

