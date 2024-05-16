#include <iostream>

int main()
{
	/*
		반복문(loop):프로그램 내에서 똑같은 명령을 일정 횟수만큼 반복하여 수행하도록 제어하는 명령문이다.
		단순하게 얘기하면 동일한 코드를 반복해서 동작 시킬대 활용하는 기능이다.

		for문
		for(초기값; 조건식; 증가값)
		{
			코드블럭;
		}의 형태로 구성된다.

		1.초기값은 for문이 시작될때 1번만 실행 된다.
		2.조건식은 매번 반복할때 마다 체크하게 되고 조건식이 true일 때 코드블럭 안의 코드가 동작되고 false가 되면 for문을 빠져나오게 된다.
		3.증가값은 코드가 1번 실행되면 증가값이 동작 되고 그 후에 조건이 체크된다.

		for문 실행순서
		초기값 -> 조건식 -> 코드실행 -> 증가값 -> 조건식 -> 코드실행 -> 증가값 -> 조건식 ->코드실행 ....false일때 for문 종료

		반복문 공통
		break를 사용하면 반복문을 빠져 나오게 된다.
		continue를 사용하면 반복문의 시작점으로 돌아가게 된다.
	*/

	int iNumber = 0;
	int i = 0;
	//전위 ++i를 사용합시다!
	for (i = 0; i < 10; ++i)
	{
		std::cout << "iNumber = " << ++iNumber << std::endl;
	}

	//시작 조건 생략할때
	for (; i < 10; ++i)
	{
		iNumber++;
	}

	std::cout << iNumber << std::endl;

	i = 0;
	//for에 무한루프를 만드는 방법
	//이 때는 break를 만나지 않는한 나가지 않는다.
	for (; ;)
	{

		++i;
		//if (i == 20) break;
		if (i == 20)
		{
			break;
		}
		std::cout << i << std::endl;

	}

	//for문을 이용하여 구구단 2단
	for (int i = 1; i < 10; ++i)
	{
		std::cout << "2 * " << i << " = " << i * 2 << std::endl;
	}

	system("cls");

	//이중for문 : for문 안에 또 다른 for문이 들어가는 형태이다.
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			std::cout << "i : " << i << " j :" << j << std::endl;
		}
	}
	system("cls");
	for (int i = 0; i < 10; ++i)
	{
		if (i == 8)
			continue;

		for (int j = 0; j < 10; ++j)
		{
			std::cout << "i : " << i << " j :" << j << std::endl;
		}
	}

	system("cls");

	//구구단 2 ~ 9단 까지 출력해보자.
	for (int i = 2; i < 10; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			if (j == 1)
				std::cout << i << "단: ";

			std::cout << i << "*" << j << "=" << i * j << "\t";
		}

		std::cout << std::endl;
	}


	return 0;
}