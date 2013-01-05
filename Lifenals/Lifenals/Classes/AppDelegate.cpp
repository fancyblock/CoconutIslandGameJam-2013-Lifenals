//
//  LifenalsAppDelegate.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-4.
//  Copyright CoconutIslandStudio 2013年. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "Common.h"
#include "GlobalWork.h"
#include "MenuLayer.h"
#include <cstdlib>
#include <ctime>

using namespace std;

USING_NS_CC;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // enable High Resource Mode(2x, such as iphone4) and maintains low resource on other devices.
    pDirector->enableRetinaDisplay(true);

    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
    //TODO 
    
    // set the screen parameter
    SGLOBAL.SetScreenSize( pDirector->getWinSize().width, pDirector->getWinSize().height );
    SGLOBAL.SetScreenResolution( pDirector->getWinSizeInPixels().width, pDirector->getWinSizeInPixels().height );
    SGLOBAL.SetLogicSize( SCREEN_WIDTH, SCREEN_HEIGHT );
    
    // initial random seed
    srand( time(0) );
    
    // load resource
    this->loadResource();

    // create a scene. it's an autorelease object
    CCScene* pScene = MenuLayer::scene();

    // run
    pDirector->runWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->pause();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->resume();
    
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}


// load game resource
void AppDelegate::loadResource()
{
    // ingame texture
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile( "rawData.plist", "rawData.png" );
    
    //TODO
}
