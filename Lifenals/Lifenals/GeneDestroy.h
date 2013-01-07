//
//  GeneDestroy.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#ifndef Lifenals_GeneDestroy_h
#define Lifenals_GeneDestroy_h
#include "BasicGene.h"

class GeneDestroy : public BasicGene
{
public:
    GeneDestroy();
    ~GeneDestroy();
    
    virtual void Start( SpriteLife* life );
};


#endif
