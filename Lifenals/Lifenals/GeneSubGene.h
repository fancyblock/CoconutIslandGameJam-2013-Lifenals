//
//  GeneSubGene.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-8.
//
//

#ifndef Lifenals_GeneSubGene_h
#define Lifenals_GeneSubGene_h
#include "BasicGene.h"


class GeneSubGene : public BasicGene
{
public:
    GeneSubGene();
    
    virtual void Start( SpriteLife* life );
};


#endif
