#include <iostream>
#include <vector>

using namespace std;

//왼쪽은 pivot보다  큰값이 나올때까지 오른쪽으로 이동한다
//오른쪽은 pivot보다 작은값이 나올떄까지 왼쪽으로 이동한다

int partition(vector<int>& _data, int pidx, int right)
{
	int start,end = 0;	//start :left를 말한다 end :right를 말한다.

	int pivot = _data[pidx];

	start = pidx + 1; //피벗인덱스 +1 쪽이 시작값이 된다
	end = right;	//오른쪽이 끝지점이 된다.

	while (start <= end)		//오른쪽이 왼쪽을 교차했을때 까지 돌아간다.
	{
		while (_data[start] < pivot && start <= right)	//왼쪽은 pivot보다  큰값이 나올때까지 오른쪽으로 이동한다
		{
			start++;
		}
		while (_data[end] > pivot && end >= pidx)		//오른쪽은 pivot보다 작은값이 나올떄까지 왼쪽으로 이동한다
		{
			end--;
		}

		if (start <= end)		//둘이 교차되지 않았다면 
		{
			int iTemp = _data[start];		//★★★swap이후 인덱스 이동을 안하면 무한 루프가 발생할수 있기때문에 꼭 해줘야된다.
			_data[start] = _data[end];		//모든값이 같거나 , swap후 조건이 계속 참인경우에 인덱스 이동이없으면 무한루프 발생
			_data[end] = iTemp;
			start++;
			end--;
		}

		
	}

	//교차를 하면 pivot 과 end위치를 교환해준다.
	int iTemp = _data[pidx];
	_data[pidx] = _data[end];
	_data[end] = iTemp;


	

	return end;
}

void quicksort(vector<int>& _data, int left, int right)
{
	if (left < right)	//오른쪽이 왼쪾을 벗어나면 최종적으로 끝
	{
		int pivot = partition(_data, left, right);	//pivot을 사용해서 부분배열로 왼쪽 오른쪽으로 나뉜다

		quicksort(_data, left , pivot - 1);//피벗을 기준으로 왼쪽 부분배열
		quicksort(_data, pivot + 1, right);		//피벗을 기준으로 오른쪽 부분배열
	}
}




int main()
{
	
	vector<int> data = { 54,34,41,89,67,16,52,23 };
	//vector<int> data = { 1,1,1,1 };	//무한루프에 빠지는 예시

	quicksort(data, 0, data.size()-1);

	for (int i = 0; i < data.size(); ++i)
	{
		std::cout << data[i] << std::endl;
	}

	return 0;
}