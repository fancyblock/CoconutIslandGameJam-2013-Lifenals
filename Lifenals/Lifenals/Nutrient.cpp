//
//  Nutrient.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#include "Nutrient.h"
#include "GlobalWork.h"
#include "Common.h"
#include "GameSettings.h"
#include "Incubator.h"
#include "SpriteLife.h"
#include "ActionSlot.h"
#include<cstdio>

using namespace std;


CCSprite* Nutrient::GetCellSprite( int gene )
{
    char buff[20];
    if( (gene+1) < 10 )
    {
        sprintf( buff, "M0%d_2.png", gene+1 );
    }
    else
    {
        sprintf( buff, "M%d_2.png", gene+1 );
    }
    
    return CCSprite::createWithSpriteFrameName( buff );
}


CCSprite* Nutrient::GetBottleSprite( int gene )
{
    char buff[20];
    if( (gene+1) < 10 )
    {
        sprintf( buff, "M0%d_1.png", gene+1 );
    }
    else
    {
        sprintf( buff, "M%d_1.png", gene+1 );
    }
    
    return CCSprite::createWithSpriteFrameName( buff );
}


CCSprite* Nutrient::GetFlagSprite( int gene )
{
    char buff[20];
    if( (gene+1) < 10 )
    {
        sprintf( buff, "M0%d_3.png", gene+1 );
    }
    else
    {
        sprintf( buff, "M%d_3.png", gene+1 );
    }
    
    return CCSprite::createWithSpriteFrameName( buff );
}


Nutrient::Nutrient( int type )
{
    m_valid = true;
    m_imgGerm = NULL;
    
    m_type = type;
    m_injectCnt = 0;
}


Nutrient::~Nutrient()
{
}


void Nutrient::Update( float dt, Incubator* incubator )
{
    m_time += dt;
    
    if( m_time > 2.0f && m_injectCnt == 0 )     //[TEMP]
    {
        SpriteLife* life = incubator->GetLife( m_x, m_y );
        if( life != NULL && life->GetStatus() == eAlive )
        {
            ActionSlot* slot = life->GetActionSlot();
            
            if( slot->GetGeneCount() < MAX_SLOT_CAPACITY )
            {
                //inject a gene
                slot->AddGene( m_type );
                life->onSlotChanged();
                
                m_injectCnt++;
                
                // exit
                m_valid = false;
            }
        }
        
        if( m_time > 7.0f )
        {
            // exit 
            m_valid = false;
        }
    }
}


bool Nutrient::IsValid()
{
    return m_valid;
}


void Nutrient::SetPosition( int x, int y )
{
    m_x = x;
    m_y = y;
}


void Nutrient::GetPosition( int& x, int& y )
{
    x = m_x;
    y = m_y;
}


void Nutrient::SetDisplayLayer( CCNode* layer )
{
    m_displayLayer = layer;
}


void Nutrient::onAdd()
{
    m_imgGerm = GetCellSprite( m_type );
    m_imgGerm->setPosition( POS(m_x*SPRITE_WID, m_y*SPRITE_HEI));
    m_imgGerm->setOpacity(150);
    
    m_displayLayer->addChild( m_imgGerm );
    m_imgGerm->runAction( CCFadeIn::create(0.6f) );
    m_time = 0.0f;
    m_injectCnt = 0;
}


void Nutrient::onRemove()
{
    m_imgGerm->runAction( CCSequence::create(
                                             CCFadeOut::create( 1.0f ),
                                             CCCallFunc::create(this, callfunc_selector(Nutrient::Exit)),
                                             NULL
                         ));
}


void Nutrient::Exit()
{
    m_displayLayer->removeChild( m_imgGerm, true );
}



