#include <iostream>
#include "CArray.h"
class Test
{
private:
	Test()
	{

	}
};

int main()
{

	//Test t;  �Ұ����ϴ� ������ Ŭ������ �����ڸ� ������ ȣ���ϰ� �Ǵµ� 
				//�̰� private�� �߱� ������ �ܺο��� �����Ҽ� �ֱ⶧���� 
				//���߿� ���������� ������ ���ӿ��� ���� ���̾��� �̱������� ���� ��Ȳ�� �ϸ� �����ϴ�
				
	CArray arr = {};

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);

	
	arr.resize(9);
	
	for (int i = 0; i < arr.GetMaxCount(); ++i)
	{
		std::cout << arr.GetpInt()[i] << std::endl;
	}

	int iData = arr[1];

	arr[2] = 200;


	return 0;
}