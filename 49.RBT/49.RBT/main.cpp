#include <iostream>
#include "CBST.h"
#include <map>
#include <string>

using namespace std;

int main()
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	std::map<int, int> mapint;




	/*mapint.insert(std::make_pair(100, 100));
	mapint.insert(std::make_pair(50, 100));
	mapint.insert(std::make_pair(25, 100));
	mapint.insert(std::make_pair(200, 100));
	mapint.insert(std::make_pair(300, 100));
	*/
	std::map<int, int>::iterator iter = mapint.begin();

	//iter++;

	//iter = mapint.insert(iter, std::make_pair(400, 300));

	int a = 0;


	CBST<int, int> MyInt;
	//CBST<char, char> myoat;


	///myoat.insert(make_mypair('a', 'a'));

	CBST<int, int>::iterator iter2;

	CBST<string, int> MyStr;

	CBST<string, int>::iterator iterstr;

	//int
	//MyInt.insert(make_mypair(100, 0));					//				 100
	//MyInt.insert(make_mypair(60, 0));					//           
	//MyInt.insert(make_mypair(25, 0));
	//MyInt.insert(make_mypair(200, 0));
	//MyInt.insert(make_mypair(250, 0));

	//MyInt.insert(make_mypair(1, 0));
	//MyInt.insert(make_mypair(2, 0));
	//MyInt.insert(make_mypair(3, 0));
	//MyInt.insert(make_mypair(4, 0));
	//MyInt.insert(make_mypair(5, 0));
	//MyInt.insert(make_mypair(6, 0));
	//MyInt.insert(make_mypair(7, 0));
	//MyInt.insert(make_mypair(8, 0));
	//MyInt.insert(make_mypair(9, 0));
	//MyInt.insert(make_mypair(10, 0));

	//MyInt.insert(make_mypair(11, 0));
	//MyInt.insert(make_mypair(12, 0));
	//MyInt.insert(make_mypair(13, 0));
	//MyInt.insert(make_mypair(14, 0));
	//MyInt.insert(make_mypair(15, 0));
	//MyInt.insert(make_mypair(16, 0));
	//MyInt.insert(make_mypair(17, 0));
	//MyInt.insert(make_mypair(18, 0));
	//MyInt.insert(make_mypair(19, 0));
	//MyInt.insert(make_mypair(20, 0));
	//MyInt.insert(make_mypair(21, 0));
	//MyInt.insert(make_mypair(22, 0));

	//��Ʈ��
	/*MyStr.insert(make_mypair(static_cast<string>("������"), 0));
	MyStr.insert(make_mypair(static_cast<string>("�ڸ���"), 0));
	MyStr.insert(make_mypair(static_cast<string>("�����"), 0));
	MyStr.insert(make_mypair(static_cast<string>("������"), 0));
	MyStr.insert(make_mypair(static_cast<string>("������"), 0));
	MyStr.insert(make_mypair(static_cast<string>("������"), 0));
	MyStr.insert(make_mypair(static_cast<string>("�ڵθ�"), 0));
	MyStr.insert(make_mypair(static_cast<string>("�ڻ�ö"), 0));
	MyStr.insert(make_mypair(static_cast<string>("�ڶ��̾�"), 0));
	MyStr.insert(make_mypair(static_cast<string>("������"), 0));
	MyStr.insert(make_mypair(static_cast<string>("����Ÿ"), 0));
	MyStr.insert(make_mypair(static_cast<string>("����"), 0));
	MyStr.insert(make_mypair(static_cast<string>("����"), 0));*/

	//���ǽ�����
	MyStr.insert(make_mypair(static_cast<string>("����"), 0));
	MyStr.insert(make_mypair(static_cast<string>("����"), 0));
	MyStr.insert(make_mypair(static_cast<string>("����"), 0));
	MyStr.insert(make_mypair(static_cast<string>("���"), 0));
	MyStr.insert(make_mypair(static_cast<string>("����"), 0));
	MyStr.insert(make_mypair(static_cast<string>("¡��"), 0));
	MyStr.insert(make_mypair(static_cast<string>("�κ�"), 0));
	MyStr.insert(make_mypair(static_cast<string>("����Ű"), 0));
	MyStr.insert(make_mypair(static_cast<string>("���"), 0));
	MyStr.insert(make_mypair(static_cast<string>("��ũ��"), 0));
	MyStr.insert(make_mypair(static_cast<string>("����"), 0));
	MyStr.insert(make_mypair(static_cast<string>("��ȣũ"), 0));
	MyStr.insert(make_mypair(static_cast<string>("Ƽġ"), 0));
	MyStr.insert(make_mypair(static_cast<string>("��"), 0));
	MyStr.insert(make_mypair(static_cast<string>("����"), 0));
	MyStr.insert(make_mypair(static_cast<string>("���"), 0));
	MyStr.insert(make_mypair(static_cast<string>("��Ÿ"), 0));
	MyStr.insert(make_mypair(static_cast<string>("ī�̵�"), 0));
	MyStr.insert(make_mypair(static_cast<string>("��γ�"), 0));
	MyStr.insert(make_mypair(static_cast<string>("���뽺��"), 0));

	iterstr = MyStr.find("����");
	iterstr = MyStr.erase(iterstr);


	iterstr = MyStr.find("¡��");
	iterstr = MyStr.erase(iterstr);

	iterstr = MyStr.find("���");
	iterstr = MyStr.erase(iterstr);

	iterstr = MyStr.find("ī�̵�");
	iterstr = MyStr.erase(iterstr);


	//iterstr = MyStr.begin();

	//iterstr = MyStr.find("������");
	//iterstr = MyStr.erase(iterstr);

	//iterstr = MyStr.find("������");
	//iterstr = MyStr.erase(iterstr);

	//iterstr = MyStr.find("������");
	//iterstr = MyStr.erase(iterstr);

	//iterstr = MyStr.find("������");
	//iterstr = MyStr.erase(iterstr);

	//MyInt.insert(make_mypair(80, 0));
	//MyInt.insert(make_mypair(300, 0));
	//iter2 = MyInt.find(200);
	//iter2 = MyInt.erase(iter2);

	////case4
	//iter2 = MyInt.find(100);
	//iter2 = MyInt.erase(iter2);

	//MyInt.insert(make_mypair(280, 0));

	//iter2 = MyInt.find(250);
	//iter2 = MyInt.erase(iter2);

	////case2��
	//iter2 = MyInt.find(280);
	//iter2 = MyInt.erase(iter2);

	//
	//iter2 = MyInt.find(80);
	//iter2 = MyInt.erase(iter2);


	int iCount = 0;
	//case1�� �׽�Ʈ


	//iter2 = MyInt.find(18);
	//iter2 = MyInt.erase(iter2);


	//iter2 = MyInt.begin();
	//////
	//////����
	//for (iter2; iter2 != MyInt.end() && iter2 != MyInt.GetNilNode(); ++iter2)
	//{
	//	iCount++;
	//	std::cout << (*iter2).first << std::endl;

	//}
	

	iterstr = MyStr.begin();

	//��Ʈ��
	for (iterstr; iterstr != MyStr.end() && iterstr != MyStr.GetNilNode(); ++iterstr)
	{
		iCount++;
		std::cout << (*iterstr).first << std::endl;

	}
	

	std::cout << iCount << std::endl;

	return 0;
}