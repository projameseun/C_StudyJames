#include <iostream>
#include <list>

using namespace std;

int main()
{
	std::list<int> number;

	//1.값 복사 방식
	for (int value : number)
	{
		//값으로 복사 하였기 때문에 number는 수정 되지 않는다.
		value += 10;
	}

	//2.const 값 복사 방식
	for (const int value : number)
	{
		//value += 10; //오류
		//수정불가
		cout << value << endl;
	}
	//3.참조 방식 (수정가능)
	for (int& value : number)
	{
		value += 10;
	}

	//4.const 참조 방식(읽기전용)
	
	for (const int& value : number)
	{
		//value는 원본을 참조한다
	}

	//5.auto 방식(타입 자동추론)
	for (auto value : number)
	{
		//1번과 같은상황 value는 요소를 복사한값 수정을 하여도 원본에는 영향이 없음
	}

	//6.auto 참조방식
	for (auto& value : number)
	{
		//value는 원본을 참조 , 수정가능
	}

	//7.const auto 참조방식
	for (const auto& value : number)
	{
		
	}



	return 0;
}