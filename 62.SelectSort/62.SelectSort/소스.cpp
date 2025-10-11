
#include <iostream>
#include <vector>

using namespace std;



vector<int> SelectSort(vector<int> data)
{	
	//data.size() -1 �� �� ������ ������ �ε����� �̹� ���ĵǾ� �ֱ⶧���� ���� �����ʴ´�.
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