#include <iostream>

class CParent
{
private:
	int m_i;

public:
	CParent() :
		m_i(0)
	{
		std::cout << "부모 생성자 호출" << std::endl;
	}

	
};

class CChild : public CParent
{
private:
	float m_f;

public:
	CChild() :
		m_f(0.f),
		CParent()
	{
		std::cout << "자식 생성자 호출 " << std::endl;
	}
};

int main()
{
	//상속
	//캡슐화
	//상속
	//다형성
	//추상화

	//자식을 호출했을때
	//초기화는 부모부터 일어나지만 
	//호출순서는 자식부터 일어난다 헷갈려서는 안된다.
	//정리하면 생성자 호출순서 자식 -> 부모
	//생성자 실행순서 부모 - > 자식

	//다운캐스팅,업캐스팅
	//생성자( 복사생성자(깊은복사,얕은복사)
	//오버라이딩, 가상함수 

	CParent cp;
	CChild ch;

	CParent* pCp = &ch;

	CChild ch;
	return 0;
}