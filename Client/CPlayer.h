#pragma once
#include "CObject.h"

class CTexture;

class CPlayer :
    public CObject
{
private:
    CTexture*   m_pTex;

private:
    void CreateMissileFront();
    void CreateMissileRightSide();
    void CreateMissileLeftSide();
    void CreateMissileDownSide();

public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    CPlayer();
    ~CPlayer();
};

