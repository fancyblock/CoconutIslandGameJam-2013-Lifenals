//
//  SelectMedium.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#include "SelectMedium.h"
#include "GlobalWork.h"
#include "GameLayer.h"
#include "Common.h"
#include "Nutrient.h"


bool SelectMedium::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayerColor::initWithColor( ccc4(175,134,104,155) ) )
    {
        return false;
    }
    
    CCMenu* menu = CCMenu::create();
    
    for( int i(0); i < 10; i++ )
    {
        CCSprite* spr = Nutrient::GetBottleSprite(i);
        CCSprite* spr2 = Nutrient::GetBottleSprite(i);
        spr2->setColor( ccc3(100, 200, 50) );
        
        CCMenuItemSprite* btnSpr = CCMenuItemSprite::create(spr, spr2, this, menu_selector(SelectMedium::onSelect));
        btnSpr->setScaleX(SGLOBAL.GetSizeFactorX());
        btnSpr->setScaleY(SGLOBAL.GetSizeFactorY());
        btnSpr->setPosition(POS(332+i%5*130,260+(i)/5*130));
        
        m_btnSet[i] = btnSpr;
        menu->addChild( btnSpr );
    }
    
    menu->setPosition(0, 0);
    this->addChild( menu );
    
    return true;
}


void SelectMedium::SetMainLayer( GameLayer* layer )
{
    m_mainLayer = layer;
}


int SelectMedium::GetSelectedGene()
{
    return m_selectedGene;
}


void SelectMedium::onSelect( CCObject* sender )
{
    for( int i(0); i < 10; i++ )
    {
        if( sender == m_btnSet[i] )
        {
            m_selectedGene = i;
            
            m_mainLayer->onSelectGermDone();
        }
    }
}


