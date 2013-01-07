//
//  GeneManager.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#include "GeneManager.h"
#include "cocos2d.h"
#include "GeneCopy.h"
#include "GeneMove.h"

USING_NS_CC;


GeneManager* GeneManager::m_instance = NULL;


GeneManager* GeneManager::sharedInstance()
{
    if( m_instance == NULL )
    {
        m_instance = new GeneManager();
    }
    
    return m_instance;
}


GeneManager::GeneManager()
{
    m_genes[eGeneCopy] = new GeneCopy();
    m_genes[eGeneMove] = new GeneMove();
    //TODO 
}


ActionGene* GeneManager::GetGene( int type )
{
    return m_genes[type];
}


