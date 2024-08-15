#include <iostream>
#include <vector>
#include <list>
#include "CArray.h"

class Test
{
public:
	int m_iNum;

public:
	Test& operator =(const Test& _other)
	{
		m_iNum = _other.m_iNum;

		return *this;
	}

public:
	//생성자를 하나라도 만들었다면 기본생성자를 호출하지 않는다
	Test() :
		m_iNum(0)
	{

	}

	//복사생성자
	Test(const Test& _other):
		m_iNum(_other.m_iNum)
	{
		
	}
};


int main()
{
	/*
		c++에서 컨테이러란 데이터를 저장하고 관리하는데 사용되는 클래스 템플릿이다.
		표준 라이브러리(STL - Standard Template Libray)에 포함되어 있고
		이는 다양한 유형의 데이터를 효율적으로 관리할수 있는 다양한 컨테이너들이 제공된다.
		컨테이너는 데이터를 저장하고 관리하는데 사용되는 객체

		반복자(iterator)
		반복자는 컨테이너의 요소들에 순차적으로 접근하기 위한 객체이다
		이너클래스라고 부른다 반복자는 포인터와 아주 유사한 동작을 하며, 다양한 컨테이너와 함께 작동할수 있다

		vctor는 인덱스를 통해 특정요소에 직접 접근이 가능해
		하지만 list는 불가능하다 이러한 차이로 인해
		list는 반복자를 사용하여 요소에 접근해야 된다.


		1.시퀀스 컨테이너 (Sequence Containers)
		시퀀스 컨테이너는 데이터요소를 순차적으로 저장한다.

		vector,list,array 등 있다

		vector=======
		push_back() 백터 끝 추가
		resize() 백터 크기조절
		reserve() 지정된 용량 미리 할당
		capacity() 최대크기 반환
		earse()특정 요소 삭제


		begin() 컨테이너 첫번재 요소를 가리키는 반복자 반환
		end() 컨테이너 마지막 요소를 다음을 가리키는 반복자 반환

		list===
		push_front() 앞에 추가
		push_back() 뒤추가
		pop_front() 앞 요소 제거
		pop_back() 뒤 삭제
		insert() 지정된 위치 요소 삽입



		2.연관 컨테이너(Associative Containers)
		연관 컨테이너는 키를 사용하여 데이터를 저장하여, 주로 정렬된 상태로 유지된다.

		set,map,multimap등

		3.어댑터 컨테이너(Adapter Containers)
		어댑터 컨테이너는 다른 컨테이너를 기반으로 특정 기능을 제공하는 컨테이너이다.
		어댑터 컨테이너는 내부적으로 시퀸스 컨테이너를 사용하여 제한된 인터페이스를 통해 특정 동작을 수행한다.
		주로 stack LIFO(Last In,First Out) -> 먼저 들어온 요소가 가장 늦게 지워지고 마지막 요소가 가장먼저 제거된다.

		push() 스택의 상단에 요소를추가
		pop() 스택의 상단에 요소 제거
		top() 스택의 상단요소 반환
		empty() 스택이 비어 있는지 여부 확인
		size() 사이즈 반환

		queue FIFO(First In,First Out)
		먼저들어온 요소가 먼저 제거되고 나중에 들어온 요소가 가장 늦게 지워진다.

		push() 큐의 뒤에 요소를추가
		pop() 큐의 앞에 요소를 제거
		front() 큐의 앞 요소를 반환
		back() 큐의 뒤 요소를 반환
		empty() 큐가 비어 있는지 여부 확인
		size() 사이즈 반환


	*/
	//std::list<int> listInt;



	//listInt.push_back(100);
	//listInt.push_back(200);
	//listInt.push_back(300);
	//listInt.push_back(400);
	//listInt.push_back(500);

	//std::list<int>::iterator iter = listInt.begin();

	//++iter;
	//*iter = 5000;

	//for (iter = listInt.begin(); iter != listInt.end(); ++iter)
	//{
	//	std::cout << *iter << std::endl;

	//}

	CArray<int> myVec;

	myVec.push_back(10);
	myVec.push_back(20);
	myVec.push_back(30);

	CArray<int>::iterator iter = myVec.begin();

	//전위 후위 연산자 
	for (; iter != myVec.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}

	iter = myVec.begin();

	++iter;
	++iter;
	--iter;

	std::cout << *(iter) << std::endl;

	
	//int iNum = *(iter++);
	//int iNum = *(++iter);

	//int iNum = *(iter--);

	//int iNum2 = *(iter--);

	int a = 0;

	//*iter
	//++iter
	//iter == iter2
	//iter--
	//iter != , 전위 후위
	
	std::vector<int> vecInt;

	std::vector<int> vecInt2;

	/*vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);*/
	
	std::vector<int>::iterator vecIter = vecInt.begin();

	for (int i = 0; i < 10; ++i)
	{
		vecInt.push_back(i);
	}

	//두개중 하나를가리킬때 문제가되는 예시
	vecInt2.push_back(1500);


	vecIter = vecInt.begin();

	vecInt.erase(vecIter);

	//에러난다 가리키는곳이 다르기 때문에
	//int iNum = *vecIter;
	
	//return 이터를 바로 주면 에러안남
	//vecIter = vecInt.erase(vecIter);
	
	vecInt.erase(vecInt.begin() + 3 );

	//위에는 vecIter가 이제 가리키는곳이 이상해진다는거 디버깅을 찍어서 확인해보면 알수 있다.

	//*vecIter;	//문제가 생긴다.  can't dereference value-initialized vector iterator"


	//enditerator접근 하면 문제생김

	//vecIter = vecInt.end();
	


	Test t1;
	t1.m_iNum = 100;

	Test t2(t1);
	//t1 = t2; 복사생성자를 사용하는 예시

	//복사생성자  컴파일러가 알아서 바꿔줌
	Test t3 = t1;



	return 0;
}