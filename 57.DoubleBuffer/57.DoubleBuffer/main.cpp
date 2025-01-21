#include <iostream>
#include <Windows.h>
#include <string>
#include <thread>
class ConsoleDoubleBuffer
{

private:


	HANDLE m_Buffer[2];
	int m_iActiveBuffer;	//현재 활성화된 버퍼인덱스
	int m_iWidth;
	int m_iHeight;


public:
	ConsoleDoubleBuffer(int _width, int _height) :
		m_iWidth(_width), m_iHeight(_height) ,m_iActiveBuffer(0)
	{


		//버퍼 생성
		//CreateConsoleScreenBuffer -> win api에서 제공하는 함수로써, 새로운 콘솔 화면 버퍼를 생성하는 역할을 한다.
		//이 함수는 콘솔출력을 제어할수 있는 스크린버퍼를 만들게 된다 ,콘솔에서 그래픽 그리거나 텍스트출력할때 사용된다.
		//CreateConsoleScreenBuffer(
		//	_In_ DWORD dwDesiredAccess,	버퍼에 대한 액세스 권한지정 GENERIC_READ | GENERIC_WRITE 읽기,쓰기 권한을 부여
		//	_In_ DWORD dwShareMode, 버퍼에대한 공유모드인데 일반적으로 0을 사용한다
		//	_In_opt_ CONST SECURITY_ATTRIBUTES * lpSecurityAttributes, 보안속성을 지정하는 구조체에 대한 포인터이다 보통 NULL을 사용한다
		//	_In_ DWORD dwFlags, 버퍼의 동작을 제어하는플래그 일반적으로 CONSOLE_TEXTMODE_BUFFER 사용하여 텍스트 모드 버퍼를 생성한다 
		//	_Reserved_ LPVOID lpScreenBufferData	버퍼데이터에 대한 포인터 보통 NULL로 설정한다 

		for (int i = 0; i < 2; ++i)
		{
			m_Buffer[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
			//콘솔화면 크기설정
			COORD tBufferSize = { static_cast<SHORT>(m_iWidth), static_cast<SHORT>(m_iHeight) };
			SMALL_RECT rect = { 0,0,static_cast<SHORT>(m_iWidth - 1),static_cast<SHORT>(m_iHeight - 1) };
			SetConsoleScreenBufferSize(m_Buffer[i], tBufferSize);
			SetConsoleWindowInfo(m_Buffer[i], TRUE, &rect);

		}
		
	}

	~ConsoleDoubleBuffer()
	{
		for (int i = 0; i < 2; ++i)
		{
			CloseHandle(m_Buffer);
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

		//WriteConsoleOutputCharacterA 콘솔 화면 버퍼에 직접 텍스트를 쓰는 역할을 하며, 이를 실제로 콘솔 화면에 보이게 하려면 버퍼를 활성화 해줘야된다.
		//SetConsoleActiveScreenBuffer 활성화버퍼
		//중요한건 화면에 아직보이지 않고 버퍼에만 존재하고있는거다 지금 상태는
		WriteConsoleOutputCharacterA(m_Buffer[m_iActiveBuffer], str.c_str(), str.length(), coord, &dwWritten);

	}

	void Present()
	{
		//현재 버퍼를 활성화하고 
		SetConsoleActiveScreenBuffer(m_Buffer[m_iActiveBuffer]);
		m_iActiveBuffer = 1 - m_iActiveBuffer;	//, 다음버퍼를 준비
	}
};

int main()
{
	const int width = 100;
	const int height = 100;

	ConsoleDoubleBuffer console(width, height);

	while (true)
	{
		//콘솔 버퍼 화면 비우기
		console.Clear();
		

		//텍스트 현제 활성화된 버퍼출력
		console.Draw(0, 0, "Flickering");

		//버퍼를 콘솔에 표시하고 다음버퍼활성화
		console.Present();

		//std::this_threa
		//std::cout << "Flickering" << std::endl;
		//깜빡이는 현상을 Flickering 현상이라고 한다 (꺼질것같은)
		//이 현상을 막기위해서는 콘솔 화면 버퍼2개를 이용하여 더블 버퍼링을 구현해야 된다.

		  // 프레임 속도 조절 (예: 60 FPS)
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	return 0;
}