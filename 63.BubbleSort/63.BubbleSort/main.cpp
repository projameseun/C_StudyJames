
#include <iostream>
#include <vector>

using namespace std;

vector<int> BubbleSort(vector<int> data)
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
		int a = 0;
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