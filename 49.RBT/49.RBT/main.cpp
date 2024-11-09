#include <iostream>
#include "CBST.h"
#include <map>
#include <string>

using namespace std;


int main()
{


	std::map<int, int> mapint;
	

	mapint.insert(std::make_pair(100, 100));
	mapint.insert(std::make_pair(50, 100));
	mapint.insert(std::make_pair(25, 100));
	mapint.insert(std::make_pair(200, 100));
	mapint.insert(std::make_pair(300, 100));
	
	std::map<int, int>::iterator iter = mapint.begin();

	iter++;

	iter = mapint.insert(iter, std::make_pair(400, 300));
	
	std::cout << (*iter).first << std::endl;
	
	int a = 0;

	CBST<int, int> MyInt;

	CBST<string, int> MyStr;
	
	string str;
	string str2;

	//str2 = "°¡";

	//str = "°¡";
	MyStr.insert(make_mypair(static_cast<string>("ÀºÁø¼ö"), 0));
	MyStr.insert(make_mypair(static_cast<string>("±èÈñ½Â"), 0));
	MyStr.insert(make_mypair(static_cast<string>("ÀÌ½ÂÈÆ"), 0));
	MyStr.insert(make_mypair(static_cast<string>("À¯Á¤È­"), 0));
	MyStr.insert(make_mypair(static_cast<string>("Àº¼º¼ö"), 0));
	MyStr.insert(make_mypair(static_cast<string>("±èÈñÀç"), 0));
	MyStr.insert(make_mypair(static_cast<string>("Á¤Áø¸ğ"), 0));
	MyStr.insert(make_mypair(static_cast<string>("¿ÀÁÖÈ£"), 0));

	CBST<int, int>::iterator iter2;

	CBST<string, int>::iterator iterstr;


	

	MyInt.insert(make_mypair(100, 0)); //
	MyInt.insert(make_mypair(50, 0)); //
	MyInt.insert(make_mypair(70, 0)); //
	MyInt.insert(make_mypair(200, 0)); //
	MyInt.insert(make_mypair(10, 0)); //
	MyInt.insert(make_mypair(55, 0)); //
	MyInt.insert(make_mypair(112, 0)); //
	
	MyInt.insert(make_mypair(78, 0)); 


	MyInt.insert(make_mypair(2000, 0));
	MyInt.insert(make_mypair(80, 0));
	MyInt.insert(make_mypair(90, 0));
	MyInt.insert(make_mypair(670, 0));
	MyInt.insert(make_mypair(59, 0));
	MyInt.insert(make_mypair(77, 0));



	
	int itest = MyInt.GetCount();
	
	iter2 = MyInt.begin();
	//++iter2;

	//iter2 = MyInt.insert(iter2, make_mypair(500, 0));
	
	int b = 0;

	int iCount = 0;

	for (iter2; iter2 != MyInt.end() && iter2 != MyInt.GetNilNode(); ++iter2)
	{
		iCount++;
		std::cout << (*iter2).first << std::endl;
	
	}
	
	std::cout << iCount << std::endl;
	int c = 0;


	iterstr = MyStr.begin();

	for (iterstr; iterstr != MyStr.end() && iterstr != MyStr.GetNilNode(); ++iterstr)
	{
		//iCount++;
		std::cout << (*iterstr).first << std::endl;

	}


	return 0;
}