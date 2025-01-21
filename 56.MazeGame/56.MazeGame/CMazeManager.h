#pragma once
#include "GameInfo.h"
class CMazeManager
{
private:
	static CMazeManager* m_pInst;
	vector<class CMaze*> m_MazeArray;
	class CMaze* m_pCurrentMaze;
	
	LARGE_INTEGER	m_fSecond;			//��
	LARGE_INTEGER	m_fPrevTime;		//�����ð� 

	bool m_bStart;

public:
	static CMazeManager* GetInst()
	{
		//�̱����̶� 
		//������ ������ �������� ������ �ϳ��̰�
		//�ϳ��� ��ü(�ν��Ͻ�)�� ���� �����ϴ� ����̴�.

		if (!m_pInst)
		{
			m_pInst = new CMazeManager;
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
	void Exit()
	{
		m_bStart = false;
	}

	class CMaze* GetCurrentMaze() const
	{
		return m_pCurrentMaze;
	}

	int GetMazeCount() const
	{
		return m_MazeArray.size();
	}

private:
	CMazeManager();
	~CMazeManager();


	
public:
	bool Start();
	void Update(int _idx, char* pBuffer);
	int	MazeMainMenu();
};

