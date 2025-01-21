#include "CPlayer.h"
#include "CMaze.h"
#include "CMazeManager.h"
#include "CObjectManager.h"


CPlayer::CPlayer() : 
	m_fSpeed(5.f),
	m_fX(0.f),
	m_fY(0.f),
	m_iBombCount(0),
	m_iBombMax(1),
	m_iPower(1)
{
}

CPlayer::~CPlayer()
{
}

bool CPlayer::Start()
{
	return true;
}

void CPlayer::Update(float fDeltaTime)
{
	//맵정보 가져오기
	CMaze* pMaze = CMazeManager::GetInst()->GetCurrentMaze();

	/*
	0 : 이전에 누른적이 없고 현재에도 누르지 않은 상태
	0x1 : 이전에 누른적이 있고 현재는 눌려있지 않은 상태
	0x8000 : 이전에 누른적이 없고 현재는 눌려있는 상태
	0x8001 : 이전에 누른적이 있고 현재도 눌려있는 상태
	*/

	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_fY -= m_fSpeed * fDeltaTime;

		if (m_fY <= -1.f)
		{
			m_fY += 1.f;
			--m_tPos.Y;

			if (m_tPos.Y < 0)
			{
				m_tPos.Y = 0;
			}

			else
			{
				BLOCK eBlock = pMaze->GetBlock(m_tPos);

				//이동할 위치가 벽이라면 이전으로 돌린다
				if (eBlock == BLOCK::WALL)
				{
					++m_tPos.Y;
				}
			}
			
		}

	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_fY += m_fSpeed * fDeltaTime;

		if (m_fY >= 1.f)
		{
			m_fY -= 1.f;
			++m_tPos.Y;

			if (m_tPos.Y >= pMaze->GetHeigth())
			{
				m_tPos.Y = pMaze->GetHeigth() - 1;
			}

			else
			{
				BLOCK eBlock = pMaze->GetBlock(m_tPos);

				//이동할 위치가 벽이라면 이전으로 돌린다
				if (eBlock == BLOCK::WALL)
				{
					--m_tPos.Y;
				}
			}
		}
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_fX -= m_fSpeed * fDeltaTime;

		if (m_fX <= -1.f)
		{
			m_fX += 1.f;
			--m_tPos.X;

			if (m_tPos.X < 0)
			{
				m_tPos.X = 0;
			}

			else
			{
				BLOCK eBlock = pMaze->GetBlock(m_tPos);

				//이동할 위치가 벽이라면 이전으로 돌린다
				if (eBlock == BLOCK::WALL)
				{
					++m_tPos.X;
				}
			}
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_fX += m_fSpeed * fDeltaTime;

		if (m_fX >= 1.f)
		{
			m_fX -= 1.f;
			++m_tPos.X;

			if (m_tPos.X >= pMaze->GetHeigth())
			{
				m_tPos.X = pMaze->GetHeigth() - 1;
			}

			else
			{
				BLOCK eBlock = pMaze->GetBlock(m_tPos);

				//이동할 위치가 벽이라면 이전으로 돌린다
				if (eBlock == BLOCK::WALL)
				{
					--m_tPos.X;
				}
			}
		}
	}

	if (pMaze->GetBlock(m_tPos) == BLOCK::EXIT)
	{
		CMazeManager::GetInst()->Exit();
	}

	//아이템 추가

	//폭탄추가

	
}

void CPlayer::Render(char* pBuffer)
{
	CMaze* pMaze = CMazeManager::GetInst()->GetCurrentMaze();

	//제일 뒤에 m_tPos.Y를 더해준 이유는 버퍼에는 각 줄마다 \n이 존재해서
	int idx = m_tPos.Y * pMaze->GetWidth() * 2 + m_tPos.X * 2 + m_tPos.Y;

	memcpy(&pBuffer[idx], "◆", 2);

	

}
