#include <iostream>
#include <stdio.h>

int main()
{
	//c++ ����¹��
	std::cout << "Hellow Word\n";

	int iNum = 0;

	//std::cin >> iNum;

	//C��� ����� ���
	printf("�ȳ��ϼ���\n");
	printf("�氩���ϴ�\n");
	printf("ProJamesEun\n");

	iNum = 10;

	float fNum = 3.14f;

	printf("James Hellow%d", iNum);
	printf("James Hellow%.1f\n",fNum);


	//c��� �Է�
	//�ּ� & 
	scanf_s("%d", &iNum);

	std::cout << "iNum = " << iNum << std::endl;

	scanf_s("%f", &fNum);

	std::cout << "fNum = " << fNum << std::endl;

	return 0;
}