//
//  SpriteLife.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#ifndef Lifenals_SpriteLife_h
#define Lifenals_SpriteLife_h

#include "ActionSlot.h"
#include "Incubator.h"
#include "cocos2d.h"
#include "LifeDisplay.h"

USING_NS_CC;

enum
{
    eNone = 0,
    eAlive,
    eDead,
    eAppear,
    eDisappear,
    eActive
};


class SpriteLife : public CCObject
{
public:
    SpriteLife();
    ~SpriteLife();
    void SetPosition( int x, int y );
    void GetPosition( int& x, int& y );
    void SetContainer( Incubator* container );
    Incubator* GetContainer();
    int GetStatus();
    void SetStatus( int status );
    void SetDisplayLayer( CCNode* layer );
    ActionSlot* GetActionSlot();
    
    void onAdd();
    void onRemove();
    void onMove();
    void onUpdate( float dt );
    void onActive();
    
protected:
    Incubator* m_container;
    ActionSlot m_actionSlot;
    
    int m_x;
    int m_y;
    int m_status;
    int m_curActionIdx;
    
    CCNode* m_displayLayer;
    LifeDisplay* m_lifeDisplay;
    
protected:
    void initDisplay();
    
};


#endif
