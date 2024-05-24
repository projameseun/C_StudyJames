#include <iostream>

/*
	함수(Function) :사용자가 원하는 코드를 모아서 기능을 만들어 줄수 있는 것을 말한다.
	예를들어서 반복되는 코드가 있다면 그것을 함수로 만들어서 필요한 곳에 이 함수를 불러서 해당코드가 작동 도리수 있게 만들어 줄수있다.
	또한 사칙연산을 함수로도 만들수있다 이와 같이 함수는 많은 기능을 포함할수 있다.

	함수문법

	반환타입(자료형) 함수명(인자 또는 매개 변수라고 부른다)
	{

	}코드블럭

	반환타입:함수가 동작을 수행하고 결과를 반환해줄수 있는 자료형을 지정한다(void,int,float등)
	
	인자는 있을수도 있고 없을수도 있다
	인자는 이 함수를 불러다 호출할때 이 함수에 넘겨주고자 하는 값이 있다면 변수를 만들어서 사용하게 해준다.
	void반환타입은 반환 할 값이 없다는 것이다.

*/


//전역변수
int gNumber;

//선언과 정의를 같이 한 경우
void IntPrint(int iPrint)
{
	
	std::cout << iPrint << std::endl;
}

int Add(int a, int b)
{
	gNumber += 10;
	return a + b;
}

int Minus(int a, int b)
{
	gNumber += 10;
	return a - b;
}

int Test2()
{
	int a = 0;
	int b = 0;

	a = 200;
	b = 245;

	int c  = a + b;

	return c;
}

void Test();  //함수선언


int main()
{
	IntPrint(10);

	int iTotal = 0;

	iTotal = Add(gNumber, 10);

	IntPrint(iTotal);

	iTotal = 0;

	iTotal = Minus(100 ,50);

	IntPrint(iTotal);

	/*
		삼항연산자
		조건 ? A: B 
		조건이 참이면 A를 반환하고 거짓이면 B를 반환한다
	*/

	int iResult = 0;

	int a = 20, b = 50;
	
	iResult = (a != b) ? a : b;
	
	IntPrint(iResult);


	Test2();

	int  test = 0;

	gNumber++;
	gNumber++;
	gNumber++;

	IntPrint(gNumber);

	/*
		지역변수:코드블럭{}안에서 선언된 변수를 말한다.
		함수의 내부나 함수의 인자들이 지역변수에 속한다.
		지역변수는 스택영역에 존재한다
		지역변수는 함수안에서만 접근이 가능하며,삼수를 벗어나면 소멸된다(메모리에서 해제된다.)
		
		전역변수:Main코드블럭 외부에서 선언한는 변수를 말한다.
		전역변수는 선언된 전역변수 아래의 어느함수에서라도 동일한 변수 접근이 가능하다.
		전역변수는 프로그램이 시작 될때 할당되고 초기화를 안하면 자동으로 0으로 초기화 한다.
		전역변수는 프로램이 실행 될 동안 메모리에서 계속 존재하다가 프로그램이 종료 될때 메모리에서 해제 된다.
	    전역변수는 data영역에 존재한다.
	
	*/


	return 0;
}


//함수정의
void Test()
{
	std::cout << " 함수의 정의입니다" << std::endl;
}