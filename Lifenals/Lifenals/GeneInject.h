//
//  GeneInject.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-8.
//
//

#ifndef Lifenals_GeneInject_h
#define Lifenals_GeneInject_h
#include "BasicGene.h"


class GeneInject : public BasicGene
{
public:
    GeneInject();
    ~GeneInject();
    
    virtual void Start( SpriteLife* life );
};


#endif
