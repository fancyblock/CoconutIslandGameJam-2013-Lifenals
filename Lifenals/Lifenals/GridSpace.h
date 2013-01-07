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
#include "Nutrient.h"
#include "Incubator.h"

USING_NS_CC;


// grid info
struct gridInfo
{
    SpriteLife* _life;
    Nutrient* _nutrient;
};


class GridSpace : public Incubator
{
public:
    GridSpace();
    ~GridSpace();
    
    void Create( CCNode* layer );
    virtual bool AddLife( SpriteLife* life, int posX, int posY );
    virtual bool RemoveLife( SpriteLife* life );
    virtual bool RemoveLife( int posX, int posY );
    virtual SpriteLife* GetLife( int posX, int posY );
    virtual void Update( float elapsed );
    virtual void RemoveAllLives();
    virtual void GetRandomBlankNeighbor( SpriteLife* life, int& x, int& y );
    virtual void MoveLife( SpriteLife* life, int x, int y );
    virtual void GetRandomNeighbor( SpriteLife* life, int& x, int& y );
    
protected:
    CCNode* m_displayLayer;
    gridInfo** m_grids;
    
    CCArray* m_lives;
    CCArray* m_pendingLives;
    
    int m_curActiveLife;
    
protected:
    gridInfo* getGridInfo( int x, int y );
    bool removeLife( SpriteLife* life );
    int getCurActiveLife();

};


#endif
