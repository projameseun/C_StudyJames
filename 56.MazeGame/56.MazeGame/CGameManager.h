#pragma once
#include "GameInfo.h"

class CGameManager
{
private:
	static CGameManager* m_pInst;	//싱글톤 사용할 인스턴스

	char m_RenderBuffer[RENDER_BUFFER_HEIGHT * RENDER_BUFFER_WIDTH];		//맵 크기
	
public:
	static CGameManager* GetInst()
	{
		//싱글톤이란 
		//디자인 패턴의 여러가지 종류중 하나이고
		//하나의 객체(인스턴스)를 만들어서 관리하는 기법이다.
		if (!m_pInst)
		{
			m_pInst = new CGameManager;
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

private:
	CGameManager();
	~CGameManager();


public:
	bool Start();
	void Update();
	

};

