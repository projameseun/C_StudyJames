
#include <iostream>
#include <Windows.h>

//마우스 이벤트함수

void ProcessMouseEvent(MOUSE_EVENT_RECORD re)
{
	switch (re.dwEventFlags)
	{
	case 0: //버튼상태가 변경된 경우
	{
		if (re.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
		{
			std::cout << "Left Button pressed" << std::endl;
			//std::cout << "Mouse moved to (" << re.dwMousePosition.X << ", " << re.dwMousePosition.Y << ")" << std::endl;
		}
		else if (re.dwButtonState & RIGHTMOST_BUTTON_PRESSED) 
		{
			std::cout << "Right button pressed" << std::endl;
		}
		else 
		{
			std::cout << "Button released" << std::endl;
		}
		break;
	}
	case MOUSE_MOVED: // 마우스 이동
		 std::cout << "Mouse moved to (" << re.dwMousePosition.X << ", " << re.dwMousePosition.Y << ")" << std::endl;
		break;

	default:
		break;
	}
}



int main()
{
	//Handle 어떤 키라고 생각해도 좋다 
	//c++에서 다양한 리소스(파일,윈도우,스레드등)를 관리하기 위해 핸들을 사용한다.
	//핸들은 void*로 구현되어 있다 . 이유는 void*가 유연성이 좋다
	//예를들어 다양한 리소스는 서로 다른 타입의 리소스일텐데 이걸 모두 동일하게 처리할수 있다는 장점이 있다.

	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD savemode;	//typedef unsigned long 

	//INVALID_HANDLE_VALUE는 WIndowAPI에서 잘못된 핸들을 나타내기 위한 사용법이다.

	if (handle == INVALID_HANDLE_VALUE)
	{
		DWORD errorcode = GetLastError();
		std::cout << "Error input handle error code : " << errorcode << std::endl;
		
	
	}

	//콘솔모드 저장
	if (!GetConsoleMode(handle, &savemode))
	{
		std::cout << "Get Console Mode Error " << std::endl;

	}
	//특정조건이나 상태를 나타내는 값들을 플래그라고 한다. 보통 Bool값이나 bit로 표현이 많이된다.
	
	//콘솔 입력모드설정 플래그들 
	//ENABLE_EXTENDED_FLAGS //플래그의 활성화를 가능하게 하는 역할 
	//
	//#define ENABLE_PROCESSED_INPUT              0x0001	특정 키 조합 시스템처리 ex) Ctrl+C 조합기능들 ..
	//#define ENABLE_LINE_INPUT                   0x0002	사용자가 Enter키를 누를때 까지 입력이 버퍼에 기록되지 않는다
	//#define ENABLE_ECHO_INPUT                   0x0004	입력한 문자를 콘솔화면에 에코한다 이플래그가 설정되지 않는다면 입력된 문자는 화면에 표시되지 않는다
	//#define ENABLE_WINDOW_INPUT                 0x0008	창 입력을 활성화할때 설정되면 콘솔 입력버퍼가 창 크기 변경 이벤트를 기록한다
	//#define ENABLE_MOUSE_INPUT                  0x0010	마우스 입력 활성화
	//#define ENABLE_INSERT_MODE                  0x0020	삽입 모드 활성화 
	//#define ENABLE_QUICK_EDIT_MODE              0x0040	빠른 편집모드 활성화
	//#define ENABLE_EXTENDED_FLAGS               0x0080	
	//#define ENABLE_AUTO_POSITION                0x0100	
	//#define ENABLE_VIRTUAL_TERMINAL_INPUT       0x0200

	//마우스 모드 저장
	DWORD mMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	if (!SetConsoleMode(handle, mMode))
	{
		std::cout << "Set Console Mode Error" << std::endl;
	}

	INPUT_RECORD pRecord[128];
	DWORD NumRe; //초기화를 읽어줘야됨

	while (true)
	{
		//입력 이벤트 읽기
		if (!ReadConsoleInput(handle, pRecord, 128, &NumRe))
		{
			std::cout << "Error ReadConsoleInput " << std::endl;
			system("Pause");
			break;
		}

		//입력 이벤트 처리
		for (DWORD i = 0; i < NumRe; ++i)
		{
			if (pRecord[i].EventType == MOUSE_EVENT)
			{
				//마우스 이벤트 시작
				ProcessMouseEvent(pRecord[i].Event.MouseEvent);
			}
		}
	
	}

	
	SetConsoleMode(handle, savemode);
	
	
	
	return 0;
}