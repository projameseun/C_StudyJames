#include "CObjectManager.h"
#include "CPlayer.h"

CObjectManager* CObjectManager::m_pInst = nullptr;

CObjectManager::CObjectManager() : m_pPlayer(nullptr)
{

}	

CObjectManager::~CObjectManager()
{
	
	for (int i = 0; i < m_ObjArray.size(); ++i)
	{
		delete	m_ObjArray[i];
		m_ObjArray[i] = nullptr;

	}

	delete m_pPlayer;
	m_pPlayer = nullptr;
	
}

bool CObjectManager::Start()
{
	m_pPlayer = new CPlayer;

	if (!m_pPlayer->Start())
	{
		return false;
	}

	return true;
}

void CObjectManager::Update(float fDeltaTime)
{
	m_pPlayer->Update(fDeltaTime);

	vector<CObject*>::iterator iter = m_ObjArray.begin();
	vector<CObject*>::iterator iterend = m_ObjArray.end();

	//아이템,폭탄등 오브젝트 업데이트

	for (; iter != iterend;)
	{
		if (!(*iter)->GetActive())
		{
			delete(*iter);
			iter = m_ObjArray.erase(iter);
			iterend = m_ObjArray.end();
			continue;
		}

		(*iter)->Update(fDeltaTime);
		++iter;
	}


	
}

void CObjectManager::Render(char* pBuffer)
{
	for (int i = 0; i < m_ObjArray.size(); ++i)
	{
		m_ObjArray[i]->Render(pBuffer);
	}

	m_pPlayer->Render(pBuffer);

}

void CObjectManager::ClearObj()
{
	for (int i = 0; i < m_ObjArray.size(); ++i)
	{
		delete m_ObjArray[i];
	}

	m_ObjArray.clear();

}
