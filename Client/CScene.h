#pragma once

class CObject;

class CScene
{
protected:
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END];// 오브젝트를 저장 및 관리할 벡터를 그룹 객수만큼 선언
	wstring			 m_strName; // Scene 이름

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	void update();
	void finalupdate();
	void render(HDC _dc);

	virtual void Enter() = 0; // 씬 진입 시 호출
	virtual void Exit() = 0; // 씬 탈출 시 호출

	void AddObject(CObject* _obj, GROUP_TYPE _grouptype)
	{
		m_arrObj[(UINT)_grouptype].push_back(_obj);
	}

public:
	CScene();
	virtual ~CScene();
};

