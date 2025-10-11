
#include <iostream>
#include <vector>

using namespace std;

/*
	선택정렬
		가장작은 값을 선택해서 가장 왼쪽으로 옮기는 과정이다
		
		동작방식 
			1.0번 인덱스(minIdx) 위치부터 시작한다
			2.현재 위치에 끝까지 탐색하여 가장 작은 인덱스를 찾는다 
			3.찾은 인덱스값(minIdx)과 현재위치의 값을 교환한다 
			4.마지막 위치까지 반복하며 정렬이 된다.

		특징
			시간 복잡도는 O(n^2)
			
		
*/


vector<int> SelectSort(vector<int> data)
{	
	//data.size() -1 를 한 이유는 마지막 인덱스는 이미 정렬되어 있기때문에 굳이 하지않는다.
	for (int i = 0; i < data.size()-1 ; ++i)
	{
		int minIdx = i;
		
		for (int j = i + 1; j < data.size(); ++j)
		{
			if (data[j] < data[minIdx])
				minIdx = j;
		}
		if (minIdx != i)
		{
			int iTemp = data[i];
			data[i] = data[minIdx];
			data[minIdx] = iTemp;
			//swap(data[i], data[minIdx]);
		}
	}
	return data;
}



int main()
{
	
	vector<int> data = { 60,20,30,10,50,60,90,100,80,27,44,67,25,68 };

	
	data = SelectSort(data);
	
	for (int i = 0; i < data.size(); ++i)
	{
		std::cout << data[i] << std::endl;
	}

	return 0;
}