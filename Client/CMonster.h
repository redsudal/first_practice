#pragma once
#include "CObject.h"
class CMonster :
    public CObject
{
private:
    float       m_fSpeed;
    float       m_fMaxDistance;
    Vec2        m_vCenterPos;
    int         m_iDir;

public:
    float GetSpeed() { return m_fSpeed; }
    void SetSpeed(float _f) { m_fSpeed = _f; }

    void SetCenterPos(Vec2 _V2) { m_vCenterPos = _V2; }


public:
    virtual void update();

public:
    CMonster();
    ~CMonster();
};

