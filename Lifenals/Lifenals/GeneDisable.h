//
//  GeneDisable.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-8.
//
//

#ifndef Lifenals_GeneDisable_h
#define Lifenals_GeneDisable_h
#include "BasicGene.h"


class GeneDisable : public BasicGene
{
public:
    GeneDisable();
    
    virtual void Start( SpriteLife* life );
};


#endif
