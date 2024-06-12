#include <iostream>


//void swap(int a, int b)
//{
//	int iTemp = 0;
//
//	iTemp = a; 
//	a = b;
//	b = iTemp;
//}

void swap(int* a ,int* b)
{
	int iTemp = 0;

	iTemp = *a;
	*a = *b;
	*b = iTemp;
}

void swap(int& a, int& b)
{
	int iTemp = 0;

	iTemp = a;
	a = b;
	b = iTemp;
}





int main()
{
	//Call by Value Call by Reference
	//call by value는 값을 인자로 전달하는 함수의 호출방식
	//값이 복사되서 전달되기때문에 함수 내에서 값을 변경해도 원본값으 변경되지 않는다.

	//Reference 는 주소 값을 인자로 전달하는 함수의 호출방식 
	//함수가 인자로 전달되는 값이 변수의 주소이므로, 함수 내에서 변수의 값을 변경하면 해당 주소에 저장된 값이 변경이 된다.


	int iNum1 = 50;
	int iNum2 = 100;

	std::cout << "======== 스왑 하기전 =======" << std::endl;
	std::cout << "iNum1 = " << iNum1 << std::endl;
	std::cout << "iNum2 = " << iNum2 << std::endl;


	//swap(50, 100);
	//swap(&iNum1, &iNum2); 
	swap(iNum1, iNum2);	//reference방식

	std::cout << "======== 스왑후 =======" << std::endl;
	std::cout << "iNum1 = " << iNum1 << std::endl;
	std::cout << "iNum2 = " << iNum2 << std::endl;


	int iNum3 = 200;

	
	//레퍼런스와 포인터는 둘다 c++에서 사용되지만 비슷하면서 둘은 차이가 있다
	//레퍼런스 
	/*
		1.레퍼런스는 선언 시 반드시 초기화가 되어야 한다.
		2.레퍼런스는 초기화 한후 다른 변수를 가르킬수 없다.
		3.레퍼런스를 통해 원본변수에 접근해서 변경할수 있다 포인터와 달리 주소 연산자를 사용할 필요가없다.
		4.NULL값이 없다. 레퍼런스는 NULL값을 가질수없다 항상 유효한 변수를 가르켜야된다는 말이다 .

		포인터는 NULL,nullptr을 가질수 있는데 이는 포인터가 어떤 유효한 변수를 가리키지 않는다는것을 의미한다.
	
	*/

	//int& ref = nullptr; 불가능
	
	int a = 100;
	int b = 200;
	int c = 300;



	int& ref = a;

	ref = b; // ref가 a를 참조하고 있기 때문에 a의 값을 b로 변경

	std::cout << "&a: " << &a << std::endl;
	std::cout << "&b: " << &b << std::endl;
	std::cout << "&ref: " << &ref << std::endl;

	b = 500;


	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "ref: " << ref << std::endl;



	return 0;
}