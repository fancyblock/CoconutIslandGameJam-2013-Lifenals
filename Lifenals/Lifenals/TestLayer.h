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

USING_NS_CC;


class TestLayer : public CCLayer
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    
    CREATE_FUNC( TestLayer );
    
protected:
    GridSpace* m_incubator;
    
protected:
    void initGame();
};



#endif
