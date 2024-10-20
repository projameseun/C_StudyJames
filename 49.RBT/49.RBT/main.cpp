#include <iostream>
#include "CBST.h"
#include <map>


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
	
	int a = 0;

	CBST<int, int> MyInt;
	
	CBST<int, int>::iterator iter2;


	

	MyInt.insert(make_mypair(100, 0));
	MyInt.insert(make_mypair(50, 0));
	MyInt.insert(make_mypair(25, 0));
	MyInt.insert(make_mypair(200, 0));
	
	
	iter2 = MyInt.begin();
	++iter2;

	MyInt.insert(iter2, make_mypair(500, 0));
	
	int b = 0;
	
	


	return 0;
}