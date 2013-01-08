//
//  GeneAssimilation.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-8.
//
//

#ifndef Lifenals_GeneAssimilation_h
#define Lifenals_GeneAssimilation_h
#include "BasicGene.h"


class GeneAssimilation : public BasicGene
{
public:
    GeneAssimilation();
    ~GeneAssimilation();
    
    virtual void Start( SpriteLife* life );
};


#endif
