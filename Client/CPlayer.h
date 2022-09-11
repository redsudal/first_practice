#pragma once
#include "CObject.h"
class CPlayer :
    public CObject
{
public:
    void CreateMissile();

public:
    virtual void update();

public:
    CPlayer();
    ~CPlayer();
};

