//
//  SelectMedium.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-7.
//
//

#ifndef Lifenals_SelectMedium_h
#define Lifenals_SelectMedium_h
#include "cocos2d.h"

USING_NS_CC;

class GameLayer;

class SelectMedium : public CCLayerColor
{
public:
    virtual bool init();
    
    CREATE_FUNC( SelectMedium );
    
    void SetMainLayer( GameLayer* layer );
    int GetSelectedGene();
    
    void onSelect( CCObject* sender );
    
protected:
    int m_selectedGene;
    CCMenuItemSprite* m_btnSet[10];
    GameLayer* m_mainLayer;
};


#endif
