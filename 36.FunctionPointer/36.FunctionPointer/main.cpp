#include <iostream>

void OutPut()
{
	std::cout << "OutPut" << std::endl;
}

void OutPut2()
{
	std::cout << "OutPut2" << std::endl;
}	

int Sum(int a, int b)
{
	return a + b;
}

void SetFunctionPointer(void (*pFunc)())
{
	pFunc();
}


int main()
{
	/*
		함수포인터 (Function Pointer)
		함수도 다른 변수들 처럼 주소를 가지고 있는데 
		이 함수의 주소를 포인터 변수에 저장해서 사용하는 걸 
		함수 포인터라고 한다.
		반환타입 (*변수명)(인자타입들);의 형태로 구성된다 .1
	*/

	int a = 100;
	int* ptr = &a;	//포인터

	//함수 포인터
	void (*pFuncOutput)() = OutPut;
	int(*pFuncSum)(int, int) = Sum;	

	pFuncOutput();	
	std::cout << pFuncSum(10, 20) << std::endl;


	//pFuncOutput = Sum; 다른 형태의함수는 불가능
	
	pFuncOutput = OutPut2;

	pFuncOutput();

	std::cout << "Sum Address : " << &pFuncSum << std::endl;
	std::cout << "pFuncOutput Address : " << &pFuncOutput << std::endl;


	std::cout << "Sum Value : " << pFuncSum << std::endl;
	std::cout << "pFuncOutput Value : " << pFuncOutput << std::endl;



	SetFunctionPointer(OutPut);


	return 0;
}