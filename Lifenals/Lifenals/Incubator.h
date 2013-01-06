//
//  Incubator.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-6.
//
//

#ifndef Lifenals_Incubator_h
#define Lifenals_Incubator_h

class SpriteLife;


/**
 * @desc    offer some interface for operate the incubator
 */
class Incubator
{
public:
    virtual bool AddLife( SpriteLife* life, int posX, int posY ) = 0;
    virtual bool RemoveLife( SpriteLife* life ) = 0;
    virtual bool RemoveLife( int posX, int posY ) = 0;
    virtual SpriteLife* GetLife( int posX, int posY ) = 0;
    virtual void Update( float elapsed ) = 0;
    virtual void RemoveAllLives() = 0;

};


#endif
