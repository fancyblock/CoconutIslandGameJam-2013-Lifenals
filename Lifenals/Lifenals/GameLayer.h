//
//  GameLayer.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#ifndef Lifenals_GameLayer_h
#define Lifenals_GameLayer_h

#include "cocos2d.h"
#include "GridSpace.h"
#include "SpriteLife.h"

USING_NS_CC;


class GameLayer : public CCLayerColor
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC( GameLayer );
    
    virtual void onEnter();
    virtual void onExit();
    virtual void onEnterTransitionDidFinish();
    void update( float dt );
    
    void onGerms( CCObject* sender );
    void onMedium( CCObject* sender );
    void onRecord( CCObject* sender );
    void onSetting( CCObject* sender );
    void onBattle( CCObject* sender );
    
protected:
    GridSpace* m_incubator;
    CCSprite* m_gameStuffLayer;
    
protected:
    void initGame();
};

#endif
