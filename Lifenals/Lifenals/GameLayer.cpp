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
    m_incubator->AddLife( life, 2, 2 );     //[HACK]
    
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


void GameLayer::update( float dt )
{    
    //TODO
    
    m_incubator->Update( dt );
}


