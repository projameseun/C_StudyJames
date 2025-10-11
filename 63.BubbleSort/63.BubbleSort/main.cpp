
#include <iostream>
#include <vector>

using namespace std;

//버블정렬
//인접한 두 원소를 반복적으로 비교하여, 더 큰 값을 뒤로(오름차순)보내는 방식의 정렬 알고리즘
//시간복잡도:O(n^2)
//작은 데이터에 적합,대량 데이터에는 비효율
//선택정렬 보다 비효율적 

vector<int> BubbleSort(vector<int> data)
{
	for (int i = 0; i < data.size(); ++i)
	{

		// data.size()-i -1 를 한이유
		//버블정렬에서 이미 정렬된 부분을 제외하고 비교해야 할 마지막 인덱스를 나타난다
		//버블 정렬은 한 번의 바깥 반복(i)이 끝날 때마다 가장 큰 값이 맨 뒤로 이동한다
		//	즉, 바깥 반복이 한 번 진행될 때마다 뒤쪽의 i개 원소는 이미 정렬되어 있으므로,
		//	안쪽 반복(j)에서는 그 부분을 다시 비교할 필요가 없다.

		for (int j = 0; j < data.size()-i -1; ++j)
		{
			
			if (data[j] > data[ j+ 1])
			{
				int iTemp = 0;
				iTemp = data[j];
				data[j] = data[j + 1];
				data[j+ 1] = iTemp;

			}
		}
		
	}

	return data;

}

int main()
{
	vector<int> data = { 48,20,19,20,55,100,535,75,1,5,36 };

	vector<int> iResult;

	iResult = BubbleSort(data);
	
	return 0;
}