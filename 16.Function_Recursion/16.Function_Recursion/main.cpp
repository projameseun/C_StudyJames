#include <iostream>

/*
	재귀(Recusion)함수란
	함수 안에서 자기 자신의 함수를 호출하는 방식
	디버그 할때 호출스택에 더블클릭을 하게 되면 다른쪽도 볼수 있음
	
	함수안에서 자기 함수를 계속 불러오면(재귀함수) 스택의 한계치를 도달하게 되는데
	이를 오버 플로우라고 한다.
*/


//팩토리얼 함수 for문 
int Fatorial(int _Cout)
{
	int iValue = 1;

	for (int i = 0; i < _Cout - 1; ++i)
	{
		//iValue = iValue * (i + 2);
		iValue *= (i + 2);
	}

	//이건 재귀함수가 맞는데 심각한 문제가 생긴다 스택에 계속함수 쌓여서 스택오버플로우가 생긴다.
	//Fatorial(5);

	return iValue;
}




int main()
{
	//팩토리얼을 생각 햇을때 4팩토리얼이면 곱하는 횟수가 3개이다.
	//4! = 1 x 2 x 3 x 4 곱하기가 3번 
	
	//팩토리얼 for으로 만들었을때
	int iFacNum = 4;
	int iValue = 1;

	for (int i = 0; i < iFacNum - 1; ++i)
	{
		//iValue = iValue * (i + 2);
		iValue *= (i + 2);
	}

	std::cout << "FactorialForMun  : " << iValue << std::endl;
	//팩토리얼 for문으로 만들었을때

	//팩토리얼 for문함수 
	iValue = Fatorial(5);
	std::cout << "FatorialForMunFuction : " << iValue << std::endl;

	


	return 0;
}