//
//  MenuLayer.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#include "MenuLayer.h"
#include "GlobalWork.h"
#include "Common.h"
#include "GameLayer.h"

USING_NS_CC;


CCScene* MenuLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MenuLayer *layer = MenuLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool MenuLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayerColor::initWithColor( ccc4(75,134,104,255) ) )
    {
        return false;
    }
    
    // add background 
    //TODO 
    
    // create menu
    CCSprite* btnNormal = NULL;
    CCSprite* btnPush = NULL;
    
    btnNormal = CCSprite::createWithSpriteFrameName( "button_start_1.png" );
    btnPush = CCSprite::createWithSpriteFrameName( "button_start_2.png" );
    CCMenuItemSprite* btnStart = CCMenuItemSprite::create( btnNormal, btnPush, this, menu_selector(MenuLayer::onStartGame) );
    btnStart->setPosition( POS(SCREEN_WIDTH/2, SCREEN_HEIGHT/3) );
    btnStart->setScaleX( SGLOBAL.GetSizeFactorX() );
    btnStart->setScaleY( SGLOBAL.GetSizeFactorY() );
    
    CCMenu* menu = CCMenu::create( btnStart, NULL );
    
    menu->setPosition( 0, 0 );
    this->addChild( menu, 0 );
    
    return true;
}


void MenuLayer::onStartGame( CCObject* sender )
{
    CCDirector::sharedDirector()->replaceScene( CCTransitionFade::create( SCENE_TRANS_TIME, GameLayer::scene() ) );
}


void MenuLayer::onHelp( CCObject* sender )
{
    //TODO
    
    CCLog( "[Help]" );
}


void MenuLayer::onAbout( CCObject* sender )
{
    
    //TODO
    
    CCLog( "[About]" );
}
