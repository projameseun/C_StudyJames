#include <iostream>
#include <vector>

using namespace std;

//������ pivot����  ū���� ���ö����� ���������� �̵��Ѵ�
//�������� pivot���� �������� ���Ë����� �������� �̵��Ѵ�

int partition(vector<int>& _data, int pidx, int right)
{
	int start,end = 0;	//start :left�� ���Ѵ� end :right�� ���Ѵ�.

	int pivot = _data[pidx];

	start = pidx + 1; //�ǹ��ε��� +1 ���� ���۰��� �ȴ�
	end = right;	//�������� �������� �ȴ�.

	while (start <= end)		//�������� ������ ���������� ���� ���ư���.
	{
		while (_data[start] < pivot && start <= right)	//������ pivot����  ū���� ���ö����� ���������� �̵��Ѵ�
		{
			start++;
		}
		while (_data[end] > pivot && end >= pidx)		//�������� pivot���� �������� ���Ë����� �������� �̵��Ѵ�
		{
			end--;
		}

		if (start <= end)		//���� �������� �ʾҴٸ� 
		{
			int iTemp = _data[start];		//�ڡڡ�swap���� �ε��� �̵��� ���ϸ� ���� ������ �߻��Ҽ� �ֱ⶧���� �� ����ߵȴ�.
			_data[start] = _data[end];		//��簪�� ���ų� , swap�� ������ ��� ���ΰ�쿡 �ε��� �̵��̾����� ���ѷ��� �߻�
			_data[end] = iTemp;
			start++;
			end--;
		}

		
	}

	//������ �ϸ� pivot �� end��ġ�� ��ȯ���ش�.
	int iTemp = _data[pidx];
	_data[pidx] = _data[end];
	_data[end] = iTemp;


	

	return end;
}

void quicksort(vector<int>& _data, int left, int right)
{
	if (left < right)	//�������� �ަU�� ����� ���������� ��
	{
		int pivot = partition(_data, left, right);	//pivot�� ����ؼ� �κй迭�� ���� ���������� ������

		quicksort(_data, left , pivot - 1);//�ǹ��� �������� ���� �κй迭
		quicksort(_data, pivot + 1, right);		//�ǹ��� �������� ������ �κй迭
	}
}




int main()
{
	
	vector<int> data = { 54,34,41,89,67,16,52,23 };
	//vector<int> data = { 1,1,1,1 };	//���ѷ����� ������ ����

	quicksort(data, 0, data.size()-1);

	for (int i = 0; i < data.size(); ++i)
	{
		std::cout << data[i] << std::endl;
	}

	return 0;
}