//
//  GeneCopy.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#ifndef Lifenals_GeneCopy_h
#define Lifenals_GeneCopy_h
#include "BasicGene.h"


class GeneCopy : public BasicGene
{
public:
    GeneCopy();
    ~GeneCopy();
    
    virtual void Start( SpriteLife* life );
};


#endif
