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
}


ActionSlot::~ActionSlot()
{
    //TODO
}


int ActionSlot::GetGeneCount()
{
    return m_actionGenes.size();
}


int ActionSlot::GetActionGene( int index )
{
    if( index < 0 || index >= m_actionGenes.size() )
    {
        return NULL;
    }
    
    return m_actionGenes[index];
}


bool ActionSlot::AddGene( int geneType )
{
    if( m_actionGenes.size() >= MAX_SLOT_CAPACITY )
    {
        return false;
    }
    
    m_actionGenes.push_back( geneType );
    
    return true;
}


void ActionSlot::RemoveGene( int geneType )
{
    vector<int>::iterator i;
    
    for( i = m_actionGenes.begin(); i != m_actionGenes.end(); i++ )
    {
        if( *i == geneType )
        {
            m_actionGenes.erase( i );
            break;
        }
    }
}


void ActionSlot::PopBackGene()
{    
    if( m_actionGenes.size() > 0 )
    {
        m_actionGenes.pop_back();
    }
}


void ActionSlot::CleanAllGene()
{    
    m_actionGenes.clear();
}


void ActionSlot::CloneFrom( ActionSlot* actionSlot )
{
    m_actionGenes.clear();
    
    for( int i(0); i < actionSlot->m_actionGenes.size(); i++ )
    {
        m_actionGenes.push_back( actionSlot->m_actionGenes[i] );
    }
}


