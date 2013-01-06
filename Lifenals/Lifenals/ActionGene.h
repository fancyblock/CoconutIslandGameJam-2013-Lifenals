//
//  ActionGene.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-6.
//
//

#ifndef Lifenals_ActionGene_h
#define Lifenals_ActionGene_h

class SpriteLife;

class ActionGene
{
public:
    virtual void Start( SpriteLife* life ) = 0;
    virtual int GetType() = 0;
};


#endif
