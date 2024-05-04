#include <iostream>
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

	//char는 1Byte이면서 8bit이다.  1bit(0,1)로 두가지를 표현 할수 있기때문에 2bit는 2의2승 4가지를 표현할수 있다.
	//그러므로 8bit 2의8승 256가지를 표현할수 있다.
	char ch = 48;  //char는 1byte 양의정수만 포함하면 0까지해서 255까지 가능하다 
	char ch2 = '48'; //작은 따옴표는 한 문자를 표현
	std::cout << ch << std::endl;
	std::cout << ch2 << std::endl;
	

	return 0;
}