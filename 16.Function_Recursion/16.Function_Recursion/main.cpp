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

//팩토리얼 재귀함수
int Factorial_Re(int _Count)
{
	if (_Count == 1)
	{
		return 1;
	}
	return _Count * Factorial_Re(_Count - 1);
}


//피보나치수열
//1 1 2 3 5 8 13 21 34 55 89
int Fibonacci(int _Num)
{
	int iPreNum = 1;
	int iPreNum2 = 1;

	int iResult = 0;

	if (_Num == 2 || _Num == 1)
	{
		return 1;
	}

	for (int i = 0; i < _Num - 2; ++i)
	{
		iResult = iPreNum + iPreNum2;

		//순서를 잘못하면 이상한 값이 들어가게 된다.
		//iPreNum2 = iResult;
		//iPreNum = iPreNum2;

		iPreNum = iPreNum2;
		iPreNum2 = iResult;
	}




	return iResult;
}

//피보나치수열 재귀함수
int Fibonacci_Re(int _Num)
{
	if (_Num == 2 || _Num == 1)
	{
		return 1;
	}
	//1 1 2 3 5 8 13 21 34 55 89
	return Fibonacci_Re(_Num - 1) + Fibonacci_Re(_Num - 2);
}


//꼬리재귀
//최적화 기능중 하나이다 쓸려면 플랫폼에 맞게 설정을 해줘야된다.
//재귀함수는 스택에 쌓인걸 반환할때 추가 연산을 하지만 꼬리재귀는 하지않는다

int FactorialTraill(int n, int acc) // acc : accumulator의 약자
{
	if (n == 1)
	{
		return acc;
	}

	return FactorialTraill(n - 1, acc * n); //일반 재귀에서의 n* Factorial(n - 1)와 달리 반환값에서 추가 연산을 필요로 하지않음
}

int FactorialTest(int n)
{
	return FactorialTraill(n, 1);
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


	//팩토리얼 재귀함수
	iValue = Factorial_Re(3);
	std::cout << "FactorialRe:" << iValue << std::endl;
	//팩토리얼 재귀함수
	
	//피보나치수열
	//1 1 2 3 5 8 13 21 34 55 89
	iValue = Fibonacci(10);
	std::cout << "Fibonacci:" << iValue << std::endl;
	//피보나치수열


	//피보나치수열 재귀함수
	iValue = Fibonacci_Re(5);
	std::cout << "Fibonacci_Re:" << iValue << std::endl;
	//피보나치수열 재귀함수

	//꼬리재귀
	iValue = FactorialTest(4);
	std::cout << "FactorialTraill_Re:" << iValue << std::endl;

	//꼬리재귀 설명잘한거 https://bozeury.tistory.com/entry/%EA%BC%AC%EB%A6%AC-%EC%9E%AC%EA%B7%80-%EC%B5%9C%EC%A0%81%ED%99%94Tail-Recursion


	return 0;
}