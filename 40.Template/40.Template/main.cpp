#include <iostream>
#include "CArray.h"

//�����ε��� ���ؼ� �����ڷ����� ���ϱ� �Լ������ ������ִµ�
//���࿡ �̰� �ϳ��� �Լ��� ���ؼ� �ڷ����� �� ��Ȳ�� �°� �������ټ� �ִٸ� ���� ȿ�����̰� ������ϰŴ�
//�̷��� ������ �Ȱ� ���ø��̴�.
//���ø��� ���� Ʋ�̶�� ���� �����ִ�.
//�츮�� ���� ���� �Լ� ���ø��̴�.


//Ŭ���� ���ø��� ���Ǵ� ������Ͽ� ��������� �ȴ�
//������ �����Ϸ��� ���ø� �ν��Ͻ�ȭ�� ����� ó���ϱ� ���ؼ� �ʿ��� �ڵ尡 ������ ���ǿ� ���� ��� ���Ե� ��������� �־�ߵȴ�.
//���ø��� ������ ������ �ƴ� �ν��Ͻ�ȭ ������ ������ �˴ϴ�., �� �����Ϸ��� ���ø��� ��� �ɶ� ������ � Ÿ���� ���ø� �Ű� ������ �������� �˾ƾ� �ȴ�.

//���ø� �ν��Ͻ�ȭ
//���ø��� ��ü���� Ÿ������ ��ȯ�ϴ� ������ ���Ѵ�
//���ø��� Ʋ,���� ���� ������ ��� �Ҷ� �� �� Ʋ�� ��ü���� ������ Ÿ������ ä���� ����ϰ� �Ǵµ� �� ������ �ν��Ͻ�ȭ��� �θ���.

//�ν��Ͻ�
//class�� �Ҽӵ� �������� ��ü�� ���Ѵ�
//ex) User�� Ŭ������ �����ϰ� player��� ��ü�� �����ϰ� �Ǹ� player��� ��ü�� user��� Ŭ������ �ν��Ͻ��� �ȴ�.

template<typename T>
T	Add(T a, T b)
{
	return a + b;
}

//int Add(int a, int b)
//{
//	return a + b;
//}
//
//float Add(float a, float b)
//{
//	return a + b;
//}
//
//char Add(char a, char b)
//{
//	return a + b;
//}

//class�� ����ص��ǰ� typename�� �ص� ������� ���⼭ class�� �츮�� ���ݱ������ Ŭ�������ƴϴ�

template<class T>
void OutPut(T a)
{
	std::cout << a << std::endl;
}

//void IntOutPut(int a)
//{
//	std::cout << a << std::endl;
//}

int main()
{
	//���ø� 
	
	int iNumber = Add<int>(10, 20);
	float fNumber = Add<float>(3.f, 3.f);
	//int iNumber = Add(10, 10);	�����Ϸ��� �ڵ����� ���ְ��ִ� ������ ��ø� �츮�� ��Ȯ�ϰ� ���ִ°� �߿��� ������ �ϳ���.

	OutPut<int>(iNumber);
	OutPut<float>(fNumber);
	//OutPut(iNumber);

	//CArray arr;  //���ø��� �Ǵ¼��� �ȵȴ�
	CArray<int> arr;

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);

	CArray<float> arr2;

	arr2.push_back(10.4f);
	arr2.push_back(20.66f);
	arr2.push_back(30.22f);

	
	for (int i = 0; i < arr.GetCount(); ++i)
	{
		std::cout << arr.GetData()[i] << std::endl;
	}

	for (int i = 0; i < arr2.GetCount(); ++i)
	{
		std::cout << arr2.GetData()[i] << std::endl;
	}
	

	int a = 0;

	return 0;
}