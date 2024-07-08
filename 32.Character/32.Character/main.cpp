#include <iostream>

int main()
{
	//문자

	char c = 49;
	bool b = 49;


	std::cout << c << std::endl;
	std::cout << b << std::endl;

	//2byte 문자를 표현하는 와이드문자.
	//L접두사로 붙이면 와이드 문자를 나타낼수있다.
	wchar_t wc = 49; 
	
	c = '1';	//문자 1을 넣은거다
	c = 1;		//정수 1을 넣은거다.
	
	//문자열 
	"178";
	/*
		178문자열은 메모리상에서
		49에 해당하는 아스키코드 표에 값이 들어가고
		55에 해당하는 아스키코드 표에 값이 들어가고
		56에 해당하는 아스키코드 표에 값이 들어가 있게 된다.
		이 모든 값들이 출력해서 되어 있을거다
		ex)1,7,8 그리고 10진수 숫자들이 2진수로 실제로 되어있을거다.
		00110001 00110111 00111000
	*/

	//문자열의 끝에는 반드시 \0가 들어가 있다.
	//컴퓨터 입장에서는 끝을 알수없기때문에 그리고 이친구가 문자열인지 알수없기때문에 그것을 알기위해서 반드시 사용된다.

	//와이드문자
	
	wc = L't'; //2바이트 메모리를 갖게 된다.

	//문자열 배열 

	char stChar[25] = "abcdefg";
	wchar_t stwChar[25] = L"abcdefg";	//L을붙여줘야 된다. 

	//멀티바이트,와이드 바이트
	
	//멀티바이트란?
	//하나 이상의 바이트로 표현되는 방식을 말한다.

	
	char exString[25] = "abcd안녕";

	//위에 문자열 배열은 영어같은 경우에는 1바이트로 표현이 되지만 한글은 2바이트로 표현이 된다.
	//이렇게 상황에 따라서 1바이트 2바이트가 왔다갔다 하는 방식이다.
	// 
	//멀티바이트의 문제점 
	int iLen  = strlen(exString);
	std::cout << iLen << std::endl;
	//멀티바이트의 문제점 

	//strlen함수는 문자열의 갯수를 반환해주는 함수이다.
	//위에 exString은총 6글자이지만 8을 출력하게 되는데 한글은 2바이트를 사용해서 2글자라고 생각하기 때문이다.
	//그래서 모든 바이트를 통일 시켜야된다.
	wchar_t exString2[25] = L"abcd안녕";
	//와이드바이트
	 iLen = wcslen(exString2);
	 std::cout << iLen << std::endl;


	 wchar_t wChar[25] = L"abcdef";
	 const wchar_t* wpChar = L"Hellow";

	 wChar[0] = 'k';
	 *(wChar + 1) = 'f';
	 /*
		 *(wChar + 1) = 'f'; 위에 wChar배열은 data영역에 저장되어 있다.
		 ★하지만 "Hellow"는 문자열은 상수이고 상수는 코드영역이다.
		 둘은 비슷하지만 전혀 다르다.
		 
		 첫번재는 배열이고
		 두번째는 wpChar가 Hellow의 주소를 가리키는 포인터이다.
		 그리고 Hellow문자열은 리터럴이고 코드영역에서 존재한다
		 그러기때문에 const를 안붙이게되면 나중 에프로그램을 실행할때 문제가 생길수 있다(수정하게되면)
		 그래서 미리 const를 붙여야 된다.
		 
	
	 */

	 wchar_t cTest[25] = L"abc";
	 wchar_t* pTest = cTest;

	 *(pTest + 1) = 'k';

	 std::cout << *(pTest) << std::endl;

	 int a = 0;
	 





	return 0;
}