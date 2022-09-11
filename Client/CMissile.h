#pragma once
#include "CObject.h"
class CMissile :
    public CObject
{
private:
    float     m_fDir;

public:
    void SetDir(bool _bUP)
    {
        if (_bUP)
            m_fDir *= -1;
        else
            m_fDir *= 1;
    }
public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    CMissile();
    ~CMissile();
};