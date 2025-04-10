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

	//반환형(클래스이름::* 포인터이름)(매개변수 목록);
	//멤버함수 포인터 객체포인터 멤버변수추가
	//void(CObject::* m_pFunc)(CBomb*);
	//CObject* m_pObj;

public:
	void SetPower(int iPower)
	{
		m_iPower = iPower;
	}

public:
	virtual bool Start();
	virtual void Update(float _fDeltaTime);
	virtual void Render(char* _pBuffer);
	
public:
	//std::function<void(int)> funcName1 = Func; //함수 대입
	//std::function<void(int)> funcName2 = [](int a) {}; // 람다함수
	//std::function<void(int)> funcName3 = std::bind(함수의주소, 인자1,인자2,); //std::bind
	// placeholders자리표시자 _1,_2,_3...사용 할수있는데 그 해당번호를 고정시키지 않겠다는거임
	//템플릿을 사용하여 특정 객체의 멤버함수를 콜백으로 설정하는 함수

	//1.콜백 함수가 호출될 객체의 포인터, 2.타입의 인수를 받는멤버 함수포인터
	//std::bind는 멤버 함수 포인터와 객체 포인터를 결합하여 멤버 함수를 호출할 수 있는 함수 객체를 생성할 수도 있습니다.

//	//placeholders설명 
//	int sum(int a, int b, int c)
//	{
//		return a + b * 10 + c * 100;
//}
//	int main()
//	{

//		auto func3 = std::bind(sum, 1, std::placeholder::_2, std::placeholder::_1);
//		cout << func3(2, 3) << endl;
//	}
	template <typename T>
	void SetBomblCallBack(T* _pObj, void(T::* _pFunc)(CBomb*))
	{
		m_BombCallBack = std::bind(_pFunc, _pObj,placeholders::_1);		
	/*	m_pObj = _pObj;
		m_pFunc = static_cast<void (CObject::*)(CBomb*)>(_pFunc);*/
	}

private:
	void CreateItem(const COORD* _tpos);
};

