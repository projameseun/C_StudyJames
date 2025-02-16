#pragma once
#include "CObject.h"

class CPlayer : public CObject
{
public:
	CPlayer();
	~CPlayer();

private:
	float	m_fSpeed;
	float	m_fX;
	float	m_fY;
	int		m_iBombCount;
	int		m_iBombMax;
	int		m_iPower;

public:
	void clear()
	{
		m_fX = 0.f;
		m_fY = 0.f;
	}
	
public:
	virtual bool Start();
	virtual void Update(float fDeltaTime);
	virtual void Render(char* pBuffer);

public:
	void BombCallBack(class CBomb* _pBomb);		//ÆøÅºÄÝ¹é
};

