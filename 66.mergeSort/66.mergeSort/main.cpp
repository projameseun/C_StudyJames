#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& _data, vector<int>& _sort, int left, int right)
{

	//std::cout << "����: [" << left << ", " << right << "]" << std::endl;

	int mid = (left + right) / 2;

	int ldx = left;
	int rdx = mid + 1;
	int sortidx = left;


	//�� ������ ���ϸ鼭 ���� ���� ���ʴ�� sorted�� �����Ѵ�

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

	//���� ���� �������� 
	while (ldx <= mid)
	{
		_sort[sortidx++] = _data[ldx++];
	}
	//���� ������ �������� 
	while (rdx <= right)
	{
		_sort[sortidx++] = _data[rdx++];
	}

	//���� ����� ���� �����Ϳ� �����Ѵ�
	for (int i = 0; i <= right; ++i)
	{
		_data[i] = _sort[i];
	}
}


void partition(vector<int>& _data, vector<int>& _sort, int left, int right, int depth)
{
	//std::cout << std::string(depth * 2, ' ') << "partition ����: [" << left << ", " << right << "]" << std::endl;
	int iMid = 0;
	if (left < right)
	{
		iMid = (left + right) / 2;
		partition(_data, _sort, left, iMid, depth + 1);
		partition(_data, _sort, iMid + 1, right, depth + 1);
		merge(_data, _sort, left, right);
	}

	//std::cout << std::string(depth * 2, ' ') << "partition ����: [" << left << ", " << right << "]" << std::endl;
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
	left,right =>���� �� ������ ���� �ε��� ��ȣ

	left = 0; , right = 7;
	0 < 7 TRUE
	{
		iMid = (0 + 7) / 2 ==> 3
		partition(_data, _sort, left, iMid);	//(0,1,2,3)����
		partition(_data, _sort, iMid+1, right); //(4,5,6,7)	������
		//merge(_data, _sort, left, right);
	}

	<0��3����>
	left = 0; , right = 3;
	0 < 3 TRUE
	{
		iMid = (0 + 3) / 2 ==> 1
		partition(_data, _sort, left, iMid);	//(0,1)	����
		partition(_data, _sort, iMid+1, right); //(2,3) ������
		//merge(_data, _sort, left, right);
	}

	<0��1����>
	left = 0; , right = 1;
	0 < 1 TRUE
	{
		iMid = (0 + 1) / 2 ==> 0
		partition(_data, _sort, left, iMid);	//(0,0)	����
		partition(_data, _sort, iMid+1, right);	//(1,1)������
		//merge(_data, _sort, left, right);
	}
	�ڡڡڡڡڡڡڡڡڡ�
	left = 0; , right = 0;
	0 < 0 FALSE
	{
		�̶� ���ÿ� �׿��ֱ⶧���� �ٽ� �ڷ� ���ư���
	}
	<0��1����>
	�ڡڡڡڡڡڡڡڡڡ�
	left = 0; , right = 1;
	0 < 1 TRUE
	{
		iMid = (0 + 1) / 2 ==> 0
		partition(_data, _sort, left, iMid);	//(0,0)	����
		partition(_data, _sort, iMid+1, right);	//(1,1)������
		//merge(_data, _sort, left, right);
	}

	������� �ʴ´�
	left = 1; , right = 1;
	1 < 1 TRUE
	{
		iMid = (0 + 1) / 2 ==> 0
		partition(_data, _sort, left, iMid);	//(0,0)	����
		partition(_data, _sort, iMid+1, right);	//(1,1)������
		//merge(_data, _sort, left, right);
	}
	<0��1����>
	left = 0; , right = 1;
	0 < 1 TRUE
	{
		iMid = (0 + 1) / 2 ==> 0
		partition(_data, _sort, left, iMid);	//(0,0)	����
		partition(_data, _sort, iMid+1, right);	//(1,1)������
		//merge(_data, _sort, left, right);
	}
	���⼭ 0,1 �� �����Ѵ�


	<0��3����>
	left = 0; , right = 3;
	0 < 3 TRUE
	{
		iMid = (0 + 3) / 2 ==> 1
		partition(_data, _sort, left, iMid);	//(0,1)	����
		partition(_data, _sort, iMid+1, right); //(2,3) ������
		//merge(_data, _sort, left, right);
	}


	<2��3����> ������
	left = 2; , right = 3;
	2 < 3 TRUE
	{
		iMid = (2 + 3) / 2 ==> 2
	����ȵ�	partition(_data, _sort, left, iMid);	//(2,2)	����
	����	partition(_data, _sort, iMid+1, right); //(3,3) ������
		//merge(_data, _sort, left, right);
	}
	���⼭ 2,3�� �����Ѵ�.
	�̷��� �ݺ����ؼ�

	[0,1] [2,3] �� �����ϰԵǰ�

	�״��� ó���� ������ �ݴ��� �����ʵ� �Ȱ���
	���������������� ������ ������ �ؼ� �ö�´�
	����������
	[0,1,2,3] + [4,5,6,7,] �̵ȴ�.


*/