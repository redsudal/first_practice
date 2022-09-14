#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
private:
    float     m_fTheta; // 이동 방향

    Vec2      m_vDir;

public:
    void SetfTheta(float _fTheta) { m_fTheta = _fTheta; }
    void SetDir(Vec2 _vec)
    {
        m_vDir = _vec;
        m_vDir.Normalize();
    }

public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    CMissile();
    ~CMissile();
};