#include <iostream>

int main()
{
	
		//operator 연산자
		//+,-,*,/,%(모듈러스)
		
	std::cout << "10 + 5 = " << (10 + 5) << std::endl;
	std::cout << "10 - 5 = " << (10 - 5) << std::endl;
	std::cout << "10 * 5 = " << (10 * 5) << std::endl;
	std::cout << "10 / 5 = " << (10 / 5) << std::endl;
	std::cout << "10 % 5 = " << (10 % 5) << std::endl;

	//모듈러스 연산자는 a를 b로 나누었을때 몫을 제외한 나머지를 구해준다.
	//10 % 5 = 0; 이 되는 것이다.
	//모듈러스 연산자를 이용하면 2로 나누었을때 나머지가 0되면 짝수이다 짝수를 뺀 나머지는 홀수이다.

	//연산자 축약형
	//+=,-=,*=,^= 등 연산자들은 축약해서 이용할수 있다.

	int a = 0;
	
	//a = a + 1;  //축약전
	a += 1;  //축약
	
	std::cout << "a = " << a << std::endl;

	//증감 연산자
	//++,--
	//전위 후위

	int data = 0;
	data++; //후위
	++data; //전위

	a = 0;

	int iNumber = 100;
	int iNumber2 = 200;

	iNumber += a++; // iNumber = iNumber + a++;

	//iNumber += ++a; 


	std::cout << "iNumber = " << iNumber << std::endl; 
	std::cout << "iNumber2 =" << iNumber2 << std::endl;

	std::cout << "data =" << data << std::endl;

	//전위연산자는 변수의 값을 먼저 증가,감소를 시킨후에 그 값을 반환한다.
	//후위 연산자는 말 그대로 값을 먼저 넣고 더 한다는 의미이다.
	//증감 연산자는 단독을 사용할때 큰 차이가 없지만 변수를 넣었을때는 얘기가 다르다
	//연산자 우선순위에 의해서 대입연산자가 먼저 일어나기 때문이다.
	//그래서 후위 와 전위를 변수에 넣었을때 분명한 차이가 있다.

	//전위연산자는 l-value , 후위연산자는 r-value이다
	//l-value: 대입연산자(=)의 왼쪽에 올수 있는 표현식을 가리킨다.
	//메모리에 저장된 위치를 나타내며,변경할 수 있다.
	//r-value :대입연산자(=)의 오른쪽에 올수 있는 표현식을 가리킨다.
	//값 자체를 나타내며,변경할수 없다.

	//여기서 const는 상수이면 값을 변경할수 없다 그래서 착각하는게 r-value라고 생각할수 있지만 const는 변경할수 없는 l-vaue이다
	//const 가 붙은 변수는 메모리의 위치는 가지고 있으므로 l-value이다.

	//전위 연산자 같은경우에는 정확히 얘기를해보면
	//먼저 값을 증가시키고 그 결과값을 반환한다.
	//에를들어 1.메모리에 있는 a에 직접 값을 1증시킨다.
	//		  2.그리고 a를 반환한다 
	//		  3.그 반환한값을 iNumber + 해준다 
	//        4.a자체를 반환했기때문에 이는 참조(주소)값을 가지고 있다는 뜻이 된다.

	//후위 연산자 같은경우에는 
	//전위와 다르게 추가적인게 필요하다
	//		1.먼저 iNumber에 a변수를 대입하고 값을 변화시키는게 특징이다.
	//		2.변화한 값을 연산을 먼저하고 가져오기 때문에 임시메모리가 필요하다 
	//		3.a에 1을 더하 값을 임시메모리(temp)에 저장해 놓는다
	//		4.그리고 a에(원본) 값을 iNumber에 더해준다
	//		5.근데 이때 a는 변경된값이 아니라 기존값이 들어가기때문에 절대 변겨오디면안되서 const를 반환한다 
	//		6.풀이를 해보면 iNumber = iNumber + a(원본) 이 되는거다 
	//아래에 오류가 되는 이유

	a = 0;
	
	++a = 100;
	//컴파일오류...
	//a++ = 100;  //l-value여야 된다고 나온다 이거 풀이해보면 0 = 100 이말과 같다  

	//결론
	// 둘다 증가된값을 리턴하지만 ++x는 증가된 x자신을 리턴하기 때문에 LValue인 반면에 x++은 증가된 복사본을 리턴하기 때문에 RValue다


		//논리연산자
	//!(NOT) , &&(AND) , ||(OR)
	//논리 연산자는 참/거짓 대 참/거짓을 연산하여 결과로 참/거짓이 나오게 된다.

	/*
		A		B		AND			OR
		false   false	false		false
		false	true	false		true
		true	false	false		ture
		true	true	true		true

		AND는 둘다 true일때 true이고 아니면 false이다
		OR는 둘중 하나라도 true일때 trueㅇ고 아니면 false이다.

		A		NOT
		false	true
		true	false
		NOT연산자는 반전이 된다.

		true = 1;
		false = 0;
	*/

	std::cout << "false && false = " << (false && false) << std::endl;		//0
	std::cout << "false && true = " << (false && true) << std::endl;		//0
	std::cout << "true && false = " << (true && false) << std::endl;		//0
	std::cout << "true && true = " << (true && true) << std::endl;			//1

	std::cout << "false || false = " << (false || false) << std::endl;		//0
	std::cout << "false || true = " << (false || true) << std::endl;		//1
	std::cout << "true || false = " << (true || false) << std::endl;		//1
	std::cout << "true || true = " << (true || true) << std::endl;			//1

	std::cout << "!false = " << !false << std::endl;						//1
	std::cout << "!true = " << !true << std::endl;							//0

	return 0;
}