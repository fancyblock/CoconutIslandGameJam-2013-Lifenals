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
#include "Nutrient.h"
#include "GlobalWork.h"
#include "ActionGene.h"


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
    if( life != m_life || life == NULL )
    {
        if( m_life != NULL )
        {
            m_life->SetSelected( false );
        }
            
        this->removeAllChildrenWithCleanup( true );
        m_life = NULL;
    }
    
    if( life != NULL )
    {
        CCSprite* spr = LifeDisplay::GetLifeSprite( life );
        ActionSlot* slot = life->GetActionSlot();
        
        for( int i(0); i < slot->GetGeneCount(); i++ )
        {
            int gene = slot->GetActionGene( i );
            
            CCSprite* spr = Nutrient::GetFlagSprite( gene );
            spr->setScaleX( SGLOBAL.GetSizeFactorX() );
            spr->setScaleY( SGLOBAL.GetSizeFactorY() );
            
            spr->setPosition(POS(-40+i*20,-62));
            this->addChild( spr );
            
            spr = Nutrient::GetFlagSprite( gene );
            spr->setScaleX( SGLOBAL.GetSizeFactorX() );
            spr->setScaleY( SGLOBAL.GetSizeFactorY() );
            
            spr->setPosition( POS(65, 50-i*25) );
            this->addChild( spr );
            
            CCLabelTTF* font = CCLabelTTF::create( g_geneName[gene], "arial.ttf", 12 );
            font->setAnchorPoint( ccp( 0, 0 ) );
            font->setPosition( POS( 80, 37-i*25) );
            font->setColor(ccc3(200, 100, 50));
            this->addChild( font );
            
            m_life = life;
        }
        
        this->addChild( spr );
        m_life->SetSelected( true );
    }
}




