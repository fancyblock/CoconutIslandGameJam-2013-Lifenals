//
//  GridSpace.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#ifndef Lifenals_GridSpace_h
#define Lifenals_GridSpace_h

#include "GameSettings.h"
#include "SpriteLife.h"


class GridSpace
{
public:
    GridSpace();
    ~GridSpace();
    
    void Create();
    bool AddLife( SpriteLife* life, int posX, int posY );
    
protected:
    //TODO 
};


#endif
