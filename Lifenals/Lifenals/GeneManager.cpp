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
#include "GeneDestroy.h"
#include "GeneAssimilation.h"
#include "GeneInject.h"
#include "GeneSubGene.h"
#include "GeneDisable.h"

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
    m_genes[eGeneDestroy] = new GeneDestroy();
    m_genes[eGeneAssimilation] = new GeneAssimilation();
    m_genes[eGeneInject] = new GeneInject();
    m_genes[eGeneSubGene] = new GeneSubGene();
    m_genes[eGeneDisable] = new GeneDisable();
    //TODO 
}


ActionGene* GeneManager::GetGene( int type )
{
    return m_genes[type];
}


