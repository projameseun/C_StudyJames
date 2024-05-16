#include <iostream>
#include <time.h>


int main()
{
	//srand((unsigned int)time(NULL));
	srand(static_cast<unsigned int>(time(NULL)));

	/*
		����(�������� ��)
		��ǻ�ʹ� �����̶�� ���� ����� ����.
		�����̶� �������� ���� ������ �ϴ°ǵ� �� �������� ���� ���ǽ������� ���� �Ҽ� ���� ������ ��ǻ�ʹ� ������ ����� ����.
		�׷��Ƿ�, ��ǻ�ʹ� ��ġ ����ó�� ���̴� ������ �Է¿� ���� ��Ÿ���� �ִ�
		��ǻ�Ͱ� ����� �� ������ ���� ����� ���ؼ� ������� ���� ��ġ �����ǰ��� ����ó�� ���̰� �ϴ°Ŵ�.

		rand()
		�������� �������̺��̶� ���� �����ϰ� �̸� �����ϴ°Ŵ�.
		rand()�Լ��� ���ο� RAND_MAX #define���� ���ǰ� �Ǿ� �ְ� �̼��ڴ� 16������ �Ǿ� �ִµ�, 10������ �ٲٰ� �Ǹ� 32,767���� �Ǿ� �ִ�.
		�ᱹ rand()�Լ��� ǥ���Ҽ� �ִ� return���� 0~32,767���� ���´�.
		rand�Լ��� ���α׷��� ����ɶ� ���� �� �������� ������ ���α׷��� ������ ������ ���ѵ� ������ ���� ���´�.
	*/

	//std::cout << "1 rand: " << rand() << std::endl;
	//std::cout << "2 rand: " << rand() << std::endl;
	//std::cout << "3 rand: " << rand() << std::endl;
	//std::cout << "4 rand: " << rand() << std::endl;
	//std::cout << "5 rand: " << rand() << std::endl;

	/*
		rand�Լ������δ� ǥ���Ҽ� ���⶧���� ������ �Ȱ� srand(�õ尪)�Լ� �̴�.
		srand(seed��)
		srand�� rand�Լ��� ���� ���� �ʱ�ȭ �Ѵ�.�� �ʱ�ȭ�� �Ű������� �޴� seed���� �̿��ؼ� ����Ѵ�.
		�Ʒ����� srand������ ���尡 �ʱ�ȭ�� ������ seed���� �����ϸ� �ᱹ �Ȱ��� ���� �ݺ��Ǳ� ������ �츮�� ���ϴ� ������ �ƴϴ�.
	*/

	//srand(5000);
	//std::cout << "rand :" << rand() << std::endl;
	//srand(5000);
	//std::cout << "rand :" << rand() << std::endl;
	//srand(6000);
	//std::cout << "rand :" << rand() << std::endl;
	//srand(200);
	//std::cout << "rand :" << rand() << std::endl;

	/*
		seed ���� ��Ӻ��Ҽ� �ִٸ� rand()�Լ��� ��� �ٸ� ���� ����Ҽ� �������̴� .
		�׷��� ������ �Ȱ� time�ð� �Լ��̴�
		time�Լ�
		UCT(1972�� 1�� 1�� 0�� 0�ʺ��� ����� ���� ǥ�ؽ�) �̽ð��� ���������� ��ȯ���ִ� �Լ��� time�Լ��̴�.
		���: seed���ȿ� time�̶�� �ð��Լ��� �־��ش�


	*/

	//srand((unsigned int)time(NULL));
	//srand(static_cast<unsigned int>(time(NULL)));
	//std::cout << time(0) << std::endl;
	//std::cout << "1.rand :" << rand() << std::endl;
	//std::cout << "2.rand :" << rand() << std::endl;
	//std::cout << "3.rand :" << rand() << std::endl;
	//std::cout << "4.rand :" << rand() << std::endl;
	//std::cout << "5.rand :" << rand() << std::endl;

	//�츮�� ������ ������ ���ھȿ��� ������ �������� �ϰ�ʹ�.
	//�̶� ����ϴ°� ������ �������̴�.
	//� ū���ڰ� �͵� ������ �����ڸ� ����ϸ� ���� ���ϴ� ������ ���� ��Ÿ���� �ִ�.
	//�̺κ��� ���ذ� �ȵȴٸ� �������ڸ� �־ �׽�Ʈ�غ��� �ٷ� �˼��ִ�.

	////0~2������ �����ǳ��´�
	///*int iRand = rand() % 3;*/
	//std::cout << iRand << std::endl;

	////0~99������ �������Ѵ�
	//iRand = rand() % 100;

	////1~100������ �������Ѵ�
	//iRand = rand() % 100 + 1;		//0 ~99 �����Եȴ� 

	////100 ~ 199 ������ �������Ѵ�

	//iRand = rand() % 100 + 100;	

	//float fRand = rand() % 10000 / 100.f;	//�Ҽ��� ��°�ڸ��� ���ڸ� ����Ҽ��� �ִ�.
	//std::cout << "Rand :" << fRand << std::endl;

	//�ּ� ���ݷ� �ִ� ���ݷ�
	//500~1000
	//int iMin = 500;
	//int iMax = 1000;

	//0 ~500���� ������ �ؾߵȴ�. 

	/*if (fRand < 1.f)
	{
		std::cout << "������ ȹ�� " << std::endl;
	}
	else if (fRand < 50.f)
	{
		std::cout << "���� ȹ�� " << std::endl;
	}
	else if (fRand < 60.f)
	{
		std::cout << "��� ȹ�� " << std::endl;
	}
	else if (fRand < 70.f)
	{
		std::cout << "�Ϲ� ȹ�� " << std::endl;
	}
	else
	{
		std::cout << "������ ���� " << std::endl;
	}*/

	int iMax = 1000;
	int iMin = 500;

	int iRand = (rand() % (1000 - 500 + 1)) + 500;

	std::cout << iRand << std::endl;

	return 0;
}