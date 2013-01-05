//
//  TestLayer.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#include "TestLayer.h"
#include "GlobalWork.h"
#include "Common.h"


CCScene* TestLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    TestLayer *layer = TestLayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool TestLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    // add background
    CCSprite* sprBg = CCSprite::createWithSpriteFrameName( "ingameBg.png" );
    sprBg->setPosition( POS( SCREEN_WIDTH/2, SCREEN_HEIGHT/2 ) );
    sprBg->setScaleX( SGLOBAL.GetSizeFactorX() );
    sprBg->setScaleY( SGLOBAL.GetSizeFactorY() );
    this->addChild( sprBg );
    
    // create menu
    //TODO
    
    initGame();
    
    this->scheduleUpdate();
    
    return true;
}


void TestLayer::initGame()
{
    // create && initial the incubator
    m_incubator = new GridSpace();
    m_incubator->Create();
    
    // add a life into incubator
    SpriteLife* life = new SpriteLife();
    m_incubator->AddLife( life, 2, 2 );     //[HACK]
    
    // setup display stuff
    m_gameStuffLayer = CCSprite::create();
    m_incubator->SetDisplayLayer( m_gameStuffLayer );
    
    this->addChild( m_gameStuffLayer );
}


void TestLayer::onEnter()
{
    CCLog( "[TestLayer]: Enter" );
    
    //TODO 
}


void TestLayer::onExit()
{
    CCLog( "[TestLayer]: Exit" );
    
    //TODO
}


void TestLayer::onEnterTransitionDidFinish()
{
    CCLog( "[TestLayer]: EnterTransitionDidFinish" );
    
    //TODO 
}


void TestLayer::update( float elapsed )
{
    //TODO 
    
    m_incubator->Update( elapsed );
}

