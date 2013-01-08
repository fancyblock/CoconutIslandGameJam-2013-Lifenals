//
//  GlobalWork.cpp
//  Lifenals
//
//  Created by He JiaBin on 13-1-5.
//
//

#include "GlobalWork.h"

using namespace std;


GlobalWork* GlobalWork::m_instance = NULL;


GlobalWork::GlobalWork()
{
}


GlobalWork::~GlobalWork()
{
}


GlobalWork* GlobalWork::Singleton()
{
    if( m_instance == NULL )
    {
        m_instance = new GlobalWork();
    }
    
    return m_instance;
}


void GlobalWork::Destory()
{
    if( m_instance != NULL )
    {
        delete m_instance;
        m_instance = NULL;
    }
}


void GlobalWork::SetScreenSize( int wid, int hei )
{
    m_screenSize.setSize( wid, hei );
    refreshFactor();
}


void GlobalWork::SetScreenResolution( int wid, int hei )
{
    m_screenResolution.setSize( wid, hei );
    refreshFactor();
}


void GlobalWork::SetLogicSize( int wid, int hei )
{
    m_logicSize.setSize( wid, hei );
    refreshFactor();
}


void GlobalWork::refreshFactor()
{
    if( m_logicSize.width > 0 && m_logicSize.height > 0 )
    {
        m_positionFactor.x = m_screenSize.width / m_logicSize.width;
        m_positionFactor.y = m_screenSize.height / m_logicSize.height;
        
        m_sizeFactor.x = m_screenResolution.width / m_logicSize.width;
        m_sizeFactor.y = m_screenResolution.height / m_logicSize.height;
    }
}


float GlobalWork::GetPositionFactorX()
{
    return m_positionFactor.x;
}


float GlobalWork::GetPositionFactorY()
{
    return m_positionFactor.y;
}


float GlobalWork::GetSizeFactorX()
{
    return m_sizeFactor.x;
}


float GlobalWork::GetSizeFactorY()
{
    return m_sizeFactor.y;
}

