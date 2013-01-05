//
//  GlobalWork.h
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#ifndef Lifenals_GlobalWork_h
#define Lifenals_GlobalWork_h

#include "cocos2d.h"

USING_NS_CC;


// store some common settings
class GlobalWork
{
public:
    static GlobalWork* Singleton();             // return the singleton of the class
    void Destory();                             // destory the object
    
    void SetScreenSize( int wid, int hei );     // set the screen size
    void SetScreenResolution( int wid, int hei );
    // the the screen resolution
    void SetLogicSize( int wid, int hei );      // set the screen logic size
    float GetPositionFactorX();                 // screen scale factor x
    float GetPositionFactorY();                 // screen scale factor y
    float GetSizeFactorX();                     // size scale factor x
    float GetSizeFactorY();                     // size scale factor y
    
protected:
    GlobalWork();                               // constructor
    ~GlobalWork();                              // deconstructor
    void refreshFactor();                       // refresh the screen convert factor
    
    static GlobalWork* m_instance;              // instance variable
    
protected:
    CCSize m_screenSize;                        // store screen size
    CCSize m_screenResolution;                  // store screen resolution
    CCSize m_logicSize;                         // stroe logic size
    
    CCPoint m_positionFactor;                   // for convert the screen coordinate
    CCPoint m_sizeFactor;                       // for convert the item size
    
};


#define SGLOBAL (*GlobalWork::Singleton())
#define POS(x,y) ccp((x)*GlobalWork::Singleton()->GetPositionFactorX(),(y)*GlobalWork::Singleton()->GetPositionFactorY())


#endif
