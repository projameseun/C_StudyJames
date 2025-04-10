#pragma once
#include "GameInfo.h"

class CMaze
{
public:
	CMaze();
	~CMaze();

private:
	char	m_strName[64];
	char**	m_pBlock;
	char**	m_pBlockOrigin;
	int		m_iWidth;
	int		m_iHeight;

	COORD	m_tStartPos;
	COORD	m_tExitPos;

public:
	int GetWidth() const
	{
		return m_iWidth;
	}
	
	int GetHeigth() const
	{
		return m_iHeight;
	}

	const char* GetName() const
	{
		return m_strName;
	}

	COORD GetStartPos() const
	{
		return m_tStartPos;
	}

	COORD GetExitPos() const
	{
		return m_tExitPos;
	}

	BLOCK GetBlock(const COORD& _pos) const
	{
		return (BLOCK)m_pBlock[_pos.Y][_pos.X];
	}

	void SetBlock(const COORD& _pos, BLOCK _block)
	{
		m_pBlock[_pos.Y][_pos.X] = (char)_block;
	}

	void clear()
	{
		//맵을 초기화를 시키지않으면 게임을 종료하기전까지 업데이트된 변화된 것들이 나오게 된다 새롭게 하기위해선 
		//꼭 초기화를 해줘야된다.
		
		for (int i = 0; i < m_iHeight; ++i)
		{
			memcpy(m_pBlock[i], m_pBlockOrigin[i], m_iWidth);
		}
	}


public:
	bool Start(const char* pFileName);
	void Render(char* pBuffer);

	

};

