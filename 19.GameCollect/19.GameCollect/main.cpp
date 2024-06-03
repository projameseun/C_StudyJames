
#include <iostream>
#include <time.h>

/*
1 ~ 9 사이의 랜덤한 숫자 3개를 중복 없이 얻어온다.
만약 랜덤하게 얻어온 숫자가 8, 3, 9 일 경우

그 후에 무한으로 반복을 한다.
사용자는 3개의 숫자를 입력한다.
1, 2, 4 를 입력했다면 중복되는 숫자가 아예 없으므로  Out을 출력한다.
8, 4, 5 를 입력했다면 8은 숫자도 같은게 있는데 자리까지 같으므로 strike로 처리한다.
나머지는 없으므로 1strike 0ball 을 출력한다.
이런식으로 숫자가 같은데 자리까지 같다면 strike추가 자리가 다르다면 ball로 추가해서
표시해준다.
모든 숫자를 자리까지 맞췄다면 게임이 종료된다.
*/
int main()
{
	srand((unsigned int)time(0));
	rand();

	int	iNumber[9] = {};

	for (int i = 0; i < 9; ++i)
	{
		iNumber[i] = i + 1;
	}

	int	iTemp, idx1, idx2;
	for (int i = 0; i < 50; ++i)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (true)
	{
		//std::cout << iNumber[0] << "\t" <<
		//	iNumber[1] << "\t" << iNumber[2] << std::endl;
		std::cout << "*\t*\t*" << std::endl;
		std::cout << "숫자 3개를 입력하세요(0 : 종료) : ";

		int	iInput[3] = {};

		std::cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 ||
			iInput[2] == 0)
			break;

		int	iStrike = 0, iBall = 0;

		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (iNumber[i] == iInput[j])
				{
					if (i == j)
						++iStrike;

					else
						++iBall;
					break;
				}
			}
		}

		if (iStrike == 3)
		{
			std::cout << "숫자를 모두 맞췄습니다." << std::endl;
			break;
		}

		else if (iStrike == 0 && iBall == 0)
			std::cout << "Out!!" << std::endl;

		else
			std::cout << iStrike << "Strike " << iBall << "Ball" << std::endl;
	}

	return 0;
}
