#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector <int> vecInt;

	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	
	vecInt[0] = 300;
	int iNumber = vecInt.at(1);

	 vecInt.data();	//���� ���� �ּ�
	 vecInt.capacity(); //���� �ִ밪 

	if (!vecInt.empty())
	{
		std::cout << "The first charater is " << vecInt.front() << std::endl;
	}

	if (!vecInt.empty())
	{
		std::cout << "The last charater is " << vecInt.back() << std::endl;
	}
	
	for (int i = 0; i < vecInt.size(); ++i)
	{
		std::cout << i + 1 << " Character : " << vecInt[i] << std::endl;
	}

	


	system("cls");
	


	std::vector<int> vecInt2(3, 100);

	for (int i = 0; i < vecInt2.size(); ++i)
	{
		std::cout << i + 1 << " Character : " << vecInt2[i] << std::endl;
	}


	//begin() vector ù��° ���� 

	
	//std::vector<int>::iterator  iter = vecInt2.begin();

	////iter = vecInt2.insert(iter, 200);
	//iter = vecInt2.insert(iter, 5, 500);

	//iter.end() ������������ ����Ų��

	//for (vecInt2.begin(); iter != vecInt2.end(); ++iter)
	//{
	//	std::cout << *iter << std::endl;
	//}
	//

	
	{

		std::list<int> listInt;

		listInt.push_back(10);
		listInt.push_back(20);
		listInt.push_back(30);

		listInt.push_front(100);

		//����Ʈ�� iterator �� �����Ѵ� �ݺ���
		std::list<int>::iterator iter = listInt.begin();	//ù��°�ּҸ� ����Ų��

		//�����;ƴϰ� operator 
		int iNum = *iter;
		++iter;	//���� �ε���������Ŵ
		iNum = *iter;

	}
	return 0;
}