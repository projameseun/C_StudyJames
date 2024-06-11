#include <iostream>

//오버로딩예시
//void Func()
//{
//	std::cout << "Fun 호출" << std::endl;
//}
//
//void Func(int a,int b)
//{
//	std::cout << "Fun2 호출" << std::endl;
//}
//
//int Func(float a, float b)
//{
//	std::cout << "Fun3 호출" << std::endl;
//	return 0;
//}
//
//void Func(float a, int b)
//{
//	std::cout << "Fun4 호출" << std::endl;
//}
//
//void Func(int a)
//{
//	std::cout << "Fun5 호출" << std::endl;
//}
//
//

void Func(int a)
{
	std::cout << "int 호출" << std::endl;
}

void Func(int* a)
{
	std::cout << "int* 호출" << std::endl;
}

void Func(std::nullptr_t ptr)
{
	std::cout << "nullptr 호출 " << std::endl;


}




int main()
{
	/*
		NULL,nullptr 사이에 몇가지 차이점...

		타입:nullptr은 c++11부터 도입된 특별한 키워드이다
		이에반해 NULL은 C언어에서 사용되던 매크로로, 정수 0으로 평가되는 표현식입니다.
		따라서 nullptr은 포인터의 값이 없을 나타내는 엄격한 표현이며, 타입정보를 가지고 있다.

		nullptr은 타입의 객체를 초기화할때 해당 포인터 타입이 컴파일러에 의해 명확하게 결정되기 때문에
		타입의 안정성이 보장 됩니다.

		NULL은 매크로이고 0으로 정의되어 있습니다
		NULL은 정수 0으로 해석될수 있다
		NULL을 사용하여 포인터를 초기화할때 타입 불일치에 대한 오류가
		발생하지 않을수 있어서 타입의 안정성이 보장되지 않는다.


	*/
	int a = 0;
	int* ptr = nullptr;


	Func(ptr);
	Func(NULL);
	Func(nullptr);


	int iNum = 0;

	a = NULL;

	Func(0);
	Func((int*)0);

	system("cls");

	//NULL은 모호하다.
	std::cout << "NULL,nullptr 비교 " << std::endl;

	int* ptr1 = NULL;
	int* ptr2 = nullptr;

	if (ptr1 == NULL)
	{
		std::cout << "NULL == NULL" << std::endl;
	}
	if (ptr2 == NULL)
	{
		std::cout << "nullptr == NULL" << std::endl;
	}
	if (ptr1 == nullptr)
	{
		std::cout << "NULL == nullptr" << std::endl;
	}
	if (ptr2 == nullptr)
	{
		std::cout << "nullptr == nullptr" << std::endl;
	}
	if (ptr1 == ptr2)
	{
		std::cout << "NULL== nullptr" << std::endl;
	}

	//위에 출력을 하게되면 모두출력이 된다.
	//NULL은 0이기도 하지만 nullptr과 비교 했을때 true가 나온다는 사실을 알수 있고
	//NULL은 상황에따라 모호하게 변동된다.
	//어떨때는 int타입이랑 비교를 하고 또 어떨때는 포인터0으로 null을 가리키는 모호한 상황이 나온다.
	//그래서 포인터를 사용할때 초기화를 할때는 NULL이 아닌 nullptr을 사용하는 것이 맞다.
	//그리고 nullptr은 사용하게 되면 사용자가 이거는 포인터를 초기화 한것이라고 바로알수있어서 가독성도 좋다.


	return 0;
}