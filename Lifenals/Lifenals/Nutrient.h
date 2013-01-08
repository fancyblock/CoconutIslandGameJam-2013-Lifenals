//
//  Nutrient.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#ifndef Lifenals_Nutrient_h
#define Lifenals_Nutrient_h
#include "cocos2d.h"

USING_NS_CC;

class Incubator;

class Nutrient : public CCObject
{
public:
    static CCSprite* GetCellSprite( int gene );
    static CCSprite* GetBottleSprite( int gene );
    
public:
    Nutrient( int type );
    ~Nutrient();
    virtual void Update( float dt, Incubator* incubator );
    bool IsValid();
    void SetPosition( int x, int y );
    void GetPosition( int& x, int& y );
    void SetDisplayLayer( CCNode* layer );
    
    void onAdd();
    void onRemove();
    
    void Exit();
    
protected:
    int m_x;
    int m_y;
    bool m_valid;
    int m_injectCnt;
    int m_type;
    float m_time;
    
    CCNode* m_displayLayer;
    CCSprite* m_imgGerm;
};


#endif
