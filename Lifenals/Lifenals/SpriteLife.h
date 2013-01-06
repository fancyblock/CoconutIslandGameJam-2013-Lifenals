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


class SpriteLife
{
public:
    SpriteLife();
    ~SpriteLife();
    void SetPosition( int x, int y );
    void GetPosition( int& x, int& y );
    void SetContainer( Incubator* container );
    Incubator* GetContainer();
    
protected:
    Incubator* m_container;
    ActionSlot m_actionSlot;
    
    int m_x;
    int m_y;
};


#endif
