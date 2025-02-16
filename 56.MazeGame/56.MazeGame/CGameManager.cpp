#include "CGameManager.h"
#include "CMazeManager.h"
#include "CObjectManager.h"


//static������ ������ cpp���� ���Ǹ� ����� �ȴ�
CGameManager* CGameManager::m_pInst = nullptr;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
	//�������� ������ ��ҵ��� �������ִ� ��
	CObjectManager::DestroyInst();
	CMazeManager::DestroyInst();
}

bool CGameManager::Start()
{
	//�޸��� Ư������ �ʱ�ȭ �Ҷ� ���ȴ�.
	memset(m_RenderBuffer, 0, RENDER_BUFFER_HEIGHT * RENDER_BUFFER_WIDTH);


	//������Ʈ �����ڸ� �ʱ�ȭ �Ѵ�.
	if (!CObjectManager::GetInst()->Start())
	{
		return false;
	}

	//�̷� �ʱ�ȭ
	if (!CMazeManager::GetInst()->Start())
	{
		return false;
	}




	return true;
}

void CGameManager::Update()
{
	while (true)
	{
		
		int iMenu = CMazeManager::GetInst()->MazeMainMenu();

		if (iMenu == CMazeManager::GetInst()->GetMazeCount() + 1)
		{ 
			return;
		}
		else if (iMenu == 0)
		{
			continue;
		}

		CMazeManager::GetInst()->Update(iMenu - 1, m_RenderBuffer);

	
	}
	

}
