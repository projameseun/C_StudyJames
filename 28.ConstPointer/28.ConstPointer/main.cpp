#include <iostream>

void Func(const int* ptr)
{
	int iNum = *ptr;
	
	//*ptr = 200;

	//강제로 형변환을 통해서 값을 변경할수 있다.
	int* pInt = (int*)ptr;
	*pInt = 10000;
}

int main()
{

	int a = 0;

	int b = 0;

	//const Pointer 가리키는걸 상수
	const int* ptr = &a;

	//*ptr = 100;

	//pointer const 자기자신 상수
	int* const ptrConst = &b;

	*ptrConst = 300;

	//ptrConst = &a;

	//둘다 상수
	const int* const pConstIntConst = nullptr;

	
	//*pConstIntConst = 500;
	//pConstIntConst = &b;
	
	//안좋은 방법...
	//int const* ptr3 = nullptr;

	{
		int a = 0;
		
		const int* pInt = &a;

		a = 300;

		std::cout << *pInt << std::endl;
	}

	a = 100;

	Func(&a);

	std::cout << "a = " << a << std::endl;
	

	return 0;
}