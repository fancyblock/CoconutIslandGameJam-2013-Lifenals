//
//  ActionSlot.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#include "ActionSlot.h"
#include "cocos2d.h"

USING_NS_CC;


ActionSlot::ActionSlot()
{
    m_geneCount = 0;
}


ActionSlot::~ActionSlot()
{
    //TODO 
}


int ActionSlot::GetGeneCount()
{
    return m_geneCount;
}


int ActionSlot::GetActionGene( int index )
{
    if( index < 0 || index >= MAX_SLOT_CAPACITY )
    {
        return NULL;
    }
    
    return m_actionGenes[index];
}


bool ActionSlot::AddGene( int geneType )
{
    if( m_geneCount >= MAX_SLOT_CAPACITY )
    {
        return false;
    }
    
    m_actionGenes[m_geneCount++] = geneType;
    
    return true;
}


void ActionSlot::CleanAllGene()
{    
    m_geneCount = 0;
}


void ActionSlot::CloneFrom( ActionSlot* actionSlot )
{
    m_geneCount = actionSlot->m_geneCount;
    
    for( int i(0); i < MAX_SLOT_CAPACITY; i++ )
    {
        m_actionGenes[i] = actionSlot->m_actionGenes[i];
    }
}


