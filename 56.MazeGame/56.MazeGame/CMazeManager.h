#pragma once
#include "GameInfo.h"
class CMazeManager
{
private:
	static CMazeManager* m_pInst;
	vector<class CMaze*> m_MazeArray;
	class CMaze* m_pCurrentMaze;
	
	LARGE_INTEGER	m_fSecond;			//초
	LARGE_INTEGER	m_fPrevTime;		//이전시간 

	bool m_bStart;

public:
	static CMazeManager* GetInst()
	{
		//싱글톤이란 
		//디자인 패턴의 여러가지 종류중 하나이고
		//하나의 객체(인스턴스)를 만들어서 관리하는 기법이다.

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

