//
//  LifeInfo.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-8.
//
//

#ifndef Lifenals_LifeInfo_h
#define Lifenals_LifeInfo_h
#include "cocos2d.h"

USING_NS_CC;

class SpriteLife;

class LifeInfo : public CCNode
{
public:
    LifeInfo();
    ~LifeInfo();
    void SetLife( SpriteLife* life );
    
protected:
    SpriteLife* m_life;
};


#endif
