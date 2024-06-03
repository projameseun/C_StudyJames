#include <iostream>
#include <time.h>
#include <Windows.h>

int iPlayer[25] = {};

int iAI[25]; 

int iPBingo = 0;
int iAIBingo = 0;

int iSelectMode = 0;

int iInput = 0;

enum class LN_NUMBER
{
	LN_W1,
	LN_W2,
	LN_W3,
	LN_W4,
	LN_W5,

	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,

	LN_LD,  //왼쪽 대각
	LN_RD,  //오른쪽 대각
	
};

enum class AIMODE
{
	EASY = 1,
	HARD ,
};

void GameModeSelect()
{
	while (true)
	{
		system("cls");

		std::cout << "게임 모드를 선택해주세요 " << std::endl;
		std::cout << "1. EASY MODE" << std::endl;
		std::cout << "2. HARD MODE" << std::endl;

		std::cin >> iSelectMode;

		if (iSelectMode == (int)AIMODE::EASY)
		{
			iSelectMode = (int)AIMODE::EASY;
			break;
		}
		else if (iSelectMode == (int)AIMODE::HARD)
		{
			iSelectMode = (int)AIMODE::HARD;

				break;
		}
		else
		{
			continue;
		}
	}
}



void Init()
{
	for (int i = 0; i < 25; ++i)
	{
		iPlayer[i] = i + 1;
		iAI[i] = i + 1;
	}



}

void Shuffule()
{
	int iTemp, idx1, idx2 = 0;

	for (int i = 0; i < 1000; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iPlayer[idx1];
		iPlayer[idx1] = iPlayer[idx2];
		iPlayer[idx2] = iTemp;

		//AI추가

		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAI[idx1];
		iAI[idx1] = iAI[idx2];
		iAI[idx2] = iTemp;
		
	}
}

void BingoCheck()
{
	//CHECK

		//별로 바뀐줄을 체크한다 
		//가로 5줄 세로 5줄 대각선 2줄 이 존재한다.
		//이중에 5줄이상을 완성하면 게임에서 승리 
		//

		//가로줄을 구한다

	int iCheck1 = 0;
	int iCheck2 = 0;

	int iAICheck1 = 0;
	int iAICheck2 = 0;


	iPBingo = 0;
	iAIBingo = 0;

	for (int i = 0; i < 5; ++i)
	{
		iCheck1 = 0;
		iCheck2 = 0;

		iAICheck1 = 0;
		iAICheck2 = 0;

		for (int j = 0; j < 5; ++j)
		{
			//가로줄
			if (iPlayer[i * 5 + j] == INT_MAX)
			{
				++iCheck1;
			}

			if (iAI[i * 5 + j] == INT_MAX)
			{
				iAICheck1++;
			}
			//세로줄
			if (iPlayer[j * 5 + i] == INT_MAX)
			{
				++iCheck2;
			}
			if (iAI[j * 5 + i] == INT_MAX)
			{
				++iAICheck2;
			}
		}

		//여기서 check가 값이 5라면 한줄이 모두 별로 바뀐것이다
		if (iCheck1 == 5)
		{
			++iPBingo;
		}
		if (iCheck2 == 5)
		{
			++iPBingo;
		}

		if (iAICheck1 == 5)
		{
			++iAIBingo;
		}
		if (iAICheck2 == 5)
		{
			++iAIBingo;
		}


	}

	iCheck1 = 0;

	iAICheck1 = 0;

	//대각선 
	for (int i = 0; i < 25; i += 6)
	{
		if (iPlayer[i] == INT_MAX)
		{
			++iCheck1;
		}
		if (iAI[i] == INT_MAX)
		{
			++iAICheck1;
		}
	}

	if (iCheck1 == 5)
	{
		++iPBingo;
	}
	if (iAICheck1 == 5)
	{
		++iAIBingo;
	}


	iCheck1 = 0;

	iAICheck1 = 0;

	for (int i = 0; i < 5; ++i)
	{
		if (iPlayer[i * 4 + 4] == INT_MAX)
		{
			++iCheck1;
		}
		if (iAI[i * 4 + 4] == INT_MAX)
		{
			++iAICheck1;
		}
	}

	if (iCheck1 == 5)
	{
		++iPBingo;
	}

	if (iAICheck1 == 5)
	{
		++iAIBingo;
	}
}

void AICheck()
{
	int iCheckCount = 0;
	int iSaveCount = 0;
	int iLine = 0;

	//가줄체크
	for (int i = 0; i < 5; ++i)
	{
		iCheckCount = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (iAI[i * 5 + j] == INT_MAX)
			{
				++iCheckCount;
			}
		}//for (int j = 0; j < 5; ++j)

		if (iCheckCount < 5 && iSaveCount < iCheckCount)
		{
			iLine = i;
			iSaveCount = iCheckCount;

		}

		
	}//for (int i = 0; i < 5; ++i)

	//세로줄체크

	for (int i = 0; i < 5; ++i)
	{
		iCheckCount = 0;
		for (int j = 0; j < 5; ++j)
		{
			if (iAI[j * 5 + i] == INT_MAX)
			{
				++iCheckCount;
			}
		}//for (int j = 0; j < 5; ++j)

		if (iCheckCount < 5 && iSaveCount < iCheckCount)
		{
			iLine = i + 5;
			iSaveCount = iCheckCount;

		}


	}//for (int i = 0; i < 5; ++i)

	iCheckCount = 0;

	//왼대
	for (int i = 0; i < 25; i+=6)
	{
		if (iAI[i] == INT_MAX)
		{
			++iCheckCount;
		}
	}

	if (iCheckCount < 5 && iSaveCount < iCheckCount)
	{
		iLine = (int)LN_NUMBER::LN_LD;
		iSaveCount = iCheckCount;
	}

	iCheckCount = 0;
	//오대
	for (int i = 4; i <= 20; i += 4)
	{
		if (iAI[i] == INT_MAX)
		{
			++iCheckCount;
		}

	}

	if (iCheckCount < 5 && iSaveCount < iCheckCount)
	{
		iLine = (int)LN_NUMBER::LN_RD;
		iSaveCount = iCheckCount;
	}
	

	//여기까지 온건 가장 포인트체크가 가장 많이된 라인을 알게된것이다.
	if (iLine <= (int)LN_NUMBER::LN_W5)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (iAI[iLine * 5 + i] != INT_MAX)
			{
				iInput = iAI[iLine * 5 + i];
			}
		}
	}
	//세로줄
	else if (iLine <= (int)LN_NUMBER::LN_H5)
	{
		for (int i = 0; i < 5; ++i)
		{
			if (iAI[i * 5 +(iLine - 5)] != INT_MAX)
			{
				iInput = iAI[i * 5 + (iLine - 5)];
			}
		}
	}
	//왼대
	else if (iLine == (int)LN_NUMBER::LN_LD)
	{
		for (int i = 0; i < 25; i += 6)
		{
			if (iAI[i] != INT_MAX)
			{
				iInput = iAI[i];
			}
		}
	}

	//오대
	else if (iLine == (int)LN_NUMBER::LN_RD)
	{
		for (int i = 4; i <= 20; i += 4)
		{
			if (iAI[i] != INT_MAX)
			{
				iInput = iAI[i];
			}
		}
	}


	//플레이어 ai INT_MAX넣어주면끝

	for (int i =  0; i < 25; ++i)
	{
		if (iAI[i] == iInput)
		{
			iAI[i] = INT_MAX;
		}
		if (iPlayer[i] == iInput)
		{
			iPlayer[i] = INT_MAX;
		}
	}
	
}


void GameStart()
{




	while (true)
	{
		system("cls");




		std::cout << "<============Player===========>" << std::endl;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (iPlayer[i * 5 + j] == INT_MAX)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED);
					std::cout << "★\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				}
				
				else
				{
					std::cout << iPlayer[i * 5 + j] << "\t";
				}
			}

			std::cout << std::endl;
		}//	for (int i = 0; i < 5; ++i)

		std::cout << "Player빙고줄수 : " << iPBingo << std::endl;

		std::cout << "<============AI===========>" << std::endl;

		//Ai 

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{

				if (iAI[i * 5 + j] == INT_MAX)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					std::cout << "♣\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				}
				else
				{
					std::cout << iAI[i * 5 + j] << "\t";
				}
			}

			std::cout << std::endl;
		}


			std::cout << "AI빙고줄수 : " << iAIBingo << std::endl;

			if (iPBingo >= 5)
			{
				std::cout << "5빙고!!!" << std::endl;
				std::cout << "게임을 종료합니다 " << std::endl;
				break;
			}

			std::cout << "숫자를 입력해주세요(999 : 종료) ";



			
			std::cin >> iInput;

			if (iInput == 999)
				break;

			else if (iInput <= 0 || iInput > 25)
			{
				continue;
			}

			//앞에서 입력한 숫자를 다시 입력했는지 체크를하기위해 bool변수를 이용한다.
			//true로 초기화를 한이유는 중복이 되었다라고 가정을 해둔상태에서
			//아래 for문에서 값을 찾았을 경우 중복이 안된것으로 false로 처리하면 된다
			//아래 for문에서 값을 못찾았다면 이미 입력한 값이라는 것이 이므로
			//중복을 처리하기 위해서이다.

			bool bAcc = true;

			//우리가 입력한 숫자를 ★로 변경해 준다.
			for (int i = 0; i < 25; ++i)
			{
				//내가 입력한 숫자가 있을경우
				if (iPlayer[i] == iInput)
				{
					iPlayer[i] = INT_MAX;
					
					bAcc = false;
					
				}
				if (iAI[i] == iInput)
				{
					iAI[i] = INT_MAX;
				}
				
			}

			//값이 중복이 되어있다면 다시입력 받게 한다
			if (bAcc)
				continue;

			//AI차례...

			switch ((AIMODE)iSelectMode)
			{
			case AIMODE::EASY:
				while (true)
				{
					int i = rand() % 25;
					if(iAI[i] == INT_MAX)
					{
						continue;
					}
					if (iAI[i] != INT_MAX)
					{
						iInput = iAI[i];
						break;
					}
				}

				for (int i = 0; i < 25; ++i)
				{
					if (iInput == iPlayer[i])
					{
						iPlayer[i] = INT_MAX;
						bAcc = false;
					}
					if (iInput == iAI[i])
					{
						iAI[i] = INT_MAX;
					}
				}

				break;
			case AIMODE::HARD:
			{
				
				AICheck();
				


			}
				



				break;
			default:
				break;
			}

			//check
			BingoCheck();


		}
	}







int main()
{
	srand(static_cast<unsigned int>(time(NULL)));

	/*
		빙고게임
		5 x 5 로 화면에 빙고판출력 하고 숫자 입력 한다


	*/

	GameModeSelect(); //MODE설정

	Init();

	Shuffule();

	GameStart();




	//숙제 aI만들어오세요 
	//이것도 됫다... AI머리가 좋아지게 






	return 0;
}