#include "CGameManager.h"
#include "CMazeManager.h"
#include "CObjectManager.h"


//static변수는 무조건 cpp에서 정의를 해줘야 된다
CGameManager* CGameManager::m_pInst = nullptr;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
	//여러가지 게임의 요소들을 삭제해주는 곳
	CObjectManager::DestroyInst();
	CMazeManager::DestroyInst();
}

bool CGameManager::Start()
{
	//메모리의 특정값을 초기화 할때 사용된다.
	memset(m_RenderBuffer, 0, RENDER_BUFFER_HEIGHT * RENDER_BUFFER_WIDTH);


	//오브젝트 관리자를 초기화 한다.
	if (!CObjectManager::GetInst()->Start())
	{
		return false;
	}

	//미로 초기화
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
