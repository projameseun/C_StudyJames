#pragma once
#include "CObject.h"
class CBomb : public CObject	
{
public:
	CBomb();
	~CBomb();

private:
	float		m_fBombTime;
	int			m_iPower;	
	std::function<void(CBomb*)>	m_BombCallBack;		//함수포인터

public:
	void SetPower(int iPower)
	{
		m_iPower = iPower;
	}

public:
	virtual bool Init();
	virtual void Update(float _fDeltaTime);
	virtual void Render(char* _pBuffer);
	
public:
	//std::function<void(int)> funcName1 = Func; //함수 대입
	//std::function<void(int)> funcName2 = [](int a) {}; // 람다함수
	//std::function<void(int)> funcName3 = std::bind(함수의주소, 인자1,인자2,); //std::bind
	// placeholders자리표시자 _1,_2,_3...사용 할수있는데 그 해당번호를 고정시키지 않겠다는거임
	//함수포인터를 사용해서 관리
	template <typename T>
	void SetBomblCallBack(T* _pObj, void(T::* _pFunc)(CBomb*))
	{
		m_BombCallBack = std::bind(_pFunc, _pObj, std::placeholders::_1);
	}

private:
	void CreateItem(const COORD* _tpos);
};

