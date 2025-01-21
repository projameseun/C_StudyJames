#pragma once
#include "GameInfo.h"

class CObject
{
public:
	CObject();
	virtual ~CObject();

protected:
	COORD	m_tPos;
	bool	m_bActive;

public:
	bool GetActive() const
	{
		return m_bActive;
	}

	void Destroy()
	{
		m_bActive = false;
	}

	void SetPos(short x, short y)
	{
		m_tPos.X = x;
		m_tPos.Y = y;
	}

	void SetPos(const COORD& _fPos)
	{
		m_tPos = _fPos;
	}

	COORD GetPos() const
	{
		return m_tPos;
	}

public:
	virtual bool Start();
	virtual void Update(float fDeltaTime);
	virtual void Render(char* pBuffer);
};

