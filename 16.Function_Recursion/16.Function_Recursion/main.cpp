#include <iostream>

/*
	���(Recusion)�Լ���
	�Լ� �ȿ��� �ڱ� �ڽ��� �Լ��� ȣ���ϴ� ���
	����� �Ҷ� ȣ�⽺�ÿ� ����Ŭ���� �ϰ� �Ǹ� �ٸ��ʵ� ���� ����
	
	�Լ��ȿ��� �ڱ� �Լ��� ��� �ҷ�����(����Լ�) ������ �Ѱ�ġ�� �����ϰ� �Ǵµ�
	�̸� ���� �÷ο��� �Ѵ�.
*/


//���丮�� �Լ� for�� 
int Fatorial(int _Cout)
{
	int iValue = 1;

	for (int i = 0; i < _Cout - 1; ++i)
	{
		//iValue = iValue * (i + 2);
		iValue *= (i + 2);
	}

	//�̰� ����Լ��� �´µ� �ɰ��� ������ ����� ���ÿ� ����Լ� �׿��� ���ÿ����÷ο찡 �����.
	//Fatorial(5);

	return iValue;
}




int main()
{
	//���丮���� ���� ������ 4���丮���̸� ���ϴ� Ƚ���� 3���̴�.
	//4! = 1 x 2 x 3 x 4 ���ϱⰡ 3�� 
	
	//���丮�� for���� ���������
	int iFacNum = 4;
	int iValue = 1;

	for (int i = 0; i < iFacNum - 1; ++i)
	{
		//iValue = iValue * (i + 2);
		iValue *= (i + 2);
	}

	std::cout << "FactorialForMun  : " << iValue << std::endl;
	//���丮�� for������ ���������

	//���丮�� for���Լ� 
	iValue = Fatorial(5);
	std::cout << "FatorialForMunFuction : " << iValue << std::endl;

	


	return 0;
}