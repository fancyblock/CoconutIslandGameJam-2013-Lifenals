//
//  GridSpace.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#ifndef Lifenals_GridSpace_h
#define Lifenals_GridSpace_h

#include "cocos2d.h"
#include "GameSettings.h"
#include "SpriteLife.h"

USING_NS_CC;

class GridSpace
{
public:
    GridSpace();
    ~GridSpace();
    
    void Create();
    bool AddLife( SpriteLife* life, int posX, int posY );
    void Update( float elapsed );
    void SetDisplayLayer( CCNode* layer );
    
protected:
    CCNode* m_displayLayer;
};


#endif
