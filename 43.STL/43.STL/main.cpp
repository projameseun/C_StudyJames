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

	 vecInt.data();	//최초 시작 주소
	 vecInt.capacity(); //현재 최대값 

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


	//begin() vector 첫번째 원소 

	
	//std::vector<int>::iterator  iter = vecInt2.begin();

	////iter = vecInt2.insert(iter, 200);
	//iter = vecInt2.insert(iter, 5, 500);

	//iter.end() 마지막다음을 가리킨단

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

		//리스트는 iterator 를 제공한다 반복자
		std::list<int>::iterator iter = listInt.begin();	//첫번째주소를 가리킨다

		//포인터아니고 operator 
		int iNum = *iter;
		++iter;	//다음 인덱스를가리킴
		iNum = *iter;

	}
	return 0;
}