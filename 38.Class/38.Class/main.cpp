#include <iostream>
/*
	객체지향 프로그래밍(OOP) : 개발 할때 필요한 기능들을 만들어 두고 필요할때
	기능들을 조립하여 개발을 진행하는 방식을 말한다.
	데이터 + 기능을 하나로 묶어서 부품을 만들고 부품들을 조립하여 완성된
	프로그램을 만들어 나가는 방식이다
	ex)로봇을 만들때 서로 각각에 기능에 맞게 만드는 느낌

	클래스:c++에서 객체 지향 프로그래밍을 지원하기 위해 사용되는 문법이다.
	구조체와 굉장히 흡사한 방식으로 사용이 되는데 구조체에서는 변수들만 모아두고
	사용을 했지만 클래스에서는 필요한 함수들도 만들어 두고 사용 할수 있다.
	c++에서는 구조체에서도 클래스와 동일하게 함수를 만들어서 사용을 하는 것이 가능하다(c++컴파일러)
	
	클래스의 4가지속성
	캡슐화: 관련있는 변수 혹은 기능들을 하나로 묶어 주는 기능을 말한다.

	은닉화: 클래스의 변수 혹은 기능들을 외부에 공개하는 수준을 설정하는것을 말한다

	클래스의 내부: 해당 클래스 만들어진 함수 안을 말한다
	
	-public: 클래스의 내부 혹은 외부 어느곳에서든 접근이 가능 한것을 말한다.
	-private: 클래스의 내부에서는 접근이 가능하고 외부에서는  접근이 불가능
	-protected: 상속 배우고 들어가기

	상속성,다형성 ==> 상속을 배우게되면 그때 

	this -> 자기 자신 메모리이다.

*/

class CPlayer
{
	//멤버 변수
public:
	char	m_StrName[25];
	int		m_iAttack;
	int		m_iDefence; 

private:
	int		m_iHP;
	int		m_iHPMax;
	int* m_pInt;

public:
	//멤버 함수
	int GetHP()
	{
		return this->m_iHP;
		//return m_iHP;
	}

	void SetHP(int _hp)
	{
		//(*this).m_iHP = _hp;
		this->m_iHP = _hp;
	}

public:
	//생성자와 소멸자는 클래스의 이름과 동일한 이름의 함수이다.
	//이 함수들은 반환 타입이 없다.
	//만약 생성, 소멸자를 만들었으면 내부적으로 기본 생성자와, 소멸자를 사용하게 된다.
	//만들어주면 만들어준 생성자와 소멸자가 동작된다.
	//생성자: 이 클래스를 이용해서 객체를 생성할때 호출되는 함수이다.
	//이런 특징 때문에 이 클래스 데이터를 초기화하는 역할을 수행할때 효율적이다
	//생성자는 오버로딩이 가능하다.
	//여러가지 인자를 활용해서 여러 생성자를 오버로딩 해놓고 사용 하는것이 가능하다.

	CPlayer()
	{
		std::cout << "CPlayer 생성자" << std::endl;
		
		m_pInt = new int;
		*m_pInt = 999;

	}

	CPlayer(const char* _name)
	{
		std::cout << "CPlayer " << _name << "생성자 " << std::endl;
		m_pInt = new int;
		*m_pInt = 999;
		
	}
	//생성자 이니셜 라이저
	CPlayer(const char* _name, int _attack, int _def, int hp, int mxhp, int* _pint)
		:m_StrName("james"),
		m_iAttack(_attack),
		m_iDefence(_def),
		m_iHP(hp),
		m_iHPMax(mxhp),
		m_pInt(nullptr)
	{

		
	}
	~CPlayer()
	{
		if (m_pInt != nullptr)
		{
			delete m_pInt;
			m_pInt = nullptr;
			std::cout << "CPlayer 소멸자 " << std::endl;
		}
		

	}
	
};

class CPoint
{
public:
	int x;
	int y;

public:
	CPoint()
	{
		x = 0;
		y = 0;
	}
	~CPoint()
	{

	}

public:
	//연산자 오버로딩 
	//자료형 * 변수명 -- 포인터 변수 선언
	//*포인터 변수  -- 역참조
	//&변수; ----본인의 주소값 반환
	//자료형 & 변수명; -- 레퍼런스 변수 선언
	const CPoint& operator + (const CPoint& pt)
	{
		CPoint result;
		result.x = x + pt.x;
		result.y = y + pt.y;
		return result;
	}

	const CPoint& operator + (int iNumber)
	{
		CPoint result;
		result.x = x + iNumber;
		result.y = y +  iNumber;
		return result;
	}

	//대입연산자 
	 CPoint& operator = (const CPoint& _Other)
	{
		//CPoint result;
		
		x =  _Other.x;
		y =  _Other.y;

		return *this;
	}
};


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	CPlayer player;
	CPlayer player2("james",10,10,100,100,nullptr);

	std::cout << player2.m_StrName << std::endl;
	std::cout << player2.m_iAttack << std::endl;
	std::cout << player2.m_iDefence << std::endl;
	std::cout << player2.GetHP() << std::endl;


	//구조체는 접근지정자를 안써줄때는 자동으로 public
	//클래스는 접근지정자를 안써줄때는 자동으로 pirvate
	//player객체는 hp를 private를 지정했기때문에 가져올수 없다 
	//이럴때 get함수를 이용하면 가능하다

	player.SetHP(1000);
	
	std::cout << "Player HP : " << player.GetHP() << std::endl;

	CPoint pt1, pt2, pt3;


	pt2.x = 100;
	pt2.y = 100;

	//이렇게 하면 클래스내에 대입연산자가 있어서 가능한건데 직접내가 연산자 오버로딩을 사용하여 만들수도있따
	pt1 = pt2;

	pt1 = pt2 = pt3;

	pt1.x = 10;
	pt1.y = 20;

	pt2.x = 30;
	pt2.y = 40;

	//연산자 오버로딩
	//기존 연산자의 동작을 재정의 하여 사용할 수 있게 하는 기능 이다
	//pt1의 + 함수를 호출한다 . 인자로 pt2를 넘겨준다

	pt3 = pt1 + pt2;



	std::cout << "x : " << pt3.x << "y : " << pt3.y << std::endl;
	
	pt3 = pt1 + 50;
	
	std::cout << "x : " << pt3.x << "y : " << pt3.y << std::endl;

	//레퍼런스
	{
		//둘의 차이점을 굳이 말한다면
		//레퍼런스는 선언과 동시에 초기화를 해야되고 다른 변수를 가리킬수 없다.
		//하지만 포인터는 다른 변수를 가르킬수 있다.

		//컴파일러 입장:
		//레퍼런스는 다 안전하고 제한적인 반면, 포인터는 더유연하고 위험할수 있어.
		//사용자 입장:
		//레퍼런스와 포인터는 문법적으로나 사용법에서 분명한 차이가 있다...
		int a = 100;
		int* ptr = &a;
		*ptr = 500;
		
		//굳이 말을하면 레퍼런스랑 매우 유사
		//int* const ptr = &a;

		//int b = 100;
		//ptr = &b;

		int& ref = a;
		ref = 600;

		//const int* const ptr = &a;
		const int& constRef = a;
		
		//이거랑 흡사
		
		//constRef = 100; 안된다
		
	}


	
	return 0;
}