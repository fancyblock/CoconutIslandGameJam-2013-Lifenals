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
#include "SelectMedium.h"
#include "LifeInfo.h"

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
    
    void EnableTouch( bool enable );
    
    void onSelectGermDone();
    
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
    
protected:
    GridSpace* m_incubator;
    CCSprite* m_gameStuffLayer;
    
    SelectMedium* m_uiSelectMedium;
    CCMenu* m_menu;
    LifeInfo* m_uiLifeInfo;
    
    int m_selectedGerm;
    CCSprite* m_sprGermInfo;
    int m_curGridX;
    int m_curGridY;
    CCSprite* m_germPlaceholder;
    
protected:
    void initGame();
    void refreshUI();
    void ScreenToGrid( CCPoint& pt, int& x, int& y );
    void GridToScreen( int x, int y, int& outX, int& outY );
};

#endif
