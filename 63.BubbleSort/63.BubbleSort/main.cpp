
#include <iostream>
#include <vector>

using namespace std;

//��������
//������ �� ���Ҹ� �ݺ������� ���Ͽ�, �� ū ���� �ڷ�(��������)������ ����� ���� �˰���
//�ð����⵵:O(n^2)
//���� �����Ϳ� ����,�뷮 �����Ϳ��� ��ȿ��
//�������� ���� ��ȿ���� 

vector<int> BubbleSort(vector<int> data)
{
	for (int i = 0; i < data.size(); ++i)
	{

		// data.size()-i -1 �� ������
		//�������Ŀ��� �̹� ���ĵ� �κ��� �����ϰ� ���ؾ� �� ������ �ε����� ��Ÿ����
		//���� ������ �� ���� �ٱ� �ݺ�(i)�� ���� ������ ���� ū ���� �� �ڷ� �̵��Ѵ�
		//	��, �ٱ� �ݺ��� �� �� ����� ������ ������ i�� ���Ҵ� �̹� ���ĵǾ� �����Ƿ�,
		//	���� �ݺ�(j)������ �� �κ��� �ٽ� ���� �ʿ䰡 ����.

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