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

	//Test t;  불가능하다 이유는 클래스는 생성자를 무조건 호출하게 되는데 
				//이걸 private로 했기 때문에 외부에서 접근할수 있기때문에 
				//나중에 디자인패턴 종류중 게임에서 정말 많이쓰는 싱글톤패턴 같은 상황을 하면 가능하다
				
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