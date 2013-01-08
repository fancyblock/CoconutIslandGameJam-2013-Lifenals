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
    "Gene Copy",
    "Gene Move",
    "Gene Jump",
    "Gene Assimilation",
    "Gene Destroy",
    "Gene DestroyOther",
    "Gene Disable",
    "Gene Rape",
    "Gene Inject",
    "Gene MixGene"
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

