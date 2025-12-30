#include <iostream>

using namespace std;
/*
	마스킹이란?
	일부를 가리는것을 말한다.
	마스킹은 기호의 열 또는 비트 패턴을 대상으로 그 일부를 추철하거나 삭제하는 것이다.
	주로 개인정보 등을 보호하기 위해 많이 쓰인다.
	단순하게 
	1,0이 들어있는 배열을 단순하게 색칠해서 나타낼수 있는 기법이기도 하다.
	내가 원하는  값만 뽑아내기 위해,필요 없는 값을 필터에 거르는 작업을 뜻한다.
*/
int main()
{
	int mask[4] = { 1,1,0,1 };
	int arr[4] = { 3,599,299,18 };
	int ret[4] = { 0,0,0,0 };

	for (int i = 0; i < 4; ++i)
	{
		if (mask[i] == 1)
		{
			ret[i] = arr[i];
		}
	}

	cout << "원본 배열 :";
	for (int i = 0; i < 4; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	cout << "마스크  배열 : ";
	for (int i = 0; i < 4; ++i)
	{
		cout << ret[i] << " ";
	}
	return 0;
}