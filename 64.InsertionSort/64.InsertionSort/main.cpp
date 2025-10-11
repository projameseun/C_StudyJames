#include <iostream>
#include <vector>

using namespace std;


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