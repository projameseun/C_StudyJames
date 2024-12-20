#include <iostream>
#include <bitset>

/*
	변수(Variable):메모리(램)에 공간을 만들고 해당 공간에 값을 저장해서 사용하게 해줄수 있는 기능.
	
	자료형(Datay Type)
	정수형:int(4),char(1),short(2),long(4)....
	실수형:float(4),double(8)....

	int a = 0;

	int는 정수
	int 4byte크기를 갖고 있다.
	변수는 고정이 아니다
	0 : 값이라고 부른다.
	= 대입연산자라고 부른다
	int 자료형이라고 부른다
	a 변수라고 부른다.

	컴퓨터의 기본크기 단위

	1bit 는 0,1 두가지를 표현할수 있고 컴퓨터의 가장 작은 단위이다.
	1byte = 8bit

	2의10승씩
	1Kbyte = 1024byte
	1MByte = 1024Kybte
	1GByte = 1024MByte
	1TBbyte = 1024GBbyte 

	int에 4byte를 bit로 표현하면 32bit이다.




*/


int main()
{
	int iNumber = 0;
	//컴파일 과정에서 (변수 ====> 메모리주소(ffbxxxx)) 이런식으로 우리는 iNubmer라고 쓰지만 컴퓨터는 본인이 알아들을수 있게 컴파일과정에서 변환한다.

	//char는 1Byte이면서 8bit이다.  1bit(0,1)로 두가지를 표현 할수 있기 때문에 2bit는 2의2승 4가지를 표현 할수 있다.
	//그러므로 8bit 2의8승 256가지를 표현할수 있다.
	unsigned char ch = 0;

	ch = 48; //아스키코드에 의해서 숫자 0 이나온다
	ch = '48'; //단일문자를 표현할수잇는데 두개의 문자가 있기때문에 컴파일 오류를 발생시킬수 있고 4,또는 8이나온다 정확히할려면 따로 써야된다.

	//아스키코드란 
	//컴퓨터에서 문자를 표현하가위해 사용되는 표준코드이다.

	
	ch = 256;  //비트가 모두 11111111(2진수) 일때가 255일거야 char는 1byte니까 그럼여기서 +1을 한 256은 0이될거야 나머지는 다 0이채워지고 0 0 0 0 0 0 0 0 이꼴이되겟지
	ch = -1;  //컴퓨터입장에서는 11111111 으로 보기때문에 255
	
	// -128 ~ 0 ~127 까지
	signed char ch2 = 0;
	 ch2 = 255;

	 //오버플로우(OverFlow)
	 //변수가 표현할수 있는 최대의 범위를 넘어가는 경우를 오버플로우 라고 한다.
	 
	 //언더플로우(UnderFlow)
	 //변수가 표현할수 있는 최소의 범위를 넘어가는 경우를 언더플로우 라고 한다.
	 
	 //수학에서는 정수를 음수 양수 0 으로 구분하지만 컴퓨터에서는 하나의 비트에 2가지만 표현 할수 있다.
	 //양수만 사용하기 위해서는 unsigned를 붙여줘야된다.
	 //실제로 우리가 자료형을 그냥 쓴 부분은 앞에 signed


	 // 0 0 0 0  0 0 0 1
	 // 1 1 1 1  1 1 1 1     -1 인데 signed에서는 그렇다ㅡㄴㄴ거지...

	 //음수표현..
	 //앞에 비트를 부호비트 MSB
	 //컴퓨터에서는 마이너를 표현할때는 
	 //1byte의 기준으로 살펴보면 8개의 모든 숫자를 저장하는게 아니라
	 //7개만 저장되고 가장왼쪽 비트1개는 음수 또는 양수 인지 구별하게 된다.
	 //여기에서 양수와 음수를 구별할수 있는 비트를 부호비트 (MSB)라고한다.

	 //MSB(Most Significant Bit) 최상위비트
	 //LSB(Least Significant Bit) 최하위비트

	 //LSB를 이용해서 짝,홀를 구별 할수 있다.
	 //2진수로 생각했을때 
	//=====================================
	 //0 -----> 0000	1 -----> 0001	2 -----> 0010	3 -----> 0011
	 //4 -----> 0100	5 -----> 0101	6 -----> 0110	7 -----> 0111  8 -----> 1000

	 //LSB는 0,1에 따라서 짝수 홀수를 알아 낼수 있다.
	 //이걸 and연산의 특성을 사용하면 짝수인지 홀수인지 알아낼수있다.
	 //and연산 -> 두숫자를 더했을때 모두 1일때 1 // 하나라도 0이면 0 

	 //결론 어떤수를1과  and연산을 시켜서 결과가 0 이면 짝수 1이면 홀수이다.
	
	 //0011
	 //0001  &
	 //----
	 //0001  
	 //홀수이다.

	 /*
		컴퓨터에서 말하는 음수란
		20 - 10 = 10 말할수 있지만 20 + (-10) = 10 이라고 말할수 있다.
		컴퓨터에서는 뺀다는 개념이 존재하지 않는다 무조건 더 한다는 개념이다.

		★★★★★★위에서 msb가 1일때 음수 0일때 양수라고 했을때 이때 중요한점이 하나있다
		8비트기준에서
		1000 0001 -> 이건 -1이냐는 라는 말인데 절대 아니라는걸 알아야 된다.
		
		======위에 말 증명 ======
		  그리고 signed 8비트 기준으로
		  0111 1111 ---> 127 
		  1000 0001 ---> -127 2의 보수를사용해서          2의보수는 아주간단 1은 0 ,0은1 그리고 컴퓨터에서 음수를 만드는방법은 2의보수를 한다음에 +1을 하면된다.
		======================
		1 0000 0000

		보시다시피 1000 0001 이 나왔지만 singned에서는 -127이라는거다 -1이 아니고
		

		0000	0001 -> 1
		1111	1111 -> -1
		===============
		1 0000	0000

		즉 위에 증명으로 인해

		singend char c = 255;	-1  비트:1111 1111
		unsigned char c = 255;  255 비트 1111 1111

		//비트단위로 보기
		//bitset헤더파일필요
		//std::cout << "c4:" << std::bitset<8>(c4) << std::endl;
		//std::cout << "c5:" << std::bitset<8>(c5) << std::endl;


		★★★★★★둘의 메모리 비트값은 똑같다 ★★★★★★★★★★★
		255라는 숫자는 똑같이 1111 1111 을 채워져있다
		근데 부호가 있는 마이너스를 채용하면 비트는 최상위 비트 msb를 부호용도로 사용하고 있다
		결국은 어떤 관점으로 보느냐에 따라 다른것이다.
		usigned 냐 signed 냐 에 따라서 
		
		음수를 조금더 쉽게 찾는법
		보수 --> 보충해주는 수

		1에 대한 10의보수는 9
		4에 대한 15의보수는 11
		

		2의보수법을 이용하면 음수를 구할수 있따
		2의보수법
		대응 되는 양수의 부호를 반전시킨다(1의보수), 1의 보수후에 +1을 더한다(2의보수)

		0 0 0 0 0 0 1 0 =====>2
		1 1 1 1 1 1 0 1 =====>반전을 시킨다
						+1을 해준다
	   ==============================
	   1 1 1 1 1 1 1 0 --->2의보수값 -2가 된다.
	   
		
		실수 
		정수형 실수형의 자료형을 나눈것은 처리하는 방식 완전다르다.
		정수랑 실수는 표현하는 메모리방식 자체가 다르다.
		컴퓨터에서는 실수는 부동소수점을 사용한다.

		float fNumber = 3.f;

		0과 1로만 실수를 과현 표현할수있을까?
		예를 들어 0.1 0.5 .이런걸 표현할수 있을까?

		int iNumber = 4 + 4.0f;  이건 자료형이 인트이기때문에 실수를 정수표현일때 로 바뀌면서 정수 8이나올것이다.
		
		부동소수점 설명만

		변수의 타입
		타입		|		크기		|		표현 종류		|	표현 범위												|			unsigned	|
		char	|	1byte		|		문자				|		-128~127											|		0 ~ 255
		bool	|	1byte		|		참/거짓			|		false(0),true(1)									|		
		short	|	2byte		|		정수				|		-32,768~32,767										|		0 ~ 65,535
		int		|	4byte		|		정수				|		-2,147,483,648 ~ 2,147,483,647						|		0~4,294,967,295
		__int64	|	8yte		|		정수				|-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807		|
		float	|	4byte		|		실수				|															|
		double	|	8byte		|		실수				|

		bool은 0은 false 
		0아아닌 모든수는 true

		bool bTest = -5;
		bool bTrue = 0;
		std::cout << bTest << std::endl;
		std::cout << bTrue << std::endl;

		short 타입 변수를 사용했을때 32768을 저장하면 이 값은 short의 표현범위를 벗어나서(over flow)-32768이 저장 된다.
		short sTest = 32768;
		std::cout << sTest << std::endl;
		int iNumber = 244444;
		__int64 iBossHp = 29999999;

		float fNumber2 = 5.6f;
		double fNumber3 = 55.5;

		변수의 특징
		카멜 표기법 myName, fireMagic , bossRica , totalNumber
		첫글자는 대문자로 적되 , 맨앞에 오는 글자는 소문자로 표기하는 방식
		낙타의 혹처럼 보인다고 카멜 표기법이라고 부른다.

		헝가리언 표기법 자료형을 확인하기 어려워서 변수이름을 정할때 앞에 변수의 특성을 알수 있게 접두어를 붙인다.
		i_data, fNumber , sh_Number,strName 등
		변수를 만들때는 변수이름만보고 자료형을 알수 있게 만드는것이 가장 좋다.

	 */

	
	

	
	return 0;
}