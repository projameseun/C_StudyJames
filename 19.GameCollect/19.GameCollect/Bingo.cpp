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

	LN_LD,  //���� �밢
	LN_RD,  //������ �밢
	
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

		std::cout << "���� ��带 �������ּ��� " << std::endl;
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

		//AI�߰�

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

		//���� �ٲ����� üũ�Ѵ� 
		//���� 5�� ���� 5�� �밢�� 2�� �� �����Ѵ�.
		//���߿� 5���̻��� �ϼ��ϸ� ���ӿ��� �¸� 
		//

		//�������� ���Ѵ�

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
			//������
			if (iPlayer[i * 5 + j] == INT_MAX)
			{
				++iCheck1;
			}

			if (iAI[i * 5 + j] == INT_MAX)
			{
				iAICheck1++;
			}
			//������
			if (iPlayer[j * 5 + i] == INT_MAX)
			{
				++iCheck2;
			}
			if (iAI[j * 5 + i] == INT_MAX)
			{
				++iAICheck2;
			}
		}

		//���⼭ check�� ���� 5��� ������ ��� ���� �ٲ���̴�
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

	//�밢�� 
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

	//����üũ
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

	//������üũ

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

	//�޴�
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
	//����
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
	

	//������� �°� ���� ����Ʈüũ�� ���� ���̵� ������ �˰ԵȰ��̴�.
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
	//������
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
	//�޴�
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

	//����
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


	//�÷��̾� ai INT_MAX�־��ָ鳡

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
					std::cout << "��\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				}
				
				else
				{
					std::cout << iPlayer[i * 5 + j] << "\t";
				}
			}

			std::cout << std::endl;
		}//	for (int i = 0; i < 5; ++i)

		std::cout << "Player�����ټ� : " << iPBingo << std::endl;

		std::cout << "<============AI===========>" << std::endl;

		//Ai 

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{

				if (iAI[i * 5 + j] == INT_MAX)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
					std::cout << "��\t";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
				}
				else
				{
					std::cout << iAI[i * 5 + j] << "\t";
				}
			}

			std::cout << std::endl;
		}


			std::cout << "AI�����ټ� : " << iAIBingo << std::endl;

			if (iPBingo >= 5)
			{
				std::cout << "5����!!!" << std::endl;
				std::cout << "������ �����մϴ� " << std::endl;
				break;
			}

			std::cout << "���ڸ� �Է����ּ���(999 : ����) ";



			
			std::cin >> iInput;

			if (iInput == 999)
				break;

			else if (iInput <= 0 || iInput > 25)
			{
				continue;
			}

			//�տ��� �Է��� ���ڸ� �ٽ� �Է��ߴ��� üũ���ϱ����� bool������ �̿��Ѵ�.
			//true�� �ʱ�ȭ�� �������� �ߺ��� �Ǿ��ٶ�� ������ �صл��¿���
			//�Ʒ� for������ ���� ã���� ��� �ߺ��� �ȵȰ����� false�� ó���ϸ� �ȴ�
			//�Ʒ� for������ ���� ��ã�Ҵٸ� �̹� �Է��� ���̶�� ���� �̹Ƿ�
			//�ߺ��� ó���ϱ� ���ؼ��̴�.

			bool bAcc = true;

			//�츮�� �Է��� ���ڸ� �ڷ� ������ �ش�.
			for (int i = 0; i < 25; ++i)
			{
				//���� �Է��� ���ڰ� �������
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

			//���� �ߺ��� �Ǿ��ִٸ� �ٽ��Է� �ް� �Ѵ�
			if (bAcc)
				continue;

			//AI����...

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
		�������
		5 x 5 �� ȭ�鿡 ��������� �ϰ� ���� �Է� �Ѵ�


	*/

	GameModeSelect(); //MODE����

	Init();

	Shuffule();

	GameStart();




	//���� aI���������� 
	//�̰͵� �̴�... AI�Ӹ��� �������� 






	return 0;
}