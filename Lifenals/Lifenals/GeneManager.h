//
//  GeneManager.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#ifndef Lifenals_GeneManager_h
#define Lifenals_GeneManager_h
#include "ActionGene.h"


class GeneManager
{
public:
    static GeneManager* sharedInstance();
    static GeneManager* m_instance;
    
    ActionGene* GetGene( int type );
    
protected:
    GeneManager();
    
protected:
    ActionGene* m_genes[eGeneCount];
    
};

#endif
