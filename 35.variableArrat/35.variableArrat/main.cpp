#include <iostream>
#include "Array.h"
#include <time.h>

#define TEsta 100


struct  CFunction
{

public:
	void Func1()
	{
		std::cout << "Func1" << std::endl;
	}
	void Func2()
	{
		std::cout << "Func2" << std::endl;
	}
	void Func3()
	{
		std::cout << "Func3" << std::endl;
	}
	void Func4()
	{
		std::cout << "Func4" << std::endl;
	}
	void Func5()
	{
		std::cout << "Func5" << std::endl;
	}

	int Add(int a, int b)
	{
		std::cout << "Add " << std::endl;
		return a + b;
	}

};

void BubbleSort(int* _pData, int Count)
{
	int iTemp = 0;

	for (int i = 0; i < Count -1; ++i)
	{
		for (int j = i + 1; j < Count; ++j)
		{
			if (_pData[i] > _pData[j])
			{
				iTemp = _pData[i];
				_pData[i] = _pData[j];
				_pData[j] = iTemp;
			}

		}
	}
}



//함수포인터 
//함수의 주소를 가지고있는 것을 말한다
void OutPut()
{
	std::cout << "OutPut" << std::endl;
}

void Test()
{
	std::cout << "Test " << std::endl;
}

int Add(int a, int b)
{
	return a + 10;
}

int main()
{
	//가변 배열
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand(static_cast<unsigned int>(time(NULL)));

	//int TEsta = 100;
	int Array[TEsta] = {};

	//함수포인터
	void(*pFunc)() = OutPut;	
	void(*pFunctest)() = nullptr;

	int(*pAddFunc)(int, int) = Add;

	pFunc();

	pFunctest = Test;

	pAddFunc(10, 10);

	void(*pSortFunc)(int*, int) = BubbleSort;

	void(CFunction:: * pFunc1)();

	pFunc1 = &CFunction::Func1;
	
	CFunction func1, func2, func3;
	
	(func1.*pFunc1)();


	void(CFunction:: * pFuncArray[10])();
	
	pFuncArray[0] = &CFunction::Func1;
	pFuncArray[1] = &CFunction::Func2;
	pFuncArray[2] = &CFunction::Func3;

	(func1.*pFuncArray[0])();
	(func1.*pFuncArray[1])();
	(func1.*pFuncArray[2])();


	


	FArray arr;
	InitArr(&arr);

	

	for (int i = 0; i < 10; ++i)
	{
		int iRand = rand() % 100 + 1;
		
		PushBack(&arr, iRand);
		
	}
		



	//for (int i = 0; i < 10; ++i)
	//{
	//	PushBack(&arr, i);
	//}
	// 
	
	//정렬
	//&BubbleSort
	Sort(&arr, pSortFunc);

	for (int i = 0; i < arr.iSize; ++i)
	{
		std::cout << arr.pData[i] << std::endl;
	}


	//Reallcate(&arr);

	DestroyArr(&arr);

	return 0;
}