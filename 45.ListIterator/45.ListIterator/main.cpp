#include <iostream>
#include <list>
#include "CList.h"

/*
	inline함수 
	컴파일한테 최적화를 진행시킨다 
	일반적으로 함수호출 구현을 하게되면
	main함수에서 새로운 함수를 사용했을때 stack메모리를 사용한다 
	재귀함수를 사용했을때 문제가 함수를 여러번 계속 호출하는게 문제엿다 
	inline함수를 사용하면 a 안에 b함수가 잇을때 b가 인라인함수라면
	a함수안에 b함수가 잇는게아니라 컴파일러입장에서는 그냥 실행한다 함수가 잇다고 생각을 안한다

	클래스는 일단 헤더에 함수를 구현하면 inline함수로 자동구현된다
	그러 ㅁ컴파일러입장에서 함수호출을하지않고 그냥 복사 한걸 그대로 붙여넣는 상황이 된다.

	함수가 호출이 많이되는데 함수의 구문이 많이 길다 그럼 inline을 사용하면 매우 비효율적일것이다.
	그래서 일반적으로 함수안에 구현이 짧을때 한두줄  근데 호출이 자주 된다 이럴때 쓰면좋음 
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

	//3.list부터
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