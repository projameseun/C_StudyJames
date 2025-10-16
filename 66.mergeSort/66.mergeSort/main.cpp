#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& _data, vector<int>& _sort, int left, int right)
{

	//std::cout << "병합: [" << left << ", " << right << "]" << std::endl;

	int mid = (left + right) / 2;

	int ldx = left;
	int rdx = mid + 1;
	int sortidx = left;


	//두 구간을 비교하면서 작은 값을 차례대로 sorted에 저장한다

	while (ldx <= mid && rdx <= right)
	{
		if (_data[ldx] <= _data[rdx])
		{
			_sort[sortidx++] = _data[ldx++];
		}
		else
		{
			_sort[sortidx++] = _data[rdx++];
		}

	}

	//남은 왼쪽 구간복사 
	while (ldx <= mid)
	{
		_sort[sortidx++] = _data[ldx++];
	}
	//남은 오른쪽 구간복사 
	while (rdx <= right)
	{
		_sort[sortidx++] = _data[rdx++];
	}

	//병합 결과를 원본 데이터에 복사한다
	for (int i = 0; i <= right; ++i)
	{
		_data[i] = _sort[i];
	}
}


void partition(vector<int>& _data, vector<int>& _sort, int left, int right, int depth)
{
	//std::cout << std::string(depth * 2, ' ') << "partition 진입: [" << left << ", " << right << "]" << std::endl;
	int iMid = 0;
	if (left < right)
	{
		iMid = (left + right) / 2;
		partition(_data, _sort, left, iMid, depth + 1);
		partition(_data, _sort, iMid + 1, right, depth + 1);
		merge(_data, _sort, left, right);
	}

	//std::cout << std::string(depth * 2, ' ') << "partition 복귀: [" << left << ", " << right << "]" << std::endl;
}

int main()
{

	//vector<int> iData = { 6,5,3,1,8,7,2,4 };
	vector<int> iData = { 6,50,100,20,3,11,48,4 };
	vector<int> iSortData;

	iSortData.resize(iData.size());

	partition(iData, iSortData, 0, iData.size() - 1, 0);


	for (const int data : iData)
	{
		std::cout << data << std::endl;
	}


	return 0;
}

/*
	left,right =>왼쪽 끝 오른쪽 끝의 인덱스 번호

	left = 0; , right = 7;
	0 < 7 TRUE
	{
		iMid = (0 + 7) / 2 ==> 3
		partition(_data, _sort, left, iMid);	//(0,1,2,3)왼쪽
		partition(_data, _sort, iMid+1, right); //(4,5,6,7)	오른쪽
		//merge(_data, _sort, left, right);
	}

	<0과3스택>
	left = 0; , right = 3;
	0 < 3 TRUE
	{
		iMid = (0 + 3) / 2 ==> 1
		partition(_data, _sort, left, iMid);	//(0,1)	왼쪽
		partition(_data, _sort, iMid+1, right); //(2,3) 오른쪽
		//merge(_data, _sort, left, right);
	}

	<0과1스택>
	left = 0; , right = 1;
	0 < 1 TRUE
	{
		iMid = (0 + 1) / 2 ==> 0
		partition(_data, _sort, left, iMid);	//(0,0)	왼쪽
		partition(_data, _sort, iMid+1, right);	//(1,1)오른쪽
		//merge(_data, _sort, left, right);
	}
	★★★★★★★★★★
	left = 0; , right = 0;
	0 < 0 FALSE
	{
		이때 스택에 쌓여있기때문에 다시 뒤로 돌아간다
	}
	<0과1스택>
	★★★★★★★★★★
	left = 0; , right = 1;
	0 < 1 TRUE
	{
		iMid = (0 + 1) / 2 ==> 0
		partition(_data, _sort, left, iMid);	//(0,0)	왼쪽
		partition(_data, _sort, iMid+1, right);	//(1,1)오른쪽
		//merge(_data, _sort, left, right);
	}

	실행되지 않는다
	left = 1; , right = 1;
	1 < 1 TRUE
	{
		iMid = (0 + 1) / 2 ==> 0
		partition(_data, _sort, left, iMid);	//(0,0)	왼쪽
		partition(_data, _sort, iMid+1, right);	//(1,1)오른쪽
		//merge(_data, _sort, left, right);
	}
	<0과1스택>
	left = 0; , right = 1;
	0 < 1 TRUE
	{
		iMid = (0 + 1) / 2 ==> 0
		partition(_data, _sort, left, iMid);	//(0,0)	왼쪽
		partition(_data, _sort, iMid+1, right);	//(1,1)오른쪽
		//merge(_data, _sort, left, right);
	}
	여기서 0,1 을 병합한다


	<0과3스택>
	left = 0; , right = 3;
	0 < 3 TRUE
	{
		iMid = (0 + 3) / 2 ==> 1
		partition(_data, _sort, left, iMid);	//(0,1)	왼쪽
		partition(_data, _sort, iMid+1, right); //(2,3) 오른쪽
		//merge(_data, _sort, left, right);
	}


	<2과3스택> 오른쪽
	left = 2; , right = 3;
	2 < 3 TRUE
	{
		iMid = (2 + 3) / 2 ==> 2
	실행안됨	partition(_data, _sort, left, iMid);	//(2,2)	왼쪽
	실행	partition(_data, _sort, iMid+1, right); //(3,3) 오른쪽
		//merge(_data, _sort, left, right);
	}
	여기서 2,3을 병합한다.
	이렇게 반복을해서

	[0,1] [2,3] 을 병합하게되고

	그다음 처음에 나눴단 반대쪽 오른쪽도 똑같이
	나눌수없을때까지 나누고 병합을 해서 올라온다
	최종적으로
	[0,1,2,3] + [4,5,6,7,] 이된다.


*/