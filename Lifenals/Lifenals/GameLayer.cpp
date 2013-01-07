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
#include <cstdio>

using namespace std;

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
    
    // var initial
    m_selectedGerm = -1;
    m_sprGermInfo = NULL;
    //TODO
    
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
    btnNormal = CCSprite::createWithSpriteFrameName( "button_battle_1.png" );
    btnPush = CCSprite::createWithSpriteFrameName( "button_battle_2.png" );
    CCMenuItemSprite* btnBattle = CCMenuItemSprite::create( btnNormal, btnPush, this, menu_selector(GameLayer::onBattle) );
    btnBattle->setScaleX( SGLOBAL.GetSizeFactorX() );
    btnBattle->setScaleY( SGLOBAL.GetSizeFactorY() );
    btnBattle->setPosition( POS( 112, 107 ) );
    
    
    m_menu = CCMenu::create( btnGerm, btnMedium, btnRecord, btnSetting, btnBattle, NULL );
    m_menu->setPosition( ccp(0,0) );
    this->addChild( m_menu );
    
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
    
    // add initial life into incubator
    SpriteLife* life = new SpriteLife();
    life->GetActionSlot()->AddGene( eGeneCopy );
    m_incubator->AddLife( life, 2, 2 );                 //[TEMP]
    
    this->addChild( m_gameStuffLayer );
    
    EnableTouch( true );
}


void GameLayer::onEnter()
{
    CCLayerColor::onEnter();
    
    CCLog( "[GameLayer]: Enter" );
    
    //TODO
}


void GameLayer::onExit()
{
    CCLog( "[GameLayer]: Exit" );
    
    //TODO
    
    this->unscheduleUpdate();
    
    CCLayerColor::onExit();
}


void GameLayer::onEnterTransitionDidFinish()
{
    CCLayerColor::onEnterTransitionDidFinish();
    
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
    EnableTouch( false );
    
    // add medium into grid
    if( m_uiSelectMedium == NULL )
    {
        m_uiSelectMedium = new SelectMedium();
        m_uiSelectMedium->init();
        
        m_uiSelectMedium->SetMainLayer( this );
    }
    
    this->getParent()->addChild( m_uiSelectMedium );
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


void GameLayer::EnableTouch( bool enable )
{
    this->setTouchEnabled( enable );
    this->m_menu->setTouchEnabled( enable );
}


void GameLayer::onSelectGermDone()
{
    EnableTouch( true );
    this->getParent()->removeChild( m_uiSelectMedium, false );
    
    m_selectedGerm = m_uiSelectMedium->GetSelectedGene();
    
    refreshUI();
}


void GameLayer::update( float dt )
{    
    //TODO
    
    m_incubator->Update( dt );
}


void GameLayer::refreshUI()
{
    // selected germ
    if( m_sprGermInfo != NULL )
    {
        this->removeChild( m_sprGermInfo, true );
        m_sprGermInfo = NULL;
    }
    if( m_selectedGerm >= 0 )
    {
        m_sprGermInfo = CCSprite::create();
        
        char buff[20];
        if( (m_selectedGerm+1) != 10 )
            sprintf( buff, "M0%d_1.png", m_selectedGerm+1 );
        else
            sprintf( buff, "M%d_1.png", m_selectedGerm+1 );
        CCSprite* imgLogo = CCSprite::createWithSpriteFrameName( buff );
        
        m_sprGermInfo->addChild( imgLogo );
        CCLabelTTF* font = CCLabelTTF::create( g_geneName[m_selectedGerm], "arial.ttf", 14 );
        font->setPosition( POS( 0, -70 ) );
        m_sprGermInfo->addChild( font );
        
        m_sprGermInfo->setPosition( POS( 930, 530 ) );
        m_sprGermInfo->setScaleX( SGLOBAL.GetSizeFactorX() );
        m_sprGermInfo->setScaleY( SGLOBAL.GetSizeFactorY() );
        this->addChild( m_sprGermInfo );
    }
    
    //TODO 
}


void GameLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
    CCTouch* pTouch = (CCTouch*)pTouches->anyObject();
    CCPoint pt = pTouch->getLocationInView();
    CCLog( "[Pos]: %.2f, %.2f", pt.x, pt.y );
    
    //TODO
}


void GameLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
    //TODO
}


void GameLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
    //TODO
}


void GameLayer::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent)
{
    //TODO 
}

