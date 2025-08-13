#include <iostream>
#include <vector>
#include <string>
#include "ArrayList.h"

int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(10);

	vec.resize(10);

	size_t t = vec.capacity();

	for (int i = 0; i < vec.size(); ++i)
	{

		std::cout << vec[i] << std::endl;
	}

	ArrayList<int> arr;

	arr.push_back(10);
	arr.push_back(20);
	arr.push_back(30);
	arr.push_back(40);
	arr.push_back(50);

	arr.clear();

	if (arr.empty())
	{
		std::cout << "비었어요" << std::endl;
	}



	ArrayList<std::string> str;

	str.push_back("one");
	str.push_back("two");
	str.push_back("three");
	str.push_back("four");
	str.push_back("five");
	str.resize(10);


	for (size_t i = 0; i < str.size(); ++i)
	{
		std::cout << str[i] << std::endl;
	}


	return 0;
}