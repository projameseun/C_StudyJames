#include <iostream>
#include <vector>

using namespace std;

/*
	삽입정렬
		가장 왼쪽은 정렬이 되어있다고 가정한다.
		배열의 두 번째 idx부터 시작하여,
		해당 idx를 앞쪽 정렬된 부분과 비교하면서
		자신이 들어갈 위치를 찾아 삽입하는 방식의 정렬 알고리즘이다.

		각 단계마다 현재 idx를 왼쪽으로 이동시키며
		자신보다 큰 값들을 오른쪽으로 밀어내고
		적절한 위치에 삽입하여 정렬된 부분을 확장해간다

		시간복잡도 O(n^2), 최선 O(n)
		- 선택정렬, 버블정렬과 달리 데이터가 거의 정렬되어 있으면 매우 빠름
		- 구현이 간단하고, 작은 데이터에 적합함
*/


void insertionSort(vector<int>& _data)
{
	for (int i = 1; i < _data.size(); ++i)
	{
		int iKey = _data[i]; //정렬되지 않은 첫번째값이 key 를 말한다
		int j = i - 1; //왼쪽은 정렬된곳이다 j가 정렬된곳을 말한다

		//key보다 큰값을 오른쪽으로 이동시킨다
		while (j >= 0 && _data[j] > iKey)
		{
			_data[j + 1] = _data[j];
			--j;
		}

		_data[j + 1] = iKey;

	}
}

void insertionSortSwap(vector<int>& _data)
{
	for (int i = 1; i < _data.size(); ++i)
	{
		for (int j = i ; j > 0 && _data[j] < _data[j - 1]; --j)
		{
			swap(_data[j], _data[j - 1]);
		}
	}
}

int main()
{

	vector<int> data = { 5, 2, 9, 1, 3, 6 };

	insertionSortSwap(data);

	for (int i = 0; i < data.size(); ++i)
	{
		std::cout << data[i] << std::endl;
	}
	
	return 0;
}