//
//  TestLayer.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#ifndef Lifenals_TestLayer_h
#define Lifenals_TestLayer_h

#include "cocos2d.h"
#include "GridSpace.h"
#include "SpriteLife.h"

USING_NS_CC;


class TestLayer : public CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC( TestLayer );
    
    virtual void onEnter();
    virtual void onExit();
    virtual void onEnterTransitionDidFinish();
    void update( float elapsed );
    
protected:
    GridSpace* m_incubator;
    CCSprite* m_gameStuffLayer;
    
protected:
    void initGame();
};



#endif
