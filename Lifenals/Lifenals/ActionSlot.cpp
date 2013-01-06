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
    
    // initial the array
    for( int i(0); i < MAX_SLOT_CAPACITY; i++ )
    {
        m_actionGenes[i] = NULL;
    }
}


ActionSlot::~ActionSlot()
{
    //TODO 
}


int ActionSlot::GetGeneCount()
{
    return m_geneCount;
}


ActionGene* ActionSlot::GetActionGene( int index )
{
    if( index < 0 || index >= MAX_SLOT_CAPACITY )
    {
        return NULL;
    }
    
    return m_actionGenes[index];
}


