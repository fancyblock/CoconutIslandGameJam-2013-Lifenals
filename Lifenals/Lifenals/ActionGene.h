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


// all the actions
enum
{
    eGeneCopy = 0,
    eGeneMove,
    eGeneJump,
    eGeneAssimilation,
    eGeneDestroy,
    eGeneDestroyOther,
    eGeneDisable,
    eGeneRape,
    eGeneInject,
    eGeneMixGene,
    eGeneCount
};

extern const char* g_geneName[];


class ActionGene
{
public:
    virtual void Start( SpriteLife* life ) = 0;
    virtual int GetType() = 0;
};


#endif
