#include <iostream>

void Func()
{
	int iNum = 200;
	
	short* sPtr = nullptr;

	
}

struct MyStruct
{
	int a;
	int b;

public:
	void Func()
	{
		std::cout << "test" << std::endl;
	}
};

int main()
{
	/*
		void(무효의)
		1.함수 반환 형식으로 사용되는 경우 함수가 값을 반환 하지 않도록 지정한다.
		2.void* 다른 형식으로 캐스팅이 되지 않는한 역참조를 할수없다.
		void*는 자료형이 정해지지 않은 특성때문에 어떤 자료형이든 저장이 가능하다.
		그런데 얼마만큼의 크기를 읽어야될지를 알수가 없어서 역참조가 불가능하다.
		또한 주소연산자도 불가능하다.
		
	*/

	int* ptr = nullptr;

	void* vPtr = nullptr;

	int a = 0;
	short b = 0;
	float f = 0.f;
	double d = 0.;

	

	vPtr = &a;
	vPtr = &b;
	vPtr = &f;
	vPtr = &d;

	//*vPtr = 300;
	//vPtr + 1 

	//std::cout << sizeof(vPtr) << std::endl;

	vPtr = &a;

	//강제 형변환을 사용해서 넣는법
	*((int*)vPtr) = 100;

	std::cout << *((int*)vPtr) << std::endl;
	//위처럼 내가 강제 형변환을 해서 어떤 자료형의 크기를 갖고 있는지 직접 넣어줘서 알려주게되면
	//해당 주소에 접근했을때 그 만큼의 데이터를 읽어들이기 때문에 역참조를 할수 있다.


	return 0;
}