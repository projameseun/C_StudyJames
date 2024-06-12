#include <iostream>


//void swap(int a, int b)
//{
//	int iTemp = 0;
//
//	iTemp = a; 
//	a = b;
//	b = iTemp;
//}

void swap(int* a ,int* b)
{
	int iTemp = 0;

	iTemp = *a;
	*a = *b;
	*b = iTemp;
}

void swap(int& a, int& b)
{
	int iTemp = 0;

	iTemp = a;
	a = b;
	b = iTemp;
}





int main()
{
	//Call by Value Call by Reference
	//call by value�� ���� ���ڷ� �����ϴ� �Լ��� ȣ����
	//���� ����Ǽ� ���޵Ǳ⶧���� �Լ� ������ ���� �����ص� �������� ������� �ʴ´�.

	//Reference �� �ּ� ���� ���ڷ� �����ϴ� �Լ��� ȣ���� 
	//�Լ��� ���ڷ� ���޵Ǵ� ���� ������ �ּ��̹Ƿ�, �Լ� ������ ������ ���� �����ϸ� �ش� �ּҿ� ����� ���� ������ �ȴ�.


	int iNum1 = 50;
	int iNum2 = 100;

	std::cout << "======== ���� �ϱ��� =======" << std::endl;
	std::cout << "iNum1 = " << iNum1 << std::endl;
	std::cout << "iNum2 = " << iNum2 << std::endl;


	//swap(50, 100);
	//swap(&iNum1, &iNum2); 
	swap(iNum1, iNum2);	//reference���

	std::cout << "======== ������ =======" << std::endl;
	std::cout << "iNum1 = " << iNum1 << std::endl;
	std::cout << "iNum2 = " << iNum2 << std::endl;


	int iNum3 = 200;

	
	//���۷����� �����ʹ� �Ѵ� c++���� �������� ����ϸ鼭 ���� ���̰� �ִ�
	//���۷��� 
	/*
		1.���۷����� ���� �� �ݵ�� �ʱ�ȭ�� �Ǿ�� �Ѵ�.
		2.���۷����� �ʱ�ȭ ���� �ٸ� ������ ����ų�� ����.
		3.���۷����� ���� ���������� �����ؼ� �����Ҽ� �ִ� �����Ϳ� �޸� �ּ� �����ڸ� ����� �ʿ䰡����.
		4.NULL���� ����. ���۷����� NULL���� ���������� �׻� ��ȿ�� ������ �����Ѿߵȴٴ� ���̴� .

		�����ʹ� NULL,nullptr�� ������ �ִµ� �̴� �����Ͱ� � ��ȿ�� ������ ����Ű�� �ʴ´ٴ°��� �ǹ��Ѵ�.
	
	*/

	//int& ref = nullptr; �Ұ���
	
	int a = 100;
	int b = 200;
	int c = 300;



	int& ref = a;

	ref = b; // ref�� a�� �����ϰ� �ֱ� ������ a�� ���� b�� ����

	std::cout << "&a: " << &a << std::endl;
	std::cout << "&b: " << &b << std::endl;
	std::cout << "&ref: " << &ref << std::endl;

	b = 500;


	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "ref: " << ref << std::endl;



	return 0;
}