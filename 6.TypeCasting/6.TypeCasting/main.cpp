#include <iostream>

int main()
{
	/*
		형변환(TypeCasting)
		5가지의 종류가 있다.
		c-style cast
		
		타입캐스트 연산자 ==> static_cast,const_cast,dynamic_cast,reinterpreat_cast

		c-style cast는 숫자앞에 (자료형)을 사용한다 
	
	*/

	int a = 0;
	float b = 1.f;

	b = (float)a + 3.f;  //c 스타일캐스트 명시적 형변환

	int c = 0;

	c = 3.5f;			//c스타일캐스트 암시적 형변환


	//static_cast
	
	int iNumber = 0;
	char cNum = 0;
	float fNumber = 0.f;

	iNumber = 25;

	cNum = static_cast<char>(iNumber); //int to char
	fNumber = static_cast<float>(cNum); //char to float

	//const_cast
	//상수성을 변경할때 사용한다 포인터나 참조(레퍼런스)를 통해서 사용함
	const int constValue = 20;
	const int* ptr = &constValue;

	//*ptr = 30; 이건안되 

	int* ptr2 = const_cast<int*>(ptr);
	
	*ptr2 = 50;  //하지만 이런식으로 사용해서 ptr2를 변경하면서 constValue 값을 변경할수있다
	//하지만 출력해보면 constValue는 변경된 값으로 는 안나와 이유는 간단해 const로 상수화시켜서 컴파일에서 이미 고정시켜놓아서

	std::cout << constValue << std::endl;
	std::cout << ptr2 << std::endl;
	std::cout << ptr<< std::endl;

	//dynamic_cast 
	
	//상속관계에 있는 클래스 간에 캐스팅이 가능하나 런타임(프로그램이 실행되고 있는동안) 타입 검사를 하지 않기때문에 위험하다
	//이럴때 dynamic_cast를 사용한다 
	//다이나믹 캐스트는 상속관계가 있는경우에 사용된다.
	//변환에 실패하면 nullptr을 반환한다 
	//이걸 알려면 상속 ,업캐스팅 다운캐스팅을 이해해야 알수잇음 나중에 설명

	//reinterpreat_cast

	//서로 다른 포인터 또는 레퍼런스를 변환하는데 사용한다 
	//나중에 타입캐스트들은 자세히 설명 하겠습니다 지금배우기에는 조금 미숙함

	//암시적형변환 - 자동으로 형변환이 이루어 진다.
	//명시적형변환 - 사용자가 직접 데이터의 타입을 변경하는것이다
	//
	//암시적형변환은 Data 의 손실이 발생할수 있기때문에 문제가 될 수있다.
	//크기가 큰대서 작은거로 대입을 하게되면 데이터의 손실이 올수 있ㅇ다.그래서 확실할때만 사용하는 것이 좋다.

	int test = 0;

	return 0;
}