#pragma once


class CTimeMgr
{
	SINGLE(CTimeMgr);
private:
	LARGE_INTEGER	m_llCurCount;
	LARGE_INTEGER	m_llPrevCount;
	LARGE_INTEGER	m_llFrequency;

	double			m_dDT;
	double			m_dAcc;
	UINT			m_iCallCount;
	UINT			m_iFPS;

	// FPS
	// 1 �����Ӵ� �ð� (Delta Time)

public:
	void init();
	void update();

public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }

};
