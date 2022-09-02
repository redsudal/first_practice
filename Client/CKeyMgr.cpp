#include "pch.h"
#include "CKeyMgr.h"

int g_arrVK[(int)KEY::LAST] =
{
	VK_LEFT,  //LEFT
	VK_RIGHT, //RIGHT
	VK_UP,	  //UP
	VK_DOWN,  //DOWN
	
	'Q','W','E','R','T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	
	VK_MENU,   //ALT
	VK_CONTROL,//CTRL
	VK_LSHIFT, //LSHIFT
	VK_SPACE,  //SPACE
	VK_RETURN, //ENTER
	VK_ESCAPE, //ESC
	
};

CKeyMgr::CKeyMgr()
{}

CKeyMgr::~CKeyMgr()
{}

void CKeyMgr::init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		m_vecKey.push_back(tKeyInfo{ KEY_STATE::NONE, false });
	}
}

void CKeyMgr::update()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		// Ű�� �����ִ�
		if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
		{
			// Ű�� �������� �����־���
			if (m_vecKey[i].bPrevPush)
			{
				m_vecKey[i].eState = KEY_STATE::HOLD;
			}
			// Ű�� ó�� ���ȴ�
			else
			{
				m_vecKey[i].eState = KEY_STATE::TAP;
			}

			m_vecKey[i].bPrevPush = true;
		}
		// Ű�� ������ �ʾҴ�
		else
		{
			if (m_vecKey[i].bPrevPush)
			{
				// ������ ���Ⱦ���
				m_vecKey[i].eState = KEY_STATE::AWAY;
			}
			else
			{
				// �������� �ȴ��ȴ�
				m_vecKey[i].eState = KEY_STATE::NONE;
			}

			m_vecKey[i].bPrevPush = false;
		}

	}
	
}

