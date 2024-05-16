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