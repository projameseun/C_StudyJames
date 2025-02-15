#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>

class ConsoleDoubleBuffer
{

private:
	HANDLE m_Buffer[2];		//HANDLE은 윈도우에서 사용되는 핸들을 나타내는 데이터형이다. 핸들은 윈도우에서 사용되는 객체를 식별하는데 사용된다. 포인터와 유사한 역할을 한다
	int m_iActiveBuffer;	//현재 활성화된 버퍼인덱스
	int m_iWidth;
	int m_iHeight;
							//버퍼의 개념
						/*
							1.메모리 공간 버퍼
							데이터를 일시적으로 저장하는 메모리 공간이다.
							데이터의 입출력 속도를 조절하고 데이터의 일관성을 유지하며, 효율적인 데이터 처리를 가능하게 한다.
							InputOutput ,네트워크통신,그래픽 렌더링 등에서 사용된다.
						
							2.화면버퍼
							콘솔 애플리케이션에서 화면에 출력할 텍스트나 그래픽데이터를 임시로 저장하는 메모리공간이다.
							화면에 표시될 내용을 저장하고 더블버퍼링을 통해 화면 깜빡임을 줄인다.
						*/

public:
	ConsoleDoubleBuffer(int _width, int _height) :
		m_iWidth(_width), m_iHeight(_height) ,m_iActiveBuffer(0)
	{


		//버퍼 생성
		//CreateConsoleScreenBuffer -> win api에서 제공하는 함수로써, 새로운 콘솔 화면 버퍼를 생성하는 역할을 한다.
		//이 함수는 콘솔출력을 제어할수 있는 스크린버퍼를 만들게 된다 ,콘솔에서 그래픽 그리거나 텍스트출력할때 사용된다.
		//	인자들설명----
		//	_In_ DWORD dwDesiredAccess,	버퍼에 대한 액세스 권한지정 GENERIC_READ | GENERIC_WRITE 읽기,쓰기 권한을 부여
		//	_In_ DWORD dwShareMode, 버퍼에대한 공유모드인데 일반적으로 0을 사용한다
		//	_In_opt_ CONST SECURITY_ATTRIBUTES * lpSecurityAttributes, 보안속성을 지정하는 구조체에 대한 포인터이다 보통 NULL을 사용한다
		//	_In_ DWORD dwFlags, 버퍼의 동작을 제어하는플래그 일반적으로 CONSOLE_TEXTMODE_BUFFER 사용하여 텍스트 모드 버퍼를 생성한다 
		//	_Reserved_ LPVOID lpScreenBufferData	버퍼데이터에 대한 포인터 보통 NULL로 설정한다 
		//	반환값===> 성공시, 함수는 새로운 콘솔 화면 버퍼에 대한 핸들을 반환한다
		//			   실패 시, INVALID_HANDLE_VALUE(유효하지 않는 핸들)를 반환하며, 오류에 대한 자세한 정보는 GetLastError 함수를 통해 얻을 수 있습니다.

		//	CreateConsoleScreenBuffer함수로 반환된 핸들을 사용하여 텍스트를 출력하려면 WriteConsoleOutputCharacterA 를 사용하여 콘솔 화면 버퍼에 텍스트를 쓸수있다.
		

		//for (int i = 0; i < 2; ++i)
		//{
		//	m_Buffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		//	//콘솔화면 크기설정
		//	COORD tBufferSize = { static_cast<SHORT>(m_iWidth), static_cast<SHORT>(m_iHeight) };
		//	SMALL_RECT rect = { 0,0,static_cast<SHORT>(m_iWidth - 1),static_cast<SHORT>(m_iHeight - 1) };
		//	
		//	
		//	SetConsoleScreenBufferSize(m_Buffer[i], tBufferSize);
		//	//SetConsoleScreenBufferSize함수를 사용하여 콘솔화면 버퍼의크기를 변경하면,콘솔창의 크기는 자동으로 변경되지 않는다. 결론은 콘솔 화면 버퍼의 크기와 콘솔창의 크기는 별개이다.
		//	//콘솔화면 버퍼:콘솔에서 출력할 텍스트나,그래픽 데이터를 저장하는 메모리 공간이다. 버퍼의 크기는 화면에 표시 될수 있는 전체 데이터 크기를 말한다.

		//	SetConsoleWindowInfo(m_Buffer[i], TRUE, &rect);	//콘솔창의 크기를 변경하는 함수

		//}

		//코드 개선 예외처리
		//	1.	예외 발생 (throw): 예외가 발생하면 throw 키워드를 사용하여 예외 객체를 던집니다.
		//	2.	예외 처리(catch) : 예외가 발생한 함수나 호출 스택 상위의 함수에서 catch 블록을 사용하여 예외를 처리합니다.
		//	3.	예외 미처리 : 만약 예외를 처리할 catch 블록이 없으면, 프로그램은 비정상적으로 종료됩니다.
		for (int i = 0; i < 2; ++i)
		{
			
			m_Buffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
			if (m_Buffer[i] == INVALID_HANDLE_VALUE)
			{
				throw std::runtime_error("실패했습니다.");
			}
			// 앞에 t는 type의 약자로 일반적으로 고주체나 클래스의 인스턴스 나타날때 사용
			COORD tBufferSize = { static_cast<SHORT>(m_iWidth), static_cast<SHORT>(m_iHeight) };
			if(!SetConsoleScreenBufferSize(m_Buffer[i], tBufferSize))
			{
				int iError = GetLastError();
				CloseHandle(m_Buffer[i]);
				throw std::runtime_error("실패했습니다.");
			}
			SMALL_RECT rect = { 0,0,static_cast<SHORT>(m_iWidth - 1),static_cast<SHORT>(m_iHeight - 1) };
			if (!SetConsoleWindowInfo(m_Buffer[i], TRUE, &rect))
			{
				CloseHandle(m_Buffer[i]);
				throw std::runtime_error("실패했습니다.");
			}


		}

		
	}

	~ConsoleDoubleBuffer()
	{
		for (int i = 0; i < 2; ++i)
		{
			CloseHandle(m_Buffer[i]);
		}
	}

	void Clear()
	{
		//버퍼를 초기화하여 화면을 지운다
		DWORD	dwWritten;
		COORD	coord = {0,0};
		FillConsoleOutputCharacter(m_Buffer[m_iActiveBuffer], ' ', m_iWidth * m_iHeight, coord, &dwWritten);	//지정된 문자로 채운다 
		FillConsoleOutputAttribute(m_Buffer[m_iActiveBuffer], FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE, m_iWidth * m_iHeight, coord, &dwWritten);	//색상설정
	}
	
	void Draw(int x, int y, const std::string& str)
	{
		//버퍼텍스트출력
		COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
		DWORD dwWritten;

		//지정된 콘솔 화면 버퍼의 특정위치에 텍스트를 출력하는 역할이다 실제 화면에 바로출력되는것이아니라 우리가 만든 화면 버퍼에 텍스트를 저장하는거다
		WriteConsoleOutputCharacterA(m_Buffer[m_iActiveBuffer], str.c_str(), str.length(), coord, &dwWritten);

	}

	void PresentBufferOutPut()
	{
		//지정된 콘솔화면 버퍼를 활성화하며,해당 버퍼의 내용을 콘솔창에 표시하는 역할. 여러 콘솔화면 버퍼 중 하나를 선택하여 현재 활성화된 버퍼로 설정
		SetConsoleActiveScreenBuffer(m_Buffer[m_iActiveBuffer]);	
		m_iActiveBuffer = 1 - m_iActiveBuffer;	//, 다음버퍼를 준비
	}
};

int main()
{

	// 콘솔 창의 크기를 설정 (너비 120, 높이 30)
	system("mode con: cols=100 lines=50");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE)
	{
		std::cerr << "GetStdHandle failed with error " << GetLastError() << std::endl;
		return 0;
	}

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		std::cerr << "GetConsoleScreenBufferInfo failed with error " << GetLastError() << std::endl;
		return 0;
	}

	int iWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	int iHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	//const int iWidth = 100;
	//const int iHeight = 50;



	

	//ConsoleDoubleBuffer console(width, height);

	//while (true)
	//{
	//	//콘솔 버퍼 화면 비우기
	//	console.Clear();
	//	

	//	//텍스트 현제 활성화된 버퍼출력
	//	console.Draw(0, 0, "Flickering");

	//	//버퍼를 콘솔에 표시하고 다음버퍼활성화
	//	console.Present();

	//	//std::this_threa
	//	//std::cout << "Flickering" << std::endl;
	//	//깜빡이는 현상을 Flickering 현상이라고 한다 (꺼질것같은)
	//	//이 현상을 막기위해서는 콘솔 화면 버퍼2개를 이용하여 더블 버퍼링을 구현해야 된다.

	//	  // 프레임 속도 조절 (예: 60 FPS)
	//	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	//}

	try {
		ConsoleDoubleBuffer console(iWidth, iHeight);
		while (true)
		{
			console.Clear();
			console.Draw(0, 0, "Flickering");
			console.PresentBufferOutPut();
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			
		}

	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}