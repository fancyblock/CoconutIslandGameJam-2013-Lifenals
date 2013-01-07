//
//  ActionSlot.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#ifndef Lifenals_ActionSlot_h
#define Lifenals_ActionSlot_h
#include "GameSettings.h"
#include <vector>

using namespace std;

class SpriteLife;
class ActionGene;

class ActionSlot
{
public:
    ActionSlot();
    ~ActionSlot();
    int GetGeneCount();
    int GetActionGene( int index );
    bool AddGene( int geneType );
    void RemoveGene( int geneType );
    void CleanAllGene();
    void CloneFrom( ActionSlot* actionSlot );
    
protected:
    vector<int> m_actionGenes;
};


#endif
