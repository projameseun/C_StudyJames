#include <iostream>
using namespace std;
/*
	해시 테이블 
	해시 함수를 사용하여 변환한 값을 색인(idex)으로 삼아
	키(key) 와   데이터(value)를 저정하는 자료구조 이다.
	기본연산으로는 탐색,삽입,삭제가 있다.

	DAT(DirectAdressingTable)
	가장 간단한 형태의 해시테이블로 이름 뜻대로 키 값을 주소로 사용하는 테이블을 말한다.
	이는 키 값이 100이라고 했을때  배열의  인덱스 100에 원하는 데이터를 저장하는것이다.

*/

//1차원패턴

//1차원패턴찾기
//char vect[12] = "BTABCQABC";
//char pattern[4] = "ABC";
//
//bool IsPattern(int startIdx)
//{
//	for (int i = 0; i < 3; ++i)
//	{
//		if (pattern[i] != vect[startIdx + i])
//		{
//			return false;
//		}
//	}
//
//	return true;
//}

//2차원 패턴
int vect[3][5] =
{
	1,2,3,4,1,
	3,1,0,0,1,
	2,3,4,1,2,
};

int pattern[3] = { 3,4,1 };

bool isPattern(int dy, int dx)
{
	for (int i = 0; i < 3; ++i)
	{
		if (pattern[i] != vect[dy][dx + i])
		{
			return false;
		}
	}

	return true;
}

int main()
{


	int size = 0;

	bool ret = false;

	//1차원패턴
	//for (int i = 0; i < 12; ++i)
	//{
	//	if (vect[i] == '\0')
	//	{
	//		size = i + 1;
	//		break;
	//	}
	//}

	//for (int i = 0; i < size; ++i)
	//{
	//	if (IsPattern(i) == true)
	//	{
	//		std::cout << "시작되는 패턴 인덱스 : " << i << endl;
	//		break;
	//	}
	//}
	//1차원패턴

	//2차원패턴
	//for (int y = 0; y < 3; ++y)
	//{
	//	for (int x = 0; x < 3; ++x)
	//	{
	//		ret = isPattern(y, x);
	//		if (ret)
	//			break;
	//	}
	//}

	//if (ret == true)
	//{
	//	cout << "존재";
	//}
	//else
	//{
	//	cout << "노존재";
	//}
	////2차원패턴

	//HashTable-DAT
	int bucket[256] = {};
	char target = 'A';
	//'A'의 아스키코드는 65
	//bucket[65] 배열에 1을 대입
	bucket[target] = 1;

	//배열에 존재하는 알파벳 갯수 찾기
	int bucket2[256] = {};
	char str[7] = "ADBFAD";
	
	for (int i = 0; i < 6; ++i)
	{
		//아스키코드 자체를 인덱스로 사용
		int idx = str[i];
		bucket2[idx]++;
	}

	//배열에 존재하는 알파벳 찾기
	int bucket3[256] = {};
	char str2[7] = "ADBFAC";
	
	for (int i = 0; i < 6; ++i)
	{
		char idx = str2[i];
		bucket3[idx]++;
	}

	for (int x = 0; x < 256; ++x)
	{
		if (bucket3[x] != 0)
		{
			//알파벳종류,알파벳의 갯수를 함께출력
			cout << (char)x << " : " << bucket3[x] << "개\n";
		}
	}


	return 0;
}