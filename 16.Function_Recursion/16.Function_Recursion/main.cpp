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

//���丮�� ����Լ�
int Factorial_Re(int _Count)
{
	if (_Count == 1)
	{
		return 1;
	}
	return _Count * Factorial_Re(_Count - 1);
}


//�Ǻ���ġ����
//1 1 2 3 5 8 13 21 34 55 89
int Fibonacci(int _Num)
{
	int iPreNum = 1;
	int iPreNum2 = 1;

	int iResult = 0;

	if (_Num == 2 || _Num == 1)
	{
		return 1;
	}

	for (int i = 0; i < _Num - 2; ++i)
	{
		iResult = iPreNum + iPreNum2;

		//������ �߸��ϸ� �̻��� ���� ���� �ȴ�.
		//iPreNum2 = iResult;
		//iPreNum = iPreNum2;

		iPreNum = iPreNum2;
		iPreNum2 = iResult;
	}




	return iResult;
}

//�Ǻ���ġ���� ����Լ�
int Fibonacci_Re(int _Num)
{
	if (_Num == 2 || _Num == 1)
	{
		return 1;
	}
	//1 1 2 3 5 8 13 21 34 55 89
	return Fibonacci_Re(_Num - 1) + Fibonacci_Re(_Num - 2);
}


//�������
//����ȭ ����� �ϳ��̴� ������ �÷����� �°� ������ ����ߵȴ�.
//����Լ��� ���ÿ� ���ΰ� ��ȯ�Ҷ� �߰� ������ ������ ������ʹ� �����ʴ´�

int FactorialTraill(int n, int acc) // acc : accumulator�� ����
{
	if (n == 1)
	{
		return acc;
	}

	return FactorialTraill(n - 1, acc * n); //�Ϲ� ��Ϳ����� n* Factorial(n - 1)�� �޸� ��ȯ������ �߰� ������ �ʿ�� ��������
}

int FactorialTest(int n)
{
	return FactorialTraill(n, 1);
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


	//���丮�� ����Լ�
	iValue = Factorial_Re(3);
	std::cout << "FactorialRe:" << iValue << std::endl;
	//���丮�� ����Լ�
	
	//�Ǻ���ġ����
	//1 1 2 3 5 8 13 21 34 55 89
	iValue = Fibonacci(10);
	std::cout << "Fibonacci:" << iValue << std::endl;
	//�Ǻ���ġ����


	//�Ǻ���ġ���� ����Լ�
	iValue = Fibonacci_Re(5);
	std::cout << "Fibonacci_Re:" << iValue << std::endl;
	//�Ǻ���ġ���� ����Լ�

	//�������
	iValue = FactorialTest(4);
	std::cout << "FactorialTraill_Re:" << iValue << std::endl;

	//������� �������Ѱ� https://bozeury.tistory.com/entry/%EA%BC%AC%EB%A6%AC-%EC%9E%AC%EA%B7%80-%EC%B5%9C%EC%A0%81%ED%99%94Tail-Recursion


	return 0;
}