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
    //TODO
    
    // create menu
    //TODO
    
    initGame();
    
    return true;
}


void TestLayer::initGame()
{
    m_incubator = new GridSpace();
    m_incubator->Create();
    
    //TODO
    
}

