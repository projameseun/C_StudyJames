#pragma once
#include "GameInfo.h"

class CObjectManager
{
private:
	static CObjectManager*	m_pInst;
	class CPlayer*			m_pPlayer;
	vector<class CObject*>	m_ObjArray;

public:
	class CPlayer* GetPlayer()
	{
		return m_pPlayer;
	}

public:
	static CObjectManager* GetInst()
	{
		if (!m_pInst)
		{
			m_pInst = new CObjectManager;
		}

		return m_pInst;
	}

	static void DestroyInst()
	{
		if (m_pInst)
		{
			delete m_pInst;
			m_pInst = nullptr;
		}
	}

public:
	CObjectManager();
	~CObjectManager();

public:
	virtual bool Start();
	virtual void Update(float fDeltaTime);
	virtual void Render(char* pBuffer);

	void ClearObj();

public:
	template <typename T>
	T*	CreateObject(const COORD& _pos ={})
	{
		
		T* pObj = new T;
		if (!pObj->Start())
		{
			delete pObj;
			return nullptr;
		}

		pObj->SetPos(_pos);
		
		m_ObjArray.push_back(pObj);

		return pObj;

	}
	
	
};

