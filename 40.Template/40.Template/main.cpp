#include <iostream>
#include "CArray.h"

//오버로딩을 통해서 여러자료형에 더하기 함수기능을 만들수있는데
//만약에 이걸 하나의 함수를 통해서 자료형을 그 상황에 맞게 변경해줄수 있다면 좀더 효율적이고 기능적일거다
//이래서 나오게 된게 템플릿이다.
//템플릿의 뜻은 틀이라는 뜻을 갖고있다.
//우리가 지금 배울건 함수 템플릿이다.


//클래스 템플릿에 정의는 헤더파일에 만들어져야 된다
//이유는 컴파일러가 템플릿 인스턴스화를 제대로 처리하기 위해서 필요한 코드가 템프릿 정의와 선언 모두 포함된 헤더파일이 있어야된다.
//템플릿은 컴파일 시점이 아닌 인스턴스화 시점에 컴파일 됩니다., 즉 컴파일러는 템플릿이 사용 될때 실제로 어떤 타입이 템플릿 매개 변수로 사용될지를 알아야 된다.

//템플릿 인스턴스화
//템플릿을 구체적인 타입으로 변환하는 과정을 말한다
//템플릿은 틀,패턴 으로 실제로 사용 할때 는 이 틀을 구체적인 데이터 타입으로 채워서 사용하게 되는데 이 과정을 인스턴스화라고 부른다.

//인스턴스
//class에 소속된 개별적인 개체를 말한다
//ex) User는 클래스를 정의하고 player라는 객체를 생성하게 되면 player라는 객체는 user라는 클래스의 인스턴스가 된다.

template<typename T>
T	Add(T a, T b)
{
	return a + b;
}

//int Add(int a, int b)
//{
//	return a + b;
//}
//
//float Add(float a, float b)
//{
//	return a + b;
//}
//
//char Add(char a, char b)
//{
//	return a + b;
//}

//class를 사용해도되고 typename을 해도 상관없다 여기서 class는 우리가 지금까지배운 클래스가아니다

template<class T>
void OutPut(T a)
{
	std::cout << a << std::endl;
}

//void IntOutPut(int a)
//{
//	std::cout << a << std::endl;
//}

int main()
{
	//템플릿 
	
	int iNumber = Add<int>(10, 20);
	float fNumber = Add<float>(3.f, 3.f);
	//int iNumber = Add(10, 10);	컴파일러가 자동으로 해주고있다 하지만 명시를 우리는 명확하게 해주는게 중요한 습관중 하나다.

	OutPut<int>(iNumber);
	OutPut<float>(fNumber);
	//OutPut(iNumber);

	//CArray arr;  //템플릿이 되는순간 안된다
	CArray<int> arr;

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);

	CArray<float> arr2;

	arr2.push_back(10.4f);
	arr2.push_back(20.66f);
	arr2.push_back(30.22f);

	
	for (int i = 0; i < arr.GetCount(); ++i)
	{
		std::cout << arr.GetData()[i] << std::endl;
	}

	for (int i = 0; i < arr2.GetCount(); ++i)
	{
		std::cout << arr2.GetData()[i] << std::endl;
	}
	

	int a = 0;

	return 0;
}