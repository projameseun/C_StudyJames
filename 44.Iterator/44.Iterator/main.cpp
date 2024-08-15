#include <iostream>
#include <vector>
#include <list>
#include "CArray.h"

class Test
{
public:
	int m_iNum;

public:
	Test& operator =(const Test& _other)
	{
		m_iNum = _other.m_iNum;

		return *this;
	}

public:
	//�����ڸ� �ϳ��� ������ٸ� �⺻�����ڸ� ȣ������ �ʴ´�
	Test() :
		m_iNum(0)
	{

	}

	//���������
	Test(const Test& _other):
		m_iNum(_other.m_iNum)
	{
		
	}
};


int main()
{
	/*
		c++���� �����̷��� �����͸� �����ϰ� �����ϴµ� ���Ǵ� Ŭ���� ���ø��̴�.
		ǥ�� ���̺귯��(STL - Standard Template Libray)�� ���ԵǾ� �ְ�
		�̴� �پ��� ������ �����͸� ȿ�������� �����Ҽ� �ִ� �پ��� �����̳ʵ��� �����ȴ�.
		�����̳ʴ� �����͸� �����ϰ� �����ϴµ� ���Ǵ� ��ü

		�ݺ���(iterator)
		�ݺ��ڴ� �����̳��� ��ҵ鿡 ���������� �����ϱ� ���� ��ü�̴�
		�̳�Ŭ������� �θ��� �ݺ��ڴ� �����Ϳ� ���� ������ ������ �ϸ�, �پ��� �����̳ʿ� �Բ� �۵��Ҽ� �ִ�

		vctor�� �ε����� ���� Ư����ҿ� ���� ������ ������
		������ list�� �Ұ����ϴ� �̷��� ���̷� ����
		list�� �ݺ��ڸ� ����Ͽ� ��ҿ� �����ؾ� �ȴ�.


		1.������ �����̳� (Sequence Containers)
		������ �����̳ʴ� �����Ϳ�Ҹ� ���������� �����Ѵ�.

		vector,list,array �� �ִ�

		vector=======
		push_back() ���� �� �߰�
		resize() ���� ũ������
		reserve() ������ �뷮 �̸� �Ҵ�
		capacity() �ִ�ũ�� ��ȯ
		earse()Ư�� ��� ����


		begin() �����̳� ù���� ��Ҹ� ����Ű�� �ݺ��� ��ȯ
		end() �����̳� ������ ��Ҹ� ������ ����Ű�� �ݺ��� ��ȯ

		list===
		push_front() �տ� �߰�
		push_back() ���߰�
		pop_front() �� ��� ����
		pop_back() �� ����
		insert() ������ ��ġ ��� ����



		2.���� �����̳�(Associative Containers)
		���� �����̳ʴ� Ű�� ����Ͽ� �����͸� �����Ͽ�, �ַ� ���ĵ� ���·� �����ȴ�.

		set,map,multimap��

		3.����� �����̳�(Adapter Containers)
		����� �����̳ʴ� �ٸ� �����̳ʸ� ������� Ư�� ����� �����ϴ� �����̳��̴�.
		����� �����̳ʴ� ���������� ������ �����̳ʸ� ����Ͽ� ���ѵ� �������̽��� ���� Ư�� ������ �����Ѵ�.
		�ַ� stack LIFO(Last In,First Out) -> ���� ���� ��Ұ� ���� �ʰ� �������� ������ ��Ұ� ������� ���ŵȴ�.

		push() ������ ��ܿ� ��Ҹ��߰�
		pop() ������ ��ܿ� ��� ����
		top() ������ ��ܿ�� ��ȯ
		empty() ������ ��� �ִ��� ���� Ȯ��
		size() ������ ��ȯ

		queue FIFO(First In,First Out)
		�������� ��Ұ� ���� ���ŵǰ� ���߿� ���� ��Ұ� ���� �ʰ� ��������.

		push() ť�� �ڿ� ��Ҹ��߰�
		pop() ť�� �տ� ��Ҹ� ����
		front() ť�� �� ��Ҹ� ��ȯ
		back() ť�� �� ��Ҹ� ��ȯ
		empty() ť�� ��� �ִ��� ���� Ȯ��
		size() ������ ��ȯ


	*/
	//std::list<int> listInt;



	//listInt.push_back(100);
	//listInt.push_back(200);
	//listInt.push_back(300);
	//listInt.push_back(400);
	//listInt.push_back(500);

	//std::list<int>::iterator iter = listInt.begin();

	//++iter;
	//*iter = 5000;

	//for (iter = listInt.begin(); iter != listInt.end(); ++iter)
	//{
	//	std::cout << *iter << std::endl;

	//}

	CArray<int> myVec;

	myVec.push_back(10);
	myVec.push_back(20);
	myVec.push_back(30);

	CArray<int>::iterator iter = myVec.begin();

	//���� ���� ������ 
	for (; iter != myVec.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	iter = myVec.begin();

	++iter;
	++iter;
	--iter;

	std::cout << *(iter) << std::endl;

	
	//int iNum = *(iter++);
	//int iNum = *(++iter);

	//int iNum = *(iter--);

	//int iNum2 = *(iter--);

	int a = 0;

	//*iter
	//++iter
	//iter == iter2
	//iter--
	//iter != , ���� ����
	
	std::vector<int> vecInt;

	std::vector<int> vecInt2;

	/*vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);*/
	
	std::vector<int>::iterator vecIter = vecInt.begin();

	for (int i = 0; i < 10; ++i)
	{
		vecInt.push_back(i);
	}

	//�ΰ��� �ϳ�������ų�� �������Ǵ� ����
	vecInt2.push_back(1500);


	vecIter = vecInt.begin();

	vecInt.erase(vecIter);

	//�������� ����Ű�°��� �ٸ��� ������
	//int iNum = *vecIter;
	
	//return ���͸� �ٷ� �ָ� �����ȳ�
	//vecIter = vecInt.erase(vecIter);
	
	vecInt.erase(vecInt.begin() + 3 );

	//������ vecIter�� ���� ����Ű�°��� �̻������ٴ°� ������� �� Ȯ���غ��� �˼� �ִ�.

	//*vecIter;	//������ �����.  can't dereference value-initialized vector iterator"


	//enditerator���� �ϸ� ��������

	//vecIter = vecInt.end();
	


	Test t1;
	t1.m_iNum = 100;

	Test t2(t1);
	//t1 = t2; ��������ڸ� ����ϴ� ����

	//���������  �����Ϸ��� �˾Ƽ� �ٲ���
	Test t3 = t1;



	return 0;
}