#pragma once
#include "CObject.h"
class CPlayer :
    public CObject
{
public:
    void CreateMissileFront();
    void CreateMissileRightSide();
    void CreateMissileLeftSide();

public:
    virtual void update();

public:
    CPlayer();
    ~CPlayer();
};

