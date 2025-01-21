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
	//������ ��������
	CMaze* pMaze = CMazeManager::GetInst()->GetCurrentMaze();

	/*
	0 : ������ �������� ���� ���翡�� ������ ���� ����
	0x1 : ������ �������� �ְ� ����� �������� ���� ����
	0x8000 : ������ �������� ���� ����� �����ִ� ����
	0x8001 : ������ �������� �ְ� ���絵 �����ִ� ����
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

				//�̵��� ��ġ�� ���̶�� �������� ������
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

				//�̵��� ��ġ�� ���̶�� �������� ������
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

				//�̵��� ��ġ�� ���̶�� �������� ������
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

				//�̵��� ��ġ�� ���̶�� �������� ������
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

	//������ �߰�

	//��ź�߰�

	
}

void CPlayer::Render(char* pBuffer)
{
	CMaze* pMaze = CMazeManager::GetInst()->GetCurrentMaze();

	//���� �ڿ� m_tPos.Y�� ������ ������ ���ۿ��� �� �ٸ��� \n�� �����ؼ�
	int idx = m_tPos.Y * pMaze->GetWidth() * 2 + m_tPos.X * 2 + m_tPos.Y;

	memcpy(&pBuffer[idx], "��", 2);

	

}
