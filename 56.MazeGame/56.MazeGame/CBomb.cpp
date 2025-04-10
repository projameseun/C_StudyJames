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

		//��ź�� ������ ��,�Ʒ� ,�� ,�쿡 �����մ��� üũ
		//0 : �� 1:�Ʒ� 2:�� 3:��	
		bool	bBomb[4] = {};
		int		iCount = 0;

		for (int i = 0; i < m_iPower; ++i)
		{
			if (iCount == 4)
				break;
			COORD tPos = m_tPos;

			//��üũ
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

						//������ ������ֱ�
					}
				}
			}

			tPos = m_tPos;

			//�Ʒ� üũ
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

						//������ ������ֱ�
					}
				}
			}

			tPos = m_tPos;

			//����
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

						//������ ������ֱ�
					}
				}
			}

			tPos = m_tPos;

			//������
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

						//������ ������ֱ�
					}
				}
			}

		}//	for (int i = 0; i < m_iPower; ++i)

		//bind callback
		if (m_BombCallBack)
		{
			m_BombCallBack(this);
		}

		//�ٸ����
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
	
	// ���� �ڿ� m_tPos.Y�� ������ ������ ���ۿ��� �� �ٸ��� \n�� �����ϱ� �����̴�.
	int	iIndex = m_tPos.Y * pMaze->GetWidth() * 2 + m_tPos.X * 2 + m_tPos.Y;

	memcpy(&_pBuffer[iIndex], "��", 2);
}

void CBomb::CreateItem(const COORD* _tpos)
{
}
