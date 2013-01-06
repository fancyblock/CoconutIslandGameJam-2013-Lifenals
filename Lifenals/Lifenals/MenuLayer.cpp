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
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    // add background 
    //TODO 
    
    // create menu
    CCMenuItemFont* btnStartGame = CCMenuItemFont::create( "Start Game", this, menu_selector(MenuLayer::onStartGame));
    btnStartGame->setPosition( POS(SCREEN_WIDTH/2, 320) );
    CCMenuItemFont* btnHelp = CCMenuItemFont::create( "Help", this, menu_selector(MenuLayer::onHelp));
    btnHelp->setPosition( POS(SCREEN_WIDTH/2, 240) );
    CCMenuItemFont* btnSettings = CCMenuItemFont::create( "Settings", this, menu_selector(MenuLayer::onSettings));
    btnSettings->setPosition( POS(SCREEN_WIDTH/2, 160) );
    CCMenuItemFont* btnAbout = CCMenuItemFont::create( "About", this, menu_selector(MenuLayer::onAbout));
    btnAbout->setPosition( POS(SCREEN_WIDTH/2, 80) );
    
    CCMenu* menu = CCMenu::create( btnStartGame, btnHelp, btnSettings, btnAbout, NULL );

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

void MenuLayer::onSettings( CCObject* sender )
{
    //TODO
    
    CCLog( "[Settings]" );
}

void MenuLayer::onAbout( CCObject* sender )
{
    
    //TODO
    
    CCLog( "[About]" );
}
