#pragma once


// �̱��� ����
// ��ü�� ������ 1���� ����
// ��𼭵� ���� ���� ����

//class CCore
//{
//private:
//	//static CCore* g_pInst;
//
//public:
//	// ���� �ɹ��Լ�
//	static CCore* GetInstance()
//	{
//		// ���� ȣ�� �� ���	
//		if (nullptr == g_pInst)
//		{
//			g_pInst = new CCore;
//		}
//		
//		return g_pInst;
//	}
//
//	static void Release()
//	{
//		if (nullptr != g_pInst)
//		{
//			delete g_pInst;
//			g_pInst = nullptr;
//		}
//		
//	}
//
//private:
//	CCore();
//	~CCore();
//};


class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hWnd;
	POINT	m_ptResolution;
public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();


private:
	CCore();
	~CCore();

};