#include <iostream>

struct Student
{
	std::string stName;
	int iScore;
};




int main()
{
	/*
		�����Ҵ�(Dymaic Allocation)�� �޸𸮸� ��Ÿ�ӿ��� ��������
		�������� �Ҵ�,���� �ϴ°��� ���մϴ�.���� ���α׷� ���� �߿�
		�޸𸮸� �Ҵ��ϰ� ���� �� �� �־ �� ������ �޸� ������ �����ϰ� �Ѵ�.
		������� c++�� ���ϸ� �������ִ°� �̺κп��� ���°Ŷ�� ������� ���� �ִ� �ֳ� �޸𸮸� ���� ���� �����Ѵ�.
		
		c- malloc(), calloc() ,relloc() �� ���� �Լ��� ����ؼ� �Ҵ��ϰ�
		free()�� �����Ѵ�.
		
		c++ new�Ҵ��ϰ� 
		delete���� �Ѵ�.

		�����Ҵ��� �ַ� �迭,����ü,��ü(Ŭ����)���� ������ ������ �ٷ궧 �����ϰ�  ���˴ϴ�.
		
		�����Ҵ��� �ϰ� �޸𸮸� ���� ���� �ʰ� �Ǹ� �޸� ����(memory leak)�� ����µ� �̸� �� ������ ����� �ȴ�.
		�޸𸮸� �Ҵ��ϰ� �Ǹ� ������ �޸𸮸� ���� ����� �ȴ�.
		���࿡ �޸𸮸� ���� ������ �ʰ� �Ǹ� ������ �߻��Ͽ� �ý����� �޸� ��뷮�� ����ؼ� �����ϰ� �ǰ�,
		�ᱹ �ý��� ���� ���ϸ� ��ų�� �ְ� �ȴ�.

		�޸𸮸��� üũ�ϴ� �Լ�
		_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	*/
		
	//malloc() 
	/*
		ǥ�ض��̺귯��<stdlib.h> ��� ���Ͽ� ���� �Ǿ� �ֽ��ϴ�.
		malloc �Լ��� ��(heap) �������� �޸� ����� �Ҵ��ϰ�, �ش� �޸� ����� �����͸� ��ȯ �մϴ�.
		
		�ܰ�
		1.��û�� �޸� ũ�⿡ ���� ������ �Ҵ��ϱ� ���ؼ� �ü���� ��û�� �����ϴ�.
		2.�ü���� ��� ������ �� �������� ��û�� �޸� ũ�⿡ �ش��ϴ� ����� ã�� �Ҵ��մϴ�.
		3.�Ҵ�� �޸� ����� �ּҸ� ��ȯ�ϰ�, �ش� �ּҸ� ����Ͽ� �������� �Ҵ�� �޸𸮿� ���� �Ҽ� �ֽ��ϴ�.

		malloc�Լ����� ��� ������ �������� ����� �޸𸮰� ���°�� malloc()�Լ��� nullptr�� ��ȯ�մϴ�.
		�̴� �޸� �Ҵ��� �����ϴ� ��츦 ���Ѵ�.

		
		
		
		


	*/

	//�޸𸮸��� üũ�ϴ� �Լ�
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//int* ptr = (int*)malloc(sizeof(int));
	////���ڵ忡�� �޸� �Ҵ��� �����Ҽ� �ֱ� ������
	////���� ���� ����ó���� ���ָ� �ȴ�.

	//if (ptr == NULL)
	//{
	//	//�޸� �Ҵ����
	//}
	//else
	//{
	//	//�Ҵ缺��
	//}

	//int* ptr = new int;
	//
	//if (ptr = nullptr)
	//{
	//	
	//}
	//else
	//{

	//}

	

	int* ptr = (int*)malloc(sizeof(int));

	*ptr = 200;

	std::cout << "ptr = " << *(ptr) << std::endl;
	
	//���� ����ȯ�� ����ϴ¹��
	*((int*)ptr) = 3.f;

	std::cout << "ptr = " << *(ptr) << std::endl;

	//�޸� ����
	if (nullptr != ptr)
	{
		free(ptr);
	}

	{
		int* ptr = new int;

		*ptr = 300;

		std::cout << "ptr = " << *(ptr) << std::endl;

		if (nullptr != ptr)
		{
			delete ptr;
		}
		

	}

	//�����Ҵ翡 ���� ����..
	int iNum = 0;

	std::cout << "�л��� �Է����ּ��� : ";
	std::cin >> iNum;

	//�Ҵ�
	Student* st = new Student[iNum];

	if (iNum <= 0 || iNum <= 10)
	{
		//�л�����
		for (int i = 0; i < iNum; ++i)
		{
			std::cout << (i + 1) << "�л� �̸� �Է� ";
			std::cin >> st[i].stName;
			std::cout << (i + 1) << "���� �Է� ";
			std::cin >> st[i].iScore;
		}


		float fAvg = 0.f;
		int iTotal = 0;
		for (int i = 0; i < iNum; ++i)
		{
			iTotal += st[i].iScore;
		}

		fAvg = iTotal / iNum;

		std::cout << "��� ���� : " << fAvg << std::endl;

		std::cout << "�л� ����  " << std::endl;
		for (int i = 0; i < iNum; ++i)
		{
			std::cout << "�̸� : " << st[i].stName << "���� : " << st[i].iScore << std::endl;
		}
	}


	
	delete[] st;

	


	return 0;
}