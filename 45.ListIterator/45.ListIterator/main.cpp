#include <iostream>
#include <list>
#include "CList.h"

/*
	inline�Լ� 
	���������� ����ȭ�� �����Ų�� 
	�Ϲ������� �Լ�ȣ�� ������ �ϰԵǸ�
	main�Լ����� ���ο� �Լ��� ��������� stack�޸𸮸� ����Ѵ� 
	����Լ��� ��������� ������ �Լ��� ������ ��� ȣ���ϴ°� �������� 
	inline�Լ��� ����ϸ� a �ȿ� b�Լ��� ������ b�� �ζ����Լ����
	a�Լ��ȿ� b�Լ��� �մ°Ծƴ϶� �����Ϸ����忡���� �׳� �����Ѵ� �Լ��� �մٰ� ������ ���Ѵ�

	Ŭ������ �ϴ� ����� �Լ��� �����ϸ� inline�Լ��� �ڵ������ȴ�
	�׷� �������Ϸ����忡�� �Լ�ȣ���������ʰ� �׳� ���� �Ѱ� �״�� �ٿ��ִ� ��Ȳ�� �ȴ�.

	�Լ��� ȣ���� ���̵Ǵµ� �Լ��� ������ ���� ��� �׷� inline�� ����ϸ� �ſ� ��ȿ�����ϰ��̴�.
	�׷��� �Ϲ������� �Լ��ȿ� ������ ª���� �ѵ���  �ٵ� ȣ���� ���� �ȴ� �̷��� �������� 
*/


int main()
{
	//1.
	CList<int> list;

	list.Pushback(10);
	list.Pushback(20);
	list.Pushback(40);

	CList<int>::iterator iter = list.begin();

	//*iter = 200;

	//2.
	/*for (iter = list.begin(); iter != list.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}*/

	int a = 0;

	//3.list����
	++iter;
	++iter;
	iter = list.insert(iter, 30);

	

	//4erase
	
	iter = list.erase(iter);

	for (iter = list.begin(); iter != list.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	
	

	return 0;
}