#include <iostream>
#include <string>

/*
	네임스페이스 (namespace) 란
	이름 공간 이라고 부른다. std 는 namespace안에 구현되어 있다.
	네임스페이스는 변수 이름 또는 함수 이름과 같이 명칭을 사용하는 공간으로 소속을 나타낸다.
	
	c++은 같은경우에는 이름이 같으면 구분이 불가능하다. 그렇기 때문에 이름이 중복되서 충돌 되는 상황을 최대한 막아주어야한다.
	namepscae는 이름이 충돌 될경우 대비하여 소속을 지정해주는 기능으로 만들어져 있다.

	::범위지정연산자 -> 전역에서 접근 가능하다.

	콘솔창 출력,입력기능

	출력
	cout (Cosole output)
	cout은 std namespace안에 만들어져 있는 기능 이기 때문에 std::를 붙여서 사용해야 된다.
	한줄의 끝은 ; 세미콜론으로 한다. 컴퓨터는 ;이 없으면 끝난지를 모르게 때문에 계속 머물러 있다.

	제어문자
	컴퓨터에서 텍스트를 표현하고 제어하는데 사용되는 특수 문자들 이다.

	========제어문자(Escape Sezuence) 종류 =========================
	\n한줄 개행을 해준다
	\a 경고문자
	\b back space
	\f 새 페이지로 
	\0 공백 문자( 문자열의 끝을 알린다)
	\r 현재 행의 처음으로 간다
	\t 탭만큼 이동
	\' 문자열로 작은따옴표를 사용할때
	\" 문자열로 큰따옴표를 사용할때
	\를 출력할려면 \\로 해야 된다.

	========제어문자(Escape Sezuence) 종류 =========================

	c언에서 사용되는 서식문자(Format Specifier)
	printf(),scanf()와 같은 함수에서 사용하고 출력 또는 입력할 데이터의 형식을 지정한다.
	%기호로 시작한다.

	%d 부호 있는 10진수
	%f 10진형 부동소수점(기본적으로 소수점 이하 6자리까지 출력 나머지는0 으로 출력)  /// 이건 나중에 부동소수점할때 다시한번 제대로 설명해줌
	%c 단일문자
	%s 문자열
	%o 8진수
	%x 16진수
	%u 부호없는 정수
	%% %기호를 출력

	입력
	cin(Console Input)
	c언어에서는 scanf를 사용한다
	c언어에서 입력을 사용할때는 &를 붙이게 되는데
	c++은 붙일 필요가 없다 내부에서 &사용하기 때문에 이다.
	cin >>

	cin은 공백 입력시 공백이전까지의 값만 결과로 받아들인다.
	ex)helllow word 라고 입력하면 hello만 입력이 된다.
	이러한 끈킴을 없애기 위해선 
	getline()함수를 사용한다
	getline()함수는 개행문자(\n)를 구분자로 사용하여서 한 줄 전체를 결과로 받아들인다.
	따라서 한줄 전체를 읽을수 있습니다. 공백을 포함함 문자열을 처리할 때 유용하다.

	getline()은 각기 다른 라이브러리에 2가지가 존재한다
	istream 라이브러리에 속한 cin.getline()
	string 라이브러리에 속한 getline() 있다.

	istream 라이브러리에 속한 getline()
	cin.getline(char* str, streamsize n)
	cin.getline(char* str, streamsize n,char dlim)
	
	1.문자 배열이며 마지막 글자가 '\n' 인 c_string을 입력받는데 사용
	2.n-1개의 문자 개수만큼 읽어와서 str에 저장한다(n번째 문자는 NULL(\0)로 바꾼다) 당연히 문자열에 마지막이니까 문자열의 마지막을 알리는건 \0;
	3.세 번째 인자인 delim은 별도로 지정해주지 않으면\ㅜ으로 인식한다
	4.delim 을 지정해주면 그 제한자 문자 직전까지 읽어와서 저장 

	string 라이브러리에 속한 getline()

	//구문
	getline(istream& is, string str);
	getline(istream& is, string str, char dlim);
	
	
	1.최대 문자수를 입력하지 않아도됨.
	2.원하는 구분자(delim)을 만날때 까지 모든 문자열을 입력받아 하나의 string객체에 저장


	결론적으로
	istream클래에 속한 getline()함수는
	문자열 버퍼(char배열)로 읽어들이고
	string에 속한 getline()함수는
	문자열로 저장한다.

	문자열 버퍼랑 문자열의차이 

	std::string클래스는 동적으로 크기가 조절되는 문자열 
	문자열버퍼(char배열)는 크기가 정적으로 정해져잇다. 선언할때 크기를 정확히 지정해주어야 된다.

	결론적으로
	문자열은 동적으로 크기가 조절되는 문자열을 표현하고
	문자열버퍼는 정적으로 크기가 고정된 문자열을 나타낸낸다
	
	
	
*/

void cout()
{
	std::cout << "cout함수 실행" << std::endl;
}

namespace Bard
{
	std::string sName = "";  //오류가 안나는이유 

	void Name()
	{
		std::cout << "저의 직업은 바드 입니다" << std::endl;
	}

	void cout(std::string sName)
	{
		printf("%s\n", sName.c_str());
	}
}


int main()
{
	//c++에서 사용하는출력방법
	std::cout << "Hellow Word" << std::endl;

	cout();

	std::cout << "안녕하세요" << std::endl;

	
	std::cout << "ff\n";

	//c언에서 출력하는방법
	printf("%d\n", 10);
	printf("%f\n", 3.f);
	printf("%c\n", 'B');

	int iNumber = 0;

	std::cin >> iNumber;

	std::cout << "출력번호:" << iNumber << std::endl;

	//문자열 배열은 수정이되는이유는 문자열 리터럴 원본을 복사하여 stack메모리에 사본으로 만든 char 문자의 배열을 사용한다 그래서 수정이 가능한거다
	//복사를하고잇다는 개념...
	//in TEXT SEGMENT “Hello” (원본)
	//in STACK ‘H’ ‘e’ ‘l’ ‘l’ ‘o’(사본)


	char cName2[] = "kakakak";  //문자열을 만들면서 크기랑 모두 만들어짐 
	char cName[25] = "";

	std::cin >> cName;

	std::cout << "이름입력:" << cName;



	std::cout <<std::endl;
	std::cin.ignore(256, '\n');


	std::string sName = "";

	std::getline(std::cin,sName);
	
	//std::cin.ignore(256, '\n');

	//std::cin >> sName;  //여기서 아까말한 getline을 사용하면되요
	
	std::cout << "한줄이름입력:" << sName << std::endl;

	//메모리영역을 알고잇어야 설명할수잇다 
	//stack data code heap 
	//code 영역은 read only 읽기만 가능 수정 불가능 
	//리터럴이 코드영역에 속한다 
	//"test"가 리터럴이다 
	/*	리터럴이란?
		소스 코드의 고정된 값을 나타내는 표기법이다. 
		거의 모든 프로그래밍 언어는 정수, 부동소수점 숫자, 문자열, 
		불린 자료형과 같은 기본적인 값에 대한 표기법이 있다.

		a 문자 리터럴(character literal)
		'abcd' 다중문자 리터럴(multicharacter literal)
		"abcd" 문자열 리터럴(string literal)
		'a'와 같이 ' '로 한 문자를 표현한 것의 자료형은 char 이다.
		"abcd"와 같이 " " 로 여러 문자를 표현한 것의 자료형은 const char*이다.
		
	*/

	//char* pNmae = "tset" // 예전에는 오류가 나오지않앗어 근데 이게 아주 치명적이야 왜 "test" 리터럴이야 근데 이거뭐야 코드영역
	//결국은 런타임에서 수정하면 에러가 발생하므로 치명적인것이다 그래서 visual에서 버전이 업글되면서 이부분을 const붙이지 않으면 에러를 띄우는거다.
	const char* pName = "tset";

	std::cout << "pNmae에 주소:" << (int)pName << std::endl; //문자열 주소를 int로 변환하는방법 
	std::cout << sizeof(pName) << std::endl;
	std::cout << *(pName + 1) << std::endl;


	pName = "kkkff";

	//주소는 변경이가능해 하지만 값은 변경이 안되 
	std::cout << "pNmae변경된 주소:" << (int)pName << std::endl; //문자열 주소를 int로 변환하는방법 
	std::cout << sizeof(pName) << std::endl;
	std::cout << *(pName + 1) << std::endl;
	
	//문자열자세히 아주 , 메모리영역,포인터 무조건개중요 const
	

	Bard::Name();

	Bard::cout("저는 바드입니다");

	return 0;
}