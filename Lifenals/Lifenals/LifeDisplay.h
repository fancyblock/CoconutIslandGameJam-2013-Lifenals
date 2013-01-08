//
//  LifeDisplay.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#ifndef Lifenals_LifeDisplay_h
#define Lifenals_LifeDisplay_h

#include "cocos2d.h"

USING_NS_CC;

class SpriteLife;

class LifeDisplay : public CCObject
{
public:
    static CCSprite* GetLifeSprite( SpriteLife* life );
    
public:
    LifeDisplay();
    ~LifeDisplay();
    void Create( SpriteLife* life );
    CCSprite* GetDisplay();
    
    void Flicker();                     // play an animation when this life's turn but it doesn't have any action
    void Appear();
    void Disappear();
    void MoveTo( int x, int y );
    
protected:
    SpriteLife* m_host;
    CCSprite* m_display;
    
protected:
    static char* getLifeLookFileName( SpriteLife* life );
    
    void onDeactive();
};


#endif
