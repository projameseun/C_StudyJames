
#include <iostream>
#include <vector>

using namespace std;

vector<int> SelectSort(vector<int> data)
{
	for (int i = 0; i < data.size(); ++i)
	{
		

		for (int j = i + 1; j < data.size(); ++j)
		{
			int iTemp = 0;
			if (data[i] > data[j])
			{
	
				iTemp = data[i];
				data[i] = data[j];
				data[j] = iTemp;
							
			}
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