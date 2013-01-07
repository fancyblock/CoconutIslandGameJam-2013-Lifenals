//
//  GameLayer.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#include "GameLayer.h"
#include "GlobalWork.h"
#include "Common.h"
#include "ActionSlot.h"
#include "ActionGene.h"

#define GRID_SPACE_X    276
#define GRID_SPACE_Y    105


CCScene* GameLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameLayer *layer = GameLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool GameLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayerColor::initWithColor( ccc4(75,134,104,255) ) )
    {
        return false;
    }
    
    CCSpriteBatchNode* batchNode = CCSpriteBatchNode::create( "rawData.png" );
    this->addChild( batchNode );
    
    CCSprite* spr = NULL;
    
    // add background
    spr = CCSprite::createWithSpriteFrameName( "area_01.png" );
    spr->setPosition( POS( 487, SCREEN_HEIGHT/2 ) );
    spr->setScaleX( SGLOBAL.GetSizeFactorX() );
    spr->setScaleY( SGLOBAL.GetSizeFactorY() );
    batchNode->addChild( spr );
    //
    spr = CCSprite::createWithSpriteFrameName( "area_02.png" );
    spr->setPosition( POS( 942, 101 ) );
    spr->setScaleX( SGLOBAL.GetSizeFactorX() );
    spr->setScaleY( SGLOBAL.GetSizeFactorY() );
    batchNode->addChild( spr );
    //
    spr = CCSprite::createWithSpriteFrameName( "frame_ifo.png" );
    spr->setPosition( POS( 944, 320 ) );
    spr->setScaleX( SGLOBAL.GetSizeFactorX() );
    spr->setScaleY( SGLOBAL.GetSizeFactorY() );
    batchNode->addChild( spr );
    //
    
    // create menu
    CCSprite* btnNormal = NULL;
    CCSprite* btnPush = NULL;
    //
    btnNormal = CCSprite::createWithSpriteFrameName( "button_germ_1.png" );
    btnPush = CCSprite::createWithSpriteFrameName( "button_germ_2.png" );
    CCMenuItemSprite* btnGerm = CCMenuItemSprite::create( btnNormal, btnPush, this, menu_selector(GameLayer::onGerms) );
    btnGerm->setScaleX( SGLOBAL.GetSizeFactorX() );
    btnGerm->setScaleY( SGLOBAL.GetSizeFactorY() );
    btnGerm->setPosition( POS( 112, 532 ) );
    //
    btnNormal = CCSprite::createWithSpriteFrameName( "button_medium_1.png" );
    btnPush = CCSprite::createWithSpriteFrameName( "button_medium_2.png" );
    CCMenuItemSprite* btnMedium = CCMenuItemSprite::create( btnNormal, btnPush, this, menu_selector(GameLayer::onMedium) );
    btnMedium->setScaleX( SGLOBAL.GetSizeFactorX() );
    btnMedium->setScaleY( SGLOBAL.GetSizeFactorY() );
    btnMedium->setPosition( POS( 112, 447 ) );
    //
    btnNormal = CCSprite::createWithSpriteFrameName( "button_record_1.png" );
    btnPush = CCSprite::createWithSpriteFrameName( "button_record_2.png" );
    CCMenuItemSprite* btnRecord = CCMenuItemSprite::create( btnNormal, btnPush, this, menu_selector(GameLayer::onRecord) );
    btnRecord->setScaleX( SGLOBAL.GetSizeFactorX() );
    btnRecord->setScaleY( SGLOBAL.GetSizeFactorY() );
    btnRecord->setPosition( POS( 112, 362 ) );
    //
    btnNormal = CCSprite::createWithSpriteFrameName( "button_setting_1.png" );
    btnPush = CCSprite::createWithSpriteFrameName( "button_setting_2.png" );
    CCMenuItemSprite* btnSetting = CCMenuItemSprite::create( btnNormal, btnPush, this, menu_selector(GameLayer::onSetting) );
    btnSetting->setScaleX( SGLOBAL.GetSizeFactorX() );
    btnSetting->setScaleY( SGLOBAL.GetSizeFactorY() );
    btnSetting->setPosition( POS( 112, 277 ) );
    //
    btnNormal = CCSprite::createWithSpriteFrameName( "button_setting_1.png" );
    btnPush = CCSprite::createWithSpriteFrameName( "button_setting_2.png" );
    CCMenuItemSprite* btnBattle = CCMenuItemSprite::create( btnNormal, btnPush, this, menu_selector(GameLayer::onBattle) );
    btnBattle->setScaleX( SGLOBAL.GetSizeFactorX() );
    btnBattle->setScaleY( SGLOBAL.GetSizeFactorY() );
    btnBattle->setPosition( POS( 112, 107 ) );
    
    
    CCMenu* menu = CCMenu::create( btnGerm, btnMedium, btnRecord, btnSetting, btnBattle, NULL );
    menu->setPosition( ccp(0,0) );
    this->addChild( menu );
    
    
    initGame();
    
    return true;
}


void GameLayer::initGame()
{
    // setup display stuff
    m_gameStuffLayer = CCSprite::create();
    m_gameStuffLayer->setPosition( POS( GRID_SPACE_X, GRID_SPACE_Y ) );
    
    // create && initial the incubator
    m_incubator = new GridSpace();
    m_incubator->Create( m_gameStuffLayer );
    
    // add a life into incubator
    SpriteLife* life = new SpriteLife();
    life->GetActionSlot()->AddGene( eGeneCopy );        //[HACK]
    m_incubator->AddLife( life, 2, 2 );                 //[HACK]
    
    this->addChild( m_gameStuffLayer );
}


void GameLayer::onEnter()
{
    CCLayer::onEnter();
    
    CCLog( "[GameLayer]: Enter" );
    
    //TODO
}


void GameLayer::onExit()
{
    CCLog( "[GameLayer]: Exit" );
    
    //TODO
    
    this->unscheduleUpdate();
    
    CCLayer::onExit();
}


void GameLayer::onEnterTransitionDidFinish()
{
    CCLayer::onEnterTransitionDidFinish();
    
    CCLog( "[GameLayer]: EnterTransitionDidFinish" );
    
    this->scheduleUpdate();
    
    //TODO
}


void GameLayer::onGerms( CCObject* sender )
{
    //TODO
}


void GameLayer::onMedium( CCObject* sender )
{
    //TODO
}


void GameLayer::onRecord( CCObject* sender )
{
    //TODO
}


void GameLayer::onSetting( CCObject* sender )
{
    //TODO
}


void GameLayer::onBattle( CCObject* sender )
{
    //TODO 
}


void GameLayer::update( float dt )
{    
    //TODO
    
    m_incubator->Update( dt );
}


