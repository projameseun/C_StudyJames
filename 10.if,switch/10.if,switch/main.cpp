#include <iostream>

int main()
{
	/*
		���ǹ�:if , switch
		���ǹ��̶�? � Ư�� ���ǽ��� �ο��ϰ� �ش� ������ �����ϸ� ������ ������ �����ϴ� ����
		if��
		if(���ǽ�)
		{

		}�ڵ��
		
		���ǽ���  true�� ��� �ڵ���� �۵��� �ǰ�, false�� if���ǹ��� ������ �ȴ�.

	*/
	
	if (true)
	{
		std::cout << "���� �Դϴ�" << std::endl;
	}
	if (false)
	{
		std::cout << "���� �Դϴ�" << std::endl;
	}

	/*
		else : if���� ���� ���� �ִ�.
		if�� 1���� 1���� else�� �ü� �ִ�.
		else ���������� ����� �Ұ��� �ϴ�.

	*/

	int iNumber = 100;

	if (iNumber == 100)
	{
		std::cout << "iNumber = " << iNumber << std::endl;
	}
	else
	{
		std::cout << "iNumber�� 100�� �ƴմϴ�" << std::endl;
	}
	
	/*
		else if: if�� �Ʒ��ü� �ִ�. else�� �ٸ��� �������� ����� �ִ�.
		else if�� ���������� ����� �Ұ��� �ϴ�.
	*/

	//������� �ν�Ʈ��ũ
	//int iEchidnaHP = 100000000;

	//if (iEchidnaHP == 100000000)
	//{
	//	//ù��° �̺�Ʈ �߻�
	//	std::cout << "1��° �̺�Ʈ �߻�" << std::endl;
	//}
	//else if (iEchidnaHP < 800000 && iEchidnaHP > 50000)
	//{
	//	std::cout << "2��° �̺�Ʈ �߻�" << std::endl;
	//}
	//else if (iEchidnaHP < 50000 && iEchidnaHP > 13000)
	//{
	//	std::cout << "3��° �̺�Ʈ �߻�" << std::endl;
	//}
	//else if (iEchidnaHP < 13000 && iEchidnaHP > 1200)
	//{
	//	std::cout << "4��° �̺�Ʈ �߻�" << std::endl;
	//}
	//else
	//{
	//	std::cout << "5��° �̺�Ʈ �߻�" << std::endl;
	//}
	
	//�л���� ���α׷�

	int iKor = 0;
	int iEng = 0;
	int iMath = 0;
	int iTotal = 0;


	//�Ҽ��� �ڸ��� ���� float�ϰ�쿡�� .f�� ������ 0�� �����Ҽ� �ִ� ex) 1.0f == 1.f;
	float fAvg = 0.f;
	//���(Average)
	// ȭ���� �ƿ� ������ ����� �Լ� Winodws.h ������ �ʿ��ϴ�
	system("cls");

	std::cout << "�������� : ";
	std::cin >> iKor;
	system("cls");
	std::cout << "�������� : ";
	std::cin >> iEng;
	system("cls");
	std::cout << "�������� : ";
	std::cin >> iMath;
	system("cls");

	std::cout << iKor << std::endl;
	std::cout << iEng << std::endl;
	std::cout << iMath << std::endl;

	iTotal = iKor + iEng + iMath;

	fAvg = iTotal / 3.f;

	std::cout << "��� : " << static_cast<int>(fAvg) << "�Դϴ�" << std::endl;


	if (fAvg >= 90.f)
	{
		std::cout << "���ϵ帳�ϴ� A�����Դϴ�." << std::endl;
	}
	//����� 80���� ũ�ų� ���� ����� 90���� ������  //  80 ~ 89
	else if (fAvg >= 80.f && fAvg < 90.f)
	{
		std::cout << "���ϵ帳�ϴ� B�����Դϴ�." << std::endl;
	}
	else if (fAvg >= 70.f && fAvg < 80.f)
	{
		std::cout << "���ϵ帳�ϴ� C�����Դϴ�." << std::endl;
	}
	else
	{
		std::cout << "F�����Դϴ�." << std::endl;
	}

	return 0;
}