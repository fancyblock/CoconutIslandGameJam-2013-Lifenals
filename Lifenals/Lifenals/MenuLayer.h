//
//  MenuLayer.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#ifndef Lifenals_MenuLayer_h
#define Lifenals_MenuLayer_h

#include "cocos2d.h"


// menu layer
class MenuLayer : public cocos2d::CCLayerColor
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    void onStartGame( CCObject* sender );
    void onHelp( CCObject* sender );
    void onAbout( CCObject* sender );
    
    CREATE_FUNC( MenuLayer );
    
protected:
    //TODO
};

#endif
