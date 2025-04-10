#include "CBomb.h"
#include "CMaze.h"
#include "CMazeManager.h"
#include "CObjectManager.h"

CBomb::CBomb() :
	m_fBombTime(3.f),
	m_iPower(1)	
{
}

CBomb::~CBomb()
{
	//if (m_pObj)
	//{
	//	delete m_pObj;
	//	m_pObj = nullptr;
	//}

	;
}

bool CBomb::Start()
{
	return true;
}

void CBomb::Update(float _fDeltaTime)
{
	m_fBombTime -= _fDeltaTime;
	if (m_fBombTime <= 0.f)
	{
		CMaze* pMaze = CMazeManager::GetInst()->GetCurrentMaze();

		pMaze->SetBlock(m_tPos, BLOCK::ROAD);

		//폭탄이 터지는 위,아래 ,좌 ,우에 벽이잇는지 체크
		//0 : 위 1:아래 2:좌 3:우	
		bool	bBomb[4] = {};
		int		iCount = 0;

		for (int i = 0; i < m_iPower; ++i)
		{
			if (iCount == 4)
				break;
			COORD tPos = m_tPos;

			//위체크
			if (!bBomb[(int)DIR::UP])
			{
				tPos.Y -= (i + 1);
				
				if (tPos.Y >= 0)
				{
					if (pMaze->GetBlock(tPos) == BLOCK::WALL)
					{
						pMaze->SetBlock(tPos, BLOCK::ROAD);
						bBomb[(int)DIR::UP] = true;
						++iCount;

						//아이템 만들어주기
					}
				}
			}

			tPos = m_tPos;

			//아래 체크
			if (!bBomb[(int)DIR::DOWN])
			{
				tPos.Y += (i + 1);

				if (tPos.Y < pMaze->GetHeigth())
				{
					if (pMaze->GetBlock(tPos) == BLOCK::WALL)
					{
						pMaze->SetBlock(tPos, BLOCK::ROAD);
						bBomb[(int)DIR::DOWN] = true;
						++iCount;

						//아이템 만들어주기
					}
				}
			}

			tPos = m_tPos;

			//왼쪽
			if (!bBomb[(int)DIR::LEFT])
			{
				tPos.X -= (i + 1);

				if (tPos.X >=0)
				{
					if (pMaze->GetBlock(tPos) == BLOCK::WALL)
					{
						pMaze->SetBlock(tPos, BLOCK::ROAD);
						bBomb[(int)DIR::LEFT] = true;
						++iCount;

						//아이템 만들어주기
					}
				}
			}

			tPos = m_tPos;

			//오른쪽
			if (!bBomb[(int)DIR::RIGHT])
			{
				tPos.X += (i + 1);

				if (tPos.X < pMaze->GetWidth())
				{
					if (pMaze->GetBlock(tPos) == BLOCK::WALL)
					{
						pMaze->SetBlock(tPos, BLOCK::ROAD);
						bBomb[(int)DIR::RIGHT] = true;
						++iCount;

						//아이템 만들어주기
					}
				}
			}

		}//	for (int i = 0; i < m_iPower; ++i)

		//bind callback
		if (m_BombCallBack)
		{
			m_BombCallBack(this);
		}

		//다른방법
		/*if (m_pFunc && m_pObj)
		{
			(m_pObj->*m_pFunc)(this);
		}*/

		Destroy();
		
	}	

}

void CBomb::Render(char* _pBuffer)
{
	CMaze* pMaze = CMazeManager::GetInst()->GetCurrentMaze();
	
	// 제일 뒤에 m_tPos.Y을 더해준 이유는 버퍼에는 각 줄마다 \n이 존재하기 때문이다.
	int	iIndex = m_tPos.Y * pMaze->GetWidth() * 2 + m_tPos.X * 2 + m_tPos.Y;

	memcpy(&_pBuffer[iIndex], "♨", 2);
}

void CBomb::CreateItem(const COORD* _tpos)
{
}
