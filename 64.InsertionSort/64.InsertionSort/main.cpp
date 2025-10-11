#include <iostream>
#include <vector>

using namespace std;

/*
	��������
		���� ������ ������ �Ǿ��ִٰ� �����Ѵ�.
		�迭�� �� ��° idx���� �����Ͽ�,
		�ش� idx�� ���� ���ĵ� �κа� ���ϸ鼭
		�ڽ��� �� ��ġ�� ã�� �����ϴ� ����� ���� �˰����̴�.

		�� �ܰ踶�� ���� idx�� �������� �̵���Ű��
		�ڽź��� ū ������ ���������� �о��
		������ ��ġ�� �����Ͽ� ���ĵ� �κ��� Ȯ���ذ���

		�ð����⵵ O(n^2), �ּ� O(n)
		- ��������, �������İ� �޸� �����Ͱ� ���� ���ĵǾ� ������ �ſ� ����
		- ������ �����ϰ�, ���� �����Ϳ� ������
*/


void insertionSort(vector<int>& _data)
{
	for (int i = 1; i < _data.size(); ++i)
	{
		int iKey = _data[i]; //���ĵ��� ���� ù��°���� key �� ���Ѵ�
		int j = i - 1; //������ ���ĵȰ��̴� j�� ���ĵȰ��� ���Ѵ�

		//key���� ū���� ���������� �̵���Ų��
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