#include <iostream>
#include <Windows.h>

#define MOUSE_BUTTON 0

void PrcesssMouseEvent(MOUSE_EVENT_RECORD mevent)
{
	switch (mevent.dwEventFlags)
	{
	case MOUSE_BUTTON: //버튼상태가 변경된경우
	{
		if (mevent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			std::cout << "Mouse Left Button Pressed" << std::endl;\
			std::cout << "Mouse Move to ( " << mevent.dwMousePosition.X << " , " << mevent.dwMousePosition.Y << ")" << std::endl;
		}
		else if (mevent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
		{
			std::cout << "Mouse Right Button Pressed" << std::endl;
		}
		else
		{
			std::cout << "Button released" << std::endl;
		}
	}
	case MOUSE_MOVED:
	{
//		std::cout << "Mouse Move to ( " << mevent.dwMousePosition.X << " , " << mevent.dwMousePosition.Y << ")" << std::endl;
	}
	default:
		break;
	}
}

int main()
{
	//Handle 어떤 키라고 생각해도 좋다.
	//c++에서 다양한 리소스(파일,윈도우,스레드등)를 관리하기위해 핸들을 사용한다.
	//핸들은 void*로 구현되어있다 이유는 void*가 유연성이 좋아서..
	//예를들어 다양한 리소스는 서로 다른 리소스일텐데 이걸모두 동일하게 처리할수 잇는 장점이 있다.

	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD savemode;	//unsigned long

	if (handle == INVALID_HANDLE_VALUE)
	{
		DWORD errocode = GetLastError();
		std::cout << "INVALID_HANDLE_VALUE Error :  " << errocode <<  std::endl;
	}

	//콘솔 모드저장
	
	if (!GetConsoleMode(handle, &savemode))
	{
		DWORD errocode = GetLastError();
		std::cout << "GetConsoleMode Error :  " << errocode << std::endl;
	}

	//플래그란 특정조건 상태를 나타내는 값을들 플래그라고 한다.
	//보통 bool값이나 bit로 표현이 된다.

	//#define ENABLE_PROCESSED_INPUT              0x0001	특정키 조합 시스템처리 ex) Ctrl + C조합기능들...
	//#define ENABLE_LINE_INPUT                   0x0002	사용자가 Enter키를 누를때 까지 입력에 버퍼가 기록되지 않는다.
	//#define ENABLE_ECHO_INPUT                   0x0004	입력한 문자를 콘솔화면에 에코한다. 이 플래그가 설정되지 않는다면 입력된 문자는 화면에 표시되지 않는다.
	//#define ENABLE_WINDOW_INPUT                 0x0008	창 입력을 활성화 할때 사용 콘솔 입력버퍼가 창 크기 변경 이벤트를 기록한다
	//#define ENABLE_MOUSE_INPUT                  0x0010	마우스 입력을 활성화 
	//#define ENABLE_INSERT_MODE                  0x0020	삽입모드 활성화
	//#define ENABLE_QUICK_EDIT_MODE              0x0040	빠른 편집 모드
	//#define ENABLE_EXTENDED_FLAGS               0x0080	플래그의 활성화를 가능하게 하는 역할
	//#define ENABLE_AUTO_POSITION                0x0100
	//#define ENABLE_VIRTUAL_TERMINAL_INPUT       0x0200

	DWORD mMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

	if (!SetConsoleMode(handle, mMode))
	{
		DWORD errocode = GetLastError();
		std::cout << "SetConsoleModeError :  " << errocode << std::endl;
	}


	INPUT_RECORD pRecord[128];
	DWORD NumRe; //얼마만큼읽을지..

		while (true)
		{


			//입력 이벤트 읽기
			if (!ReadConsoleInput(handle, pRecord, 128, &NumRe))
			{
				std::cout << "ReadConsoleInput Error" << std::endl;
				system("Pause");
				break;
			}

			for (DWORD i = 0; i < NumRe; ++i)
			{
				if (pRecord[i].EventType == MOUSE_EVENT)
				{
					//마우스이벤트시작
					//std::cout << "마우스 이벤트시작 " << std::endl;
					PrcesssMouseEvent(pRecord[i].Event.MouseEvent);
				}
			}
		}
	

	

	


	SetConsoleMode(handle, savemode);

	return 0;
}