#include "GameEngine.h"

#define MOUSE_BUTTON 0

void GameEngine::gotoxy(int x, int y)
{
	COORD _pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), _pos);

}



MOUSE_EVENT_RECORD GameEngine::PrcesssMouseEvent(MOUSE_EVENT_RECORD mevent)
{
	switch (mevent.dwEventFlags)
	{
	case MOUSE_BUTTON: //버튼상태가 변경된경우
	{
		if (mevent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
		{

			//타입넣어주기
		
			GameRender(mevent);
			/*std::cout << "Mouse Left Button Pressed" << std::endl; \
				std::cout << "Mouse Move to ( " << mevent.dwMousePosition.X << " , " << mevent.dwMousePosition.Y << ")" << std::endl;*/
		}
		else if (mevent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
		{
			//std::cout << "Mouse Right Button Pressed" << std::endl;
		}
		else
		{
			//std::cout << "Button released" << std::endl;
		}
	}
	case MOUSE_MOVED:
	{
		//		std::cout << "Mouse Move to ( " << mevent.dwMousePosition.X << " , " << mevent.dwMousePosition.Y << ")" << std::endl;
	}
	default:
		break;
	}

	return mevent;
}


void GameEngine::GameInit()
{
	m_Colum = 19;
	m_Row = 19;
	m_Black = true;		//true 흑돌 , false 백돌
	NumRe = 0;

	m_GameWin = 0;
	MouseInit();
	StoneInit();
}


void GameEngine::StoneInit()
{
	for (int i = 0; i <GridY; ++i)
	{
		for (int j = 0; j < GridX; ++j)
		{
			m_GridType[i][j].m_Type = 0;
		}
	}

	
}

void GameEngine::GameStart()
{
	//HANDLE handle, INPUT_RECORD* pRecord, DWORD NumRe
	//입력 이벤트 읽기
	GameInit();
	
	m_Om->OmokMap(m_Colum, m_Row);

	while (true)
	{
		if (!ReadConsoleInput(handle, pRecord, 128, &NumRe))
		{
			std::cout << "ReadConsoleInput Error" << std::endl;
			system("Pause");
			break;
		}

		if (m_GameWin == 0)
		{
			GameUpdate(handle, pRecord, NumRe);
		}
		else if (m_GameWin == 1)
		{
			system("pause");
			Clear();
		}
		
	}


}

void GameEngine::GameRender(MOUSE_EVENT_RECORD MSenvet)
{
	if (MSenvet.dwMousePosition.X <= GridX && MSenvet.dwMousePosition.Y <= GridY)
	{
		if (MSenvet.dwMousePosition.X % 2 == 0 || MSenvet.dwMousePosition.X == 0)
		{
			gotoxy(MSenvet.dwMousePosition.X, MSenvet.dwMousePosition.Y);

			if (m_GridType[MSenvet.dwMousePosition.Y][MSenvet.dwMousePosition.X].m_Type == 0)
			{
				if (m_Black == true) //흑돌
				{

					m_GridType[MSenvet.dwMousePosition.Y][MSenvet.dwMousePosition.X].m_Type = 1;
					std::cout << "○";
					//gotoxy(13, 13);
					//std::cout << "Mouse Move to ( " << MSenvet.dwMousePosition.X << " , " << MSenvet.dwMousePosition.Y << ")";
					m_Black = !m_Black;
				}
				else if (m_Black == false) //백돌
				{

					m_GridType[MSenvet.dwMousePosition.Y][MSenvet.dwMousePosition.X].m_Type = 2;
					std::cout << "●";
					//std::cout << "Mouse Move to ( " << MSenvet.dwMousePosition.X << " , " << MSenvet.dwMousePosition.Y << ")";
					m_Black = !m_Black;
				}
			}





		}//if (MSenvet.dwMousePosition.X % 2 == 0 || MSenvet.dwMousePosition.X == 0)
	}//if (MSenvet.dwMousePosition.X <= GridX && MSenvet.dwMousePosition.Y <= GridY)

	JugMent();
	
	//JugMent


}

MOUSE_EVENT_RECORD GameEngine::GameUpdate(HANDLE handle, INPUT_RECORD *pRecord, DWORD NumRe)
{

	//MOUSE Evnent
	for (DWORD i = 0; i < NumRe; ++i)
	{
		if (pRecord[i].EventType == MOUSE_EVENT)
		{
			//마우스이벤트시작
			//std::cout << "마우스 이벤트시작 " << std::endl;
			pRecord[i].Event.MouseEvent = PrcesssMouseEvent(pRecord[i].Event.MouseEvent);

			return pRecord[i].Event.MouseEvent;
		}
			
		return pRecord[i].Event.MouseEvent;
		
	}

	
	
	 
}

void GameEngine::JugMent()
{
	gotoxy(22, 22);

	for (int i = 0; i < GridY; ++i)
	{
		for (int j = 0; j < GridX; j += 2)
		{
			//가로
			if ((m_GridType[i][j].m_Type == 1) &&
				(m_GridType[i][j + 2].m_Type == 1) &&
				(m_GridType[i][j + 4].m_Type == 1) &&
				(m_GridType[i][j + 6].m_Type == 1) &&
				(m_GridType[i][j + 8].m_Type == 1))
			{
				std::cout << "흑돌승리" << std::endl;
				m_GameWin = 1;
		
			}

			//세로
			if ((m_GridType[i][j].m_Type == 1) &&
				(m_GridType[i + 1][j].m_Type == 1) &&
				(m_GridType[i + 2][j].m_Type == 1) &&
				(m_GridType[i + 3][j].m_Type == 1) &&
				(m_GridType[i + 4][j].m_Type == 1))
			{
				std::cout << "흑돌승리" << std::endl;
				m_GameWin = 1;
		
			}

			//왼대
			if ((m_GridType[i][j].m_Type == 1) &&
				(m_GridType[i + 1][j + 2].m_Type == 1) &&
				(m_GridType[i + 2][j + 4].m_Type == 1) &&
				(m_GridType[i + 3][j + 6].m_Type == 1) &&
				(m_GridType[i + 4][j + 8].m_Type == 1))
			{
				std::cout << "흑돌승리" << std::endl;
				m_GameWin = 1;
				
			}

			//오대
			if (j > 7)
			{
				if ((m_GridType[i][j].m_Type == 1) &&
					(m_GridType[i + 1][j - 2].m_Type == 1) &&
					(m_GridType[i + 2][j - 4].m_Type == 1) &&
					(m_GridType[i + 3][j - 6].m_Type == 1) &&
					(m_GridType[i + 4][j - 8].m_Type == 1))
				{
					std::cout << "흑돌승리" << std::endl;
					m_GameWin = 1;
				
				}
			}
			

			//흰

			//가로
			if ((m_GridType[i][j].m_Type == 2) &&
				(m_GridType[i][j + 2].m_Type == 2) &&
				(m_GridType[i][j + 4].m_Type == 2) &&
				(m_GridType[i][j + 6].m_Type == 2) &&
				(m_GridType[i][j + 8].m_Type == 2))
			{
				std::cout << "백돌승리" << std::endl;
				m_GameWin = 1;
			
			}

			//세로
			if ((m_GridType[i][j].m_Type == 2) &&
				(m_GridType[i + 1][j].m_Type == 2) &&
				(m_GridType[i + 2][j].m_Type == 2) &&
				(m_GridType[i + 3][j].m_Type == 2) &&
				(m_GridType[i + 4][j].m_Type == 2))
			{
				std::cout << "백돌승리" << std::endl;
				m_GameWin = 1;
		
			}

			//왼대
			if ((m_GridType[i][j].m_Type == 2) &&
				(m_GridType[i + 1][j + 2].m_Type == 2) &&
				(m_GridType[i + 2][j + 4].m_Type == 2) &&
				(m_GridType[i + 3][j + 6].m_Type == 2) &&
				(m_GridType[i + 4][j + 8].m_Type == 2))
			{
				std::cout << "백돌승리" << std::endl;
				m_GameWin = 1;
			
			}

			//오대
			if (j > 7)
			{
				if ((m_GridType[i][j].m_Type == 2) &&
					(m_GridType[i + 1][j - 2].m_Type == 2) &&
					(m_GridType[i + 2][j - 4].m_Type == 2) &&
					(m_GridType[i + 3][j - 6].m_Type == 2) &&
					(m_GridType[i + 4][j - 8].m_Type == 2))
				{
					std::cout << "백돌승리" << std::endl;
					m_GameWin = 1;
			
				}
			}
			

		}

	}
}

void GameEngine::Clear()
{
	system("cls");

	GameInit();
	m_Om->OmokMap(m_Colum, m_Row);
	m_GameWin = 0;
}

void GameEngine::MouseInit()
{
	 handle = GetStdHandle(STD_INPUT_HANDLE);
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
}

//ff








