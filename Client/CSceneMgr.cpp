#include "pch.h"
#include "CSceneMgr.h"

#include "CScene_Start.h"

CSceneMgr::CSceneMgr():
	m_pCurScene(nullptr),
	m_arrScene{}
{
}

CSceneMgr::~CSceneMgr()
{
	//�� ���� ����
	for (UINT i = 0; i < (UINT)SCENE_TYPE::END; ++i)
	{
		if (m_arrScene[i] != nullptr)
		{
			delete m_arrScene[i];
		}
	}
}

void CSceneMgr::init()
{
	//Scene ����
	m_arrScene[(UINT)SCENE_TYPE::START] = new CScene_Start;
	//m_arrScene[(UINT)SCENE_TYPE::TOOL] = new CScene_Tool;
	//m_arrScene[(UINT)SCENE_TYPE::START] = new CScene_Start;
	//m_arrScene[(UINT)SCENE_TYPE::START] = new CScene_Start;

	// ���� �� ����
	m_pCurScene = m_arrScene[(UINT)SCENE_TYPE::START];
}
