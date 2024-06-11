#include <iostream>

void Func(int* a)
{
	*a = 2000;
}

void Func(int a)
{
	a = 2000;
}

int main()
{
	int iNum = 0;
	int* pNum = nullptr;

	pNum = &iNum;

	//포인터의크기
	//플랫폼 환경에 따라 다르다
	std::cout << sizeof(pNum) << std::endl;

	//포인터의 연산
	//포인터는 덧셈과 뺄샘 2가지를 제공한다
	//만약에 포인터 변수에 +1을 하게되면 메모리주소가 1000번지 라고 가정할때
	//1001이 되는게 아니라 그 해당 자료형 만큼 더해진다.
	//예를들어 int면 int는 4byte이니까 1004가 되는것이다.


	pNum += 1;
	//pNum = pNum + 1;

	/*
		포인터 배열
		배열명은 포인터다 배열명은 해당 배열이 시작하는 첫번째 메모리주소이다.
		그렇게 때문에 포인터변수에 배열의 시작 메모리 주소를 저장하고 인덱스로 접근할수 있다.
		여기서 말하는 index는 방으로 생각하면 쉽다.

		배열의특징
		1.연속적으로 메모리가 만들어진다.
		2.배열명은 포인터다 배열명은 해당 배열의 첫번째 주소이다.

	*/

	int iArr[100] = {};

	std::cout << iArr << std::endl;

	for (int i = 0; i < 100; ++i)
	{
		iArr[i] = i + 1;
	}

	std::cout << *(iArr + 1) << std::endl;

	*(iArr + 0) = 30;	//iArr[0] = 30;
	*(iArr + 3) = 500;	//iArr[3] = 500;


	system("cls");

	pNum = iArr;

	int iSize = 0;

	iSize = sizeof(iArr) / sizeof(int);

	/*for (int i = 0; i < iSize; ++i)
	{
		std::cout << iArr[i] << std::endl;
	}*/

	//for (int i = 0; i < iSize; ++i)
	//{
	//	std::cout << *(pNum + i) << std::endl;
	//}

	* (pNum + 5) = 10000;

	for (int i = 0; i < iSize; ++i)
	{
		std::cout << iArr[i] << std::endl;
	}


	int a = 200;

	int b = 200;

	Func(&a);
	Func(b);

	std::cout << a << std::endl;

	std::cout << b << std::endl;


	return 0;
}