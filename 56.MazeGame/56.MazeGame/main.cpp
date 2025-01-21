#include "GameInfo.h"
#include "CGameManager.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(static_cast<unsigned int>(time(0)));

	if (!CGameManager::GetInst()->Start())
	{
		CGameManager::DestroyInst();

		return 0;
	}

	//°ÔÀÓ update
	CGameManager::GetInst()->Update();

	CGameManager::GetInst()->DestroyInst();

	
	return 0;
}