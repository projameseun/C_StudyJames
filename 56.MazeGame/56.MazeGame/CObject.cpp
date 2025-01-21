#include "CObject.h"

CObject::CObject() 
{
	m_tPos.X = 0;
	m_tPos.Y = 0;
	m_bActive = true;
}

CObject::~CObject()
{
}

bool CObject::Start()
{
	return true;
}

void CObject::Update(float fDeltaTime)
{
}

void CObject::Render(char* pBuffer)
{
}
