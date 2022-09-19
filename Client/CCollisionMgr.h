#pragma once
class CCollisionMgr
{
	SINGLE(CCollisionMgr);
private:
	UINT	m_arrCheck[(UINT)GROUP_TYPE::END];

public:
	void init();
	void update();
	void CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	void ResetCheck()
	{
		memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);
	}
};

