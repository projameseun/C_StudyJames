#include <iostream>
#include "CArray.h"
#include <vector>
class Test
{
private:
	Test()
	{

	}
};

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Test t;  �Ұ����ϴ� ������ Ŭ������ �����ڸ� ������ ȣ���ϰ� �Ǵµ� 
				//�̰� private�� �߱� ������ �ܺο��� �����Ҽ� �ֱ⶧���� 
				//���߿� ���������� ������ ���ӿ��� ���� ���̾��� �̱������� ���� ��Ȳ�� �ϸ� �����ϴ�
				
	CArray arr = {};

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);
	arr.push_back(60);
	arr.push_back(70);

	
	//arr.resize(9);
	
	for (int i = 0; i < arr.GetMaxCount(); ++i)
	{
		std::cout << arr.GetpInt()[i] << std::endl;
	}

	int iData = arr[1];

	arr[2] = 200;

	std::cout << "=====================" << std::endl;
	
	arr.Delete(4);

	for (int i = 0; i <arr.GetCount(); ++i)
	{
		std::cout << arr.GetpInt()[i] << std::endl;
	}

	//std::vector <int> vec;

	//vec.push_back(10);
	//vec.push_back(20);
	//vec.push_back(30);

	//vec.resize(10);
	//
	//for (int i = 0; i < 5; ++i)
	//{
	//	std::cout << vec[i]  << std::endl;
	//}



	//vec.erase(vec.begin() +1);

	//for (int i = 0; i < vec.size(); ++i)
	//{
	//	std::cout << i + 1 << vec[i] << std::endl;
	//}

	return 0;
}