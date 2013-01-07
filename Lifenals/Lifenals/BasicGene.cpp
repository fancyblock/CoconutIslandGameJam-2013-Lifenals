//
//  BasicGene.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#include "BasicGene.h"

const char* g_geneName[]=
{
    "GeneCopy",
    "GeneMove",
    "GeneJump",
    "GeneAssimilation",
    "GeneDestroy",
    "GeneDestroyOther",
    "GeneDisable",
    "GeneRape",
    "",
    ""
};


BasicGene::BasicGene()
{
    m_life = NULL;
}


BasicGene::~BasicGene()
{
    //TODO 
}


void BasicGene::Start( SpriteLife* life )
{
    m_life = life;
}


int BasicGene::GetType()
{
    return m_type;
}

