//
//  GeneMove.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#ifndef Lifenals_GeneMove_h
#define Lifenals_GeneMove_h
#include "BasicGene.h"


class GeneMove : public BasicGene
{
public:
    GeneMove();
    ~GeneMove();
    
    virtual void Start( SpriteLife* life );
    
protected:
    //TODO
};


#endif
