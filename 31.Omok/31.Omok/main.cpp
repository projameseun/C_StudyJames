#include <iostream>
#include <Windows.h>
#include "GameEngine.h"




int main()
{


	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD savemode;	//unsigned long

	if (handle == INVALID_HANDLE_VALUE)
	{
		DWORD errocode = GetLastError();
		std::cout << "INVALID_HANDLE_VALUE Error :  " << errocode << std::endl;
	}

	//콘솔 모드저장

	if (!GetConsoleMode(handle, &savemode))
	{
		DWORD errocode = GetLastError();
		std::cout << "GetConsoleMode Error :  " << errocode << std::endl;
	}



	DWORD mMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

	if (!SetConsoleMode(handle, mMode))
	{
		DWORD errocode = GetLastError();
		std::cout << "SetConsoleModeError :  " << errocode << std::endl;
	}


	//INPUT_RECORD pRecord[128];
	//DWORD NumRe = 0; //얼마만큼읽을지..

	GameEngine GM;

	GM.GameStart();
		


		//입력 이벤트 읽기
	
	
	//종료될때 다시 원래대로 세팅

	SetConsoleMode(handle, savemode);

	return 0;
}