#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{


	//SetConsoleCP(65001);
	//SetConsoleOutputCP(65001);	//윈도우 콘솔에서 출력 코드페이지(문자인코딩방식)를 설정하는 함수
	//이를 통해서 콘솔에서 출력되는 문자들이 어떤 인코딩 방식으로 처리 될지를 지정할수 있다.
	//65001 : UTF-8 
	//949 : EUC-KR
	//437 : MS-DOS
	//936 : GBK(중국어)
	//SetConsoleOutputCP(949);



	/*
	스트림이란?
	실제어원은 시냇물 흐르다라는 말에서 시작이 되었다.
	데이터의 흐름을 나타내는 용어다.
	결론적으로 데이터를 연속적으로 흘려보내거나 받아오는 통로를 의미한다.
	ex)키보드를 통해서 입력을 받고 그 결과값을 모니터에 출력하는 통로 
	프로그램 <-------(스트림) 1)키보드 2)모니터 3)파일 4)... 5)네트워크

	입력 스트림 : 외부 데이터가 프로그램에 들어오게 되는 경우
	출력 스트림 : 프로그램의 데이터를 외부로 내보내는 경우

	c에서 쓰는 파일스트림

	C언어에서는 FILE 구조체와 관련 함수(fopen ,fclose,fgets,fwrite등) 을 사용하여 파일을 처리한다 
	헤더파일은 stdio.h에 있습니다.


	c++에서 쓰는 표준 스트림
	std::cout , std::cin , std::cerr(에러출력)

	c++에서 쓰는 파일 스트림
	std::ifstream -> 파일 입력 스트림(파일 읽기)
	std::ofstream -> 파일 출력 스트림(파일 쓰기)
	std::fstream -> 파일 입력 및 출력 스트림( 파일 읽기/쓰기 가능)

	*/
	
	//c언어 방식 파일

	//비쥬얼 스튜디오 버전에 따라 다른 내부 
	//https://blog.naver.com/tipsware/221262052970
	
	//visual studio 2013까지는 FILE구조체가 
	//typedef struct _iobuf
	//{
	//	char*	_ptr;
	//  int		_cnt;
	// char		*_base;
	// int		_flag;
	// int		_file;
	// int		_charbuf;
	// int		_bufsiz;
	// char*	_tmfname
	//} FILE;
	// 
	// 2017때 부터 변경
	//typedef struct _iobuf
	//{
	//	void* _Placeholder;
	//} FILE;

	//변경된 이유 
	//구조체의 내부 구현 세부사항을 감추고 파일 입출력 기능을 사용하느 개발자가 이를 직접 다루지 못하도록 하기 위함
	//이렇게 설계를 한이유는 추상화와 호환성유지를 위한 전략

	//FILE구조체의 실제구현은 운영체제와 라이브러리 버전에 따라다릅니다.
	//내부를 void*로 감추면 개발자가 FILE내부에 직접 전근하거나 조작할수 없다
	//이는 추상화를 제공항 사용자가 파일 스트림 동작원리를 몰라도 간단히 입출력을 수행할수 있게해준다 또한 내부 구조를 변경해도 외부코드와의 호환성이 유지된다.

	//void* placeholder로 정의되어 있지만 실제 구현은 MSVC런타임 라이브러리내부에 비공개로 존재하고있다.(사용자가 접근할수 없다)

	//FILE*는 레스토랑의 주문 번호표랑 비슷하다
	//사용자는 번호표(주소)를 들고 기다리면, 주방(라이브러리 내부)에서 알아서 요리를 준비해준다고 보면 된다. 
	//내부과정(레시피,재료처리 등)은 손님에게 보이지 않는다 우린 결과물만 받아들이면 된다.


	
	
	FILE* pFile = nullptr;

	//
	/*
	setlocal 함수 
	category: 로케일을 설정할 항목을 지정하는 값입니다. 주로 다음과 같은 값을 사용합니다:

	LC_ALL: 모든 카테고리를 설정합니다.
	LC_COLLATE: 문자열의 정렬 순서 설정 (예: 알파벳 순서).
	LC_CTYPE: 문자 분류와 변환 (예: 대소문자 변환).
	LC_MONETARY: 통화 형식 관련 설정 (예: 통화 기호).
	LC_NUMERIC: 숫자 형식 설정 (예: 소수점 구분 기호).
	LC_TIME: 날짜와 시간 형식 설정.
	locale: 설정하려는 로케일의 이름을 지정합니다. 예를 들어:
	
	"en_US": 미국 영어.
	"ko_KR": 한국어.
	"C" 또는 "POSIX": 기본 로케일로, 시스템 기본값을 의미합니다.
	"de_DE": 독일어.
	*/
	//로케일을 설정해주는 함수 호케일은 날짜,시간,숫자,포맷,인코딩을 관리해줄수 있다.
	setlocale(LC_ALL, "ko-KR");	//언어 지역코드를 ko-kr로설정

	//모드가 rb 바이너리 형식으로 열면 줄바꿈 문자가 변환되지않고 그대로 읽혀져서 \r\n까지 출력이된다
	fopen_s(&pFile,"newFile.txt", "rt");	//파일 열기

	if (pFile == nullptr)
	{
		perror("Faild to Open File");		//에러 메시지를 출력하는 함수
	
		return 0;
	}

	//출력
	char Buffer[256] = {};

	string strBuffer[256];
	

	
	
	//fgets함수는 스트림에서 문자열을 받아서 (MaxCount -1) 개의 문자를 입력 받을때까지나, 개항 문자나 파일끝에 도달할때까지 입력 받아서 
	// C형식의 문자열로 저장한다. 
	// 개행 문자는 fgets로 하여금 입력을 끝나게 하지만 이문자 역시 _Buffer에 저장한다 
	// NULL문자는 자동적으로 마지막으로 입력받은 문자뒤에 붙는다. 
	// fgets함수는 scanf함수와 달리 오직 개행문자의 의해서만 입력이 끝나기 때문에 띄어쓰기가 있는 문자열도 입력받을수 있다 
	// 반면에 scanf함수의 경우 개행문자뿐만 아니라
	// ' ' 와 '\t'에 의해서도 입력이 끝낙니때문에 띄어쓰기가 있는 문자열은 입력받을수 없다.
	
	//_ACRTIMP char* __cdecl fgets(
	//	_Out_writes_z_(_MaxCount) char* _Buffer,
	//	_In_                      int   _MaxCount,
	//	_Inout_                   FILE * _Stream
	//);

	//만약에 txt파일이 한국어로 되어있으면 저장할때 인코딩방식을 ANSI로 해줘야 제대로 한국어가 출력이된다.
	// 또다른 방법은 system("chcp 65001");  Winodws에서 콘솔 문자셋을 UTF-8로 설정 이걸 근데사용하면 콘솔에 제대로 메시지가 됫다는 출력이되는데 이거마져 싫으면
	//SetConsoleOutputCP(65001); 를사용해라 
	
	
	
	

	//system("chcp 65001");	
	

	//스트림 위치 지정자
	//Origin 인자로 전달된 위치로 부터 Offset인자로 전달된 만큼 더한 위치로 위치 지정을 설정한다.
	// Offset은 이동할 바이트수를 나타내며,양수이면 앞으로 , 음수이면 뒤로 이동한다
	// Origin는 offset의 기준위치를 지정한다 이값은 3가지가 될수잇다
	// SEEK_SET : 파일의 시작 기준으로 합니다 
	// SEEK_CUR : 파일 포인터의 현재위치를 기준으로 합니다ㅣ
	// SEEK_END : 파일의 끝을 기준으로 한다
	// fseek함수가 성공적으로 실행이 되면 0을 반환하고 실패하면 0이 아닌값을 반환한다.
	//_ACRTIMP int __cdecl fseek(
	//	_Inout_ FILE * _Stream,
	//	_In_    long  _Offset,
	//	_In_    int   _Origin
	//);

	fseek(pFile, 0, SEEK_END);	// 파일포인터를 파일끝으로 이동
	
	size_t isize = ftell(pFile);	//파일 포인터의 현재위치를 반환하는 함수이다 즉, 파일을 읽거나 쓸때 현재 파일에서 몇번째 바이트를 가리키고있는지 알아낼수있다.
	fseek(pFile, 0, SEEK_SET);		//파일포인터를 다시 파일 시작으로 이동


	//_ACRTIMP size_t __cdecl fread(
	//	_Out_writes_bytes_(_ElementSize * _ElementCount) void* _Buffer,	버퍼
	//	_In_                                             size_t _ElementSize,	각 항목의 크기(바이트단위)
	//	_In_                                             size_t _ElementCount,	읽은 갯수
	//	_Inout_                                          FILE * _Stream			스트림
	//);

	//데이터를 읽어오는 함수이다 주로 바이너리 파일을 읽거나,텍스트 파일에서 일정량에 데이터를 한번에 읽어오는데 사용된다.
	//개행문자 상관없이 읽어 들일 바이트수 만큼 문자를 읽어온다 한번에 다읽을수잇다
	//하지만 fgets는 개행문자를 만나면 더이상 읽지 않는다.


	//fread(Buffer, 1,isize, pFile);
	//for (size_t i = 0; i < isize; ++i)
	//{
	//	printf("buffer[%zu] = %d ('%c')\n", i, Buffer[i], Buffer[i]);
	//}


	//바이너리 형식이면 isize를 넣고 그냥 일반 텍스트방식이면 \r빠지기때문에 isize-1을 넣는게 맞다
	

	

	fread(Buffer, 1,isize, pFile);
	Buffer[isize ] = '\0';
	//fgets(Buffer, 256, pFile);

	//system("chcp 65001");
	std::cout << Buffer << std::endl;


	//=======================================
	//파일쓰기 
	//문자열을 파일에 쓰는함수이다.
	//이 함수는 주어진 문자열 그대로 파일에 쓰게되어있다 또한 형식 지정 없이 문자열을 쓰기때문에 
	//파일에 출력될 내용이 그대로 기록된다.
	
	memset(Buffer, 0, isize);		//0으로 싹다초기화 

	const char* str = "tst222\n";

	fseek(pFile, -1, SEEK_END);

	char lastchar = fgetc(pFile);
	
	//만약에 문자열이 지금 라스트가 \n 또는 마지막이 아니라면 \n을 강제로 넣어준다
	//EOF end of file -1을반환
	if (lastchar != '\n' && lastchar != EOF)
	{
		fseek(pFile, 0, SEEK_END);
		fputs("\n", pFile);
		
	}




	fputs(str, pFile);
	

	
	
	//fprintf(pFile, "%s", "test");

	
	//파일 닫기 꼭해줘야된다
	//인자로 지정한 스트림에 해당하는 파일을 닫는다
	//이때 그스트림의 모든 버퍼들은 비워진다(flush)
	//혹시나 fclose함수의 호출이 실패하더라고 인자로 전잘된 스트림과 이에 해당하느 파일의 관계는 끊어진다.
	fclose(pFile);

	//새로운 텍스트파일을생성한다 
	FILE* pNewFile = nullptr;

    fopen_s(&pNewFile,"newFile.txt", "wb");
	
	if (pNewFile == nullptr)
	{
		return 1;
	}
	
	//UTF8 BOM
	

	
	//const char* str2 = "안녕하세요 다시 변경합니다";
	//fwrite(str2, 1, strlen(str2), pNewFile);
	fputs("My Name is James\n", pNewFile);	//UTF8로저장가능
	//fprintf(pNewFile, "안녕하세요 제임스입니다 방가워요\n");

	fclose(pNewFile);
	

	


	return 0;
}
