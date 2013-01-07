//
//  BasicGene.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#ifndef Lifenals_BasicGene_h
#define Lifenals_BasicGene_h

#include "cocos2d.h"
#include "ActionGene.h"

USING_NS_CC;


class BasicGene : public CCObject, public ActionGene
{
public:
    BasicGene();
    ~BasicGene();
    
    virtual void Start( SpriteLife* life );
    virtual int GetType();
    
protected:
    int m_type;
    SpriteLife* m_life;
    
};


#endif
