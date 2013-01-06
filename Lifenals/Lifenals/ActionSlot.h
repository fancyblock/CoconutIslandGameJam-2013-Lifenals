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

class SpriteLife;
class ActionGene;

class ActionSlot
{
public:
    ActionSlot();
    ~ActionSlot();
    int GetGeneCount();
    ActionGene* GetActionGene( int index );
    
protected:
    ActionGene* m_actionGenes[MAX_SLOT_CAPACITY];
    int m_geneCount;
};


#endif
