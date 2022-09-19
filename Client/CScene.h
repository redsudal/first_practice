#pragma once

class CObject;

class CScene
{
protected:
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END];// ������Ʈ�� ���� �� ������ ���͸� �׷� ������ŭ ����
	wstring			 m_strName; // Scene �̸�

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	void update();
	void finalupdate();
	void render(HDC _dc);

	virtual void Enter() = 0; // �� ���� �� ȣ��
	virtual void Exit() = 0; // �� Ż�� �� ȣ��

	void AddObject(CObject* _obj, GROUP_TYPE _grouptype)
	{
		m_arrObj[(UINT)_grouptype].push_back(_obj);
	}

public:
	CScene();
	virtual ~CScene();
};

