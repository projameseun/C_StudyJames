#include <iostream>
#include <time.h>
#include <algorithm>


bool iCompare(int a, int b)
{
	return a < b; //��������
	//return a > b; ��������
}

int main()
{
	/*
		�迭:���� �ڷ����� ���� �������� �ѹ��� �����Ҽ� �ִ� ���ִ� ����̴�.
		�迭�� Ư¡ �޸𸮰� ���������� �����ִ�.

		����Ÿ�� �迭��[����] ������ ����� �����ϴ�.
		�� ���·� �����ȴ�. 

		�迭�� ��������
		������ �޸𸮸� ���鶧 �Ȱ��� �����͸� �׷����� ��� ǥ���Ҷ� �迭 ������ ����Ѵ�.
		
		
	*/
	
	//�л����α׷��������
	int iStudent[100];
	//��ó�� ����� �Ǹ� �л� 100���� �����Ҽ� �ִ� �޸𸮰� �����Ȱ��̴�.
	//400byte���� ����� �Ǵ°��̴�.
	//�� ��ҿ� �����ϱ� ���ؼ� ����ϴ� ���� �ε����̴�.
	//�ε����� 0 ~~ ���� -1 �����̴�.

	//�迭 �ʱ�ȭ
	int iNum[10] = {}; // ��� 0 ���� �ʱ�ȭ �Ѵ�
	//int iNum[10] = { 0, };
	//int iNum[10] = { 0,0,0,0,0,0,0,0,0,0 };

	int iNum2[] = { 1,299,300,500,20,10 };	//6���� �ʱ�ȭ �Ѵ�.

	int iArray[10] = { 1,2,3 };
	//��ó�� �ʱ�ȭ�� �ϰ� �Ǹ� 0, 1, 2 �� �ε����� 1,2,3���� ���� �ǰ� �������� 0 ���� �ʱ�ȭ �ȴ�.

	iArray[0] = 20;
	iArray[5] = 100;

	//�迭 ���� ���� = sizeof(�迭��) / sizeof(�ڷ���);
	size_t iSize = 0; //typedef unsigned int 

	std::cout << "iArray : " << sizeof(iArray) << std::endl; //4byte * 10 = 40

	iSize = sizeof(iArray) / sizeof(int); //�迭�� ������ ���Ѱ���
	
	std::cout << "Size = " << iSize << std::endl;

	for (int i = 0; i < iSize; ++i)
	{
		iArray[i] = i + 1;
	}

	for (int i = 0; i < iSize; ++i)
	{
		std::cout << "iAraay[";
		std::cout << i << "]" << iArray[i] << std::endl;
	}
	
	float fArray[100] = { 0.f };

	std::cout << "fArray : " << sizeof(fArray) << std::endl;

	//���ڿ� �迭 
	char data[6] = { 'H','A','P','P','Y'};		//���ڿ��� ���� NULL ,0���� ǥ���Ѵ� �̷��� �����Ϸ��� �̹迭�� ����� ������ ���ڿ��̶�°��� �˼� �ִ�.
	char data2[6] = "Happy";

	char data3[25] = "�ȳ��ϼ���"; //�ѱ��� 2����Ʈ ����� 1����Ʈ 

	std::cout << data << std::endl;
	std::cout << data2 << std::endl;
	std::cout << data3 << std::endl;
	
	system("cls");

	//�ζ� ���α׷�
	//1~45������ ������ ������ 6���� ���ڸ� �����´�
	//���� �ߺ��Ǹ� �ȵȴ�.
	//��������, ��������

	int iLotto[45] = {};

	iSize = sizeof(iLotto) / sizeof(int);

	for (int i = 0; i < iSize; ++i)
	{
		iLotto[i] = i + 1;
	}

	srand(static_cast<unsigned int>(time(NULL)));

	//Shffule
	int iTemp, idx1, idx2 = 0;

	for (int i = 0; i < 5000; ++i)
	{
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}
	
	iTemp = 0;
	//���� ���� �������� ����
	//���� ū���ں��� �߳������°Ű� , ������ �������ں��� �ö󰣴�

	//STL(Standdard ���̺귯��)
	
	//�������� ������������ �������ִ°Ŵ�
	// sort(array.begin(), array.end(), compare);c
	//std::sort(iLotto, iLotto+ 6); //2��°�� �������ּҸ� ����Ű�°Ŵ� �츰�������� �����Ŵϰ� 6���������� 
	std::sort(iLotto, iLotto +6, iCompare); //compare�� ���� ����������� �Ϲ������� �����������Ѵ�

	/*for (int i = 0; i < 5; ++i)
	{
		for (int j = i + 1; j < 6; ++j)
		{
			if (iLotto[i] > iLotto[j])
			{
				iTemp = iLotto[i];
				iLotto[i] = iLotto[j];
				iLotto[j] = iTemp;
			}
		
		}
	}*/

	for (int i = 0; i < 6; ++i)
	{
		std::cout << iLotto[i] << std::endl;
	}

	return 0;
}