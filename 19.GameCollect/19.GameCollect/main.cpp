
#include <iostream>
#include <time.h>

/*
1 ~ 9 ������ ������ ���� 3���� �ߺ� ���� ���´�.
���� �����ϰ� ���� ���ڰ� 8, 3, 9 �� ���

�� �Ŀ� �������� �ݺ��� �Ѵ�.
����ڴ� 3���� ���ڸ� �Է��Ѵ�.
1, 2, 4 �� �Է��ߴٸ� �ߺ��Ǵ� ���ڰ� �ƿ� �����Ƿ�  Out�� ����Ѵ�.
8, 4, 5 �� �Է��ߴٸ� 8�� ���ڵ� ������ �ִµ� �ڸ����� �����Ƿ� strike�� ó���Ѵ�.
�������� �����Ƿ� 1strike 0ball �� ����Ѵ�.
�̷������� ���ڰ� ������ �ڸ����� ���ٸ� strike�߰� �ڸ��� �ٸ��ٸ� ball�� �߰��ؼ�
ǥ�����ش�.
��� ���ڸ� �ڸ����� ����ٸ� ������ ����ȴ�.
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
		std::cout << "���� 3���� �Է��ϼ���(0 : ����) : ";

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
			std::cout << "���ڸ� ��� ������ϴ�." << std::endl;
			break;
		}

		else if (iStrike == 0 && iBall == 0)
			std::cout << "Out!!" << std::endl;

		else
			std::cout << iStrike << "Strike " << iBall << "Ball" << std::endl;
	}

	return 0;
}
