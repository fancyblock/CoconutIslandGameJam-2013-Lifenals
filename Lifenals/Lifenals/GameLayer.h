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

USING_NS_CC;


class GameLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC( GameLayer );
    
protected:
    //TODO 
};

#endif
