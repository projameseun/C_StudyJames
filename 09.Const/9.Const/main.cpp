#include <iostream>

#define ASPECT_RATIO 1.6533



/*
	const(상수)
	상수란? 수식에서 변하지 않는 값
	컴퓨터에서 말하는 상수는 변수에 초기화를 하게 되면 한번 그 정해진 값을 절대 바꿀수 없다.
	c++에서는 정의를 내리는 define대신 const가 바람직하다.
	
	define은 메모리에 할당되지 않는다
	const는 메모리에 할당된다.

	define 문제점
	우리에겐 ASPECT_RATIO가 기호식 이름으 보이지만 컴파일러에게 넘어 가기 전에 선행 처리자(컴파일 이전의 처리를 의미한다)가 1.653으로 모두 바꿔버리기 때문에 
	컴파일러가 쓰는 기호 테이블에 들어가지 않게 된다. 따라서 다음과 같은 문제들이 발생한다.
	나중에 프로그래밍이 거대한대 혹시나 컴파일이 1.6533이라는 오류를 범했어 이걸 과연찾을수잇을까?
	물론내가 만든건 상관없겠지만 다른 사람이 만든 프로그램에 오류라면 찾기 쉽지 않을것이다 그래서 
	우린 const를 쓰는게 바람직하다 혹여나 define을 사용할거라면 신중하게 써야 된다는 것이다.

*/

int main()
{
	int a = 0;

	float fNumber  = 1.6533;

	fNumber = 1.6533;


	//const float ASPECT_RATIO 1.653;

	//변수의 const
	
	//const int num = 1;
	//num = 2;

	//첫 번째, const 위치가 맨 앞에 있으면서 포인터 변수가 가리키는 값에 대하여 상수화를 시키는 경우입니다.
	int num = 1;
	const int* ptr = &num; // *ptr을 상수화

	//*ptr = 2; // Compile Error
	num = 2;  // Pass

	//두 번째, const 위치가 type과 변수 이름 사이에 있으면서 포인터 변수 자체를 상수화 시키는 경우입니다.
	int num1 = 1;
	int num2 = 2;
	int* const ptr2 = &num1; // ptr을 상수화

	//ptr2 = &num2; // Compile Error
	*ptr2 = 10;



	return 0;
}