#include <iostream>
#include <time.h>


int main()
{
	//srand((unsigned int)time(NULL));
	srand(static_cast<unsigned int>(time(NULL)));

	/*
		난수(무작위의 수)
		컴퓨터는 랜덤이라는 수를 만들수 없다.
		랜덤이란 무작위의 수를 나오게 하는건데 이 무작위의 수를 무의식적으로 선택 할수 없기 때문에 컴퓨터는 랜덤을 만들수 없다.
		그러므로, 컴퓨터는 마치 랜덤처럼 보이는 정해진 입력에 값을 나타내고 있다
		컴퓨터가 만들어 낸 랜덤은 여러 계산을 통해서 사람들이 볼때 마치 임의의값인 랜덤처럼 보이게 하는거다.

		rand()
		무작위의 랜덤테이블이란 것이 존재하고 이를 리턴하는거다.
		rand()함수는 내부에 RAND_MAX #define으로 정의가 되어 있고 이숫자는 16진수로 되어 있는데, 10진수로 바꾸게 되면 32,767으로 되어 있다.
		결국 rand()함수가 표현할수 있는 return값은 0~32,767값이 나온다.
		rand함수는 프로그램이 실행될때 값이 딱 정해지기 때문에 프로그램을 여러번 실행을 시켜도 동일한 값이 나온다.
	*/

	//std::cout << "1 rand: " << rand() << std::endl;
	//std::cout << "2 rand: " << rand() << std::endl;
	//std::cout << "3 rand: " << rand() << std::endl;
	//std::cout << "4 rand: " << rand() << std::endl;
	//std::cout << "5 rand: " << rand() << std::endl;

	/*
		rand함수만으로는 표현할수 없기때문에 나오게 된게 srand(시드값)함수 이다.
		srand(seed값)
		srand는 rand함수에 사용될 수를 초기화 한다.이 초기화를 매개변수로 받는 seed값을 이용해서 사용한다.
		아래에는 srand때문에 랜드가 초기화가 되지만 seed값이 동일하면 결국 똑같은 수가 반복되기 때문에 우리가 원하는 랜덤이 아니다.
	*/

	//srand(5000);
	//std::cout << "rand :" << rand() << std::endl;
	//srand(5000);
	//std::cout << "rand :" << rand() << std::endl;
	//srand(6000);
	//std::cout << "rand :" << rand() << std::endl;
	//srand(200);
	//std::cout << "rand :" << rand() << std::endl;

	/*
		seed 값이 계속변할수 있다면 rand()함수에 계쏙 다른 값을 출력할수 있을것이다 .
		그래서 나오게 된게 time시간 함수이다
		time함수
		UCT(1972년 1월 1일 0분 0초부터 시행된 국제 표준시) 이시간을 정수값으로 반환해주는 함수가 time함수이다.
		결론: seed값안에 time이라는 시간함수를 넣어준다


	*/

	//srand((unsigned int)time(NULL));
	//srand(static_cast<unsigned int>(time(NULL)));
	//std::cout << time(0) << std::endl;
	//std::cout << "1.rand :" << rand() << std::endl;
	//std::cout << "2.rand :" << rand() << std::endl;
	//std::cout << "3.rand :" << rand() << std::endl;
	//std::cout << "4.rand :" << rand() << std::endl;
	//std::cout << "5.rand :" << rand() << std::endl;

	//우리가 정해진 범위의 숫자안에서 랜덤을 가져오게 하고싶다.
	//이때 사용하는게 나머지 연산자이다.
	//어떤 큰숫자가 와도 나머지 연산자를 사용하면 내가 원하는 범위에 값을 나타낼수 있다.
	//이부분이 이해가 안된다면 작은숫자를 넣어서 테스트해보면 바로 알수있다.

	//rand()함수는 내부적으로 PRNG알고리즘을 사용힌다 
	// 초기화가 되지 않는한 항상 고정된값 seed = 1 을 사용한다 
	//그렇다면 seed(1) 테이블에 해당하는거만 가져와야되는데 왜 다르게 나오냐?
	// PRNG 계산법 ==> X n+1 = (a . x(n) + c) mod m 
	// x0 : 초기값(seed) x1,x2,x3...순차적으로 계산됨 
	// ★★★★ x0 가 같다면 PRNG는 항상동일한 x1,x2,x3...새로운값을 계산하게 된다.
	// 
	//seed란 정확히 얘기를 해주면 ==> 난수생성기(PRNG)가 난수를 계산할때 사용하는 초기값으로, 난수 시퀸스를 결정하는 중요한 입력값이다.
	// seed값이 같으면 항상 동일한 난수 시퀸스를 생성하며 seed를 다양화 하면 서로 다른 시퀸스를 얻을수 있다.
	// 시퀸스란? ==>일련의 순서가 있는 값들의 집합이라고 볼수 있다.
	// 
	//이 함수에 숫자를 대입하면 난수생성기(PRNG) 라고부른다 
	//PRNG는 난수생성기를 의미하고 실제 난수를 생성하는게아니라 수학적 알고리즘을 기반으로 "난수 처럼 보이는 숫자" 를 생성하는거다 .
	//PRNG는 항상 동일한숫자를 생성한다 그러기 때문에 계속 변경되는숫자를 얻기위해서는 time함수를 같이 사용해야 된다.

	//time() 함수안에 왜 NULL ,0 을넣는가?
	//time함수는 기본적으로 현재시간을 time_t타입으로 반환 한다 이시간은 보통 Unix 시스템에서 1970년 1월1일 00:00:00(UTC_)부터의 경과 시간을 초 단위로 저장하는 자료형이다
	//time_t time(time_t* ptr); 
	//timet*t ptr 현재시간을 저장할 메모리 주소를 전달한다
	//만약에 ptr이 NULL 또는 0이라면 현재 시간을 반환만하고 저장하지 않는다

	time_t currentTime = time(NULL);		//현지시간반환
	std::cout << "현재 시간: " << currentTime << std::endl;

	//만약ㅁ에 시간을저장하고 싶다
	time_t nowTime;
	time(&nowTime);	//현재 시간을 저장

	//팁 NULL을 전달하는것은 기본적으로 값을 반환하고 메모리공간을 사용하지 않겠다는 의도를 많이 나타낸다


	////0~2까지만 무조건나온다
	///*int iRand = rand() % 3;*/
	//std::cout << iRand << std::endl;

	////0~99까지만 나오게한다
	//iRand = rand() % 100;

	////1~100까지만 나오게한다
	//iRand = rand() % 100 + 1;		//0 ~99 나오게된다 

	////100 ~ 199 까지만 나오게한다

	//iRand = rand() % 100 + 100;	

	//float fRand = rand() % 10000 / 100.f;	//소수점 둘째자리의 숫자를 사용할수도 있다.
	//std::cout << "Rand :" << fRand << std::endl;

	//최소 공격력 최대 공격력
	//500~1000
	//int iMin = 500;
	//int iMax = 1000;

	//0 ~500값이 나오게 해야된다. 

	/*if (fRand < 1.f)
	{
		std::cout << "에스더 획득 " << std::endl;
	}
	else if (fRand < 50.f)
	{
		std::cout << "유물 획득 " << std::endl;
	}
	else if (fRand < 60.f)
	{
		std::cout << "희귀 획득 " << std::endl;
	}
	else if (fRand < 70.f)
	{
		std::cout << "일반 획득 " << std::endl;
	}
	else
	{
		std::cout << "아이템 없음 " << std::endl;
	}*/

	int iMax = 1000;
	int iMin = 500;

	int iRand = (rand() % (1000 - 500 + 1)) + 500;

	std::cout << iRand << std::endl;

	return 0;
}