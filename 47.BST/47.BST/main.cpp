#include <iostream>
#include <map>
#include <set>
#include <string>

#include "CBST.h"

enum class Gender
{
	MAN = 1,
	WOMAN
};

struct FStdInfo
{
	//wchar_t			m_stName[20];
	std::wstring	m_stName;
	unsigned char	m_Age;
	unsigned char	m_Gender;

public:
	FStdInfo() :
		m_stName{},
		m_Age(0),
		m_Gender(0)
	{

	}

	/*FStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender) :
		m_stName{},
		m_Age(_age),
		m_Gender(_gender)
	{
		wcscpy_s(m_stName, 20, _pName);
	}*/
	FStdInfo(const std::wstring& _pName, unsigned char _age, unsigned char _gender) :
		m_stName(_pName),
		m_Age(_age),
		m_Gender(_gender)
	{
		
	}
};


//iterator로 접근했을때 pair가 이렇게 생겼을것이다
//struct pair
//{
//	const wchar_t* p;
//	FStdInfo		info;
//};

class MyClass
{
private:
	int a;

public:
	bool operator < (const MyClass& _other) const
	{
		if (a < _other.a)
			return true;
		else
			return false;
	}

};


int main()
{

	//이진탐색트리
	//트리의 모양이 밸런스가 유지되지 않으면 제대로 된 탐색 효율이 나오지 않는다
	//그래서 자가균형이필요하다 근데 우리는 이걸 만들지는 않을것이고 비슷한걸 만들것이다.
	//자가균형기능 (AVL,Red/Black)

	//map부터
	
	std::set<int> setInt;

	setInt.insert(100);
	setInt.insert(55);
	setInt.insert(150);
	
	/*
			 100
			<===>
		55		150
	
	*/

	//실제로 set을 많이 사용하지 않고 map을 사용한다 map우리가 나중에 만들 red black Binary Search Tree 로 구현되어 있다


	//맵은 타입을 2가지를 사용한다
	//맵은 key 와 value로 나뉘어지는데 key값 기준으로 오름차순으로 자동 정렬된다.
	//std::map<int, float>  mapData;

	//맵을 그림으로 표현하면
	/*
							100(float)도 들어가잇다 
							<===>
		55 (float)도 들어가잇다 		150(float)도 들어가잇다 
	
		찾아오는건 key로 찾아오겠지만 정말 중요한 data는 float이 될것이다 2번쨰인자가 

		만약에 학생정보 프로그램을 만든다고 가정할때
		문자열을 사용하여 이름으로 찾는다고하면 key값이 문자열이 될것이다.
		<이름,정보> 이런식으로 될것이다 
	*/

	

	std::map<const wchar_t*, FStdInfo>  mapData;

	FStdInfo info(L"이무열", 20, (char)Gender::MAN);
	FStdInfo info2(L"김지혜", 29, (char)Gender::WOMAN);

	mapData.insert(std::make_pair(L"이무열", info));
	mapData.insert(std::make_pair(L"김지혜", info2));

	

	std::map<const wchar_t*, FStdInfo>::iterator  mapiter;

	//pair에 첫번째는 first, 두번째는 second

	wchar_t szFind[20] = L"김지혜";	//주소가 아에다른거고
	  
	const wchar_t* pStr = L"이무열"; //이친구는 주소가 같은거다 

	//이터를 반환해줌
	mapiter = mapData.find(szFind);

	//지역설정
	_wsetlocale(LC_ALL, L"korean");

	if (mapiter == mapData.end())
	{
		std::cout << "찾지 못했다" << std::endl;
	}
	else
	{
		std::wcout << L"이름 : " << mapiter->second.m_stName << std::endl;
		std::wcout << L"나이 : " << mapiter->second.m_Age<< std::endl;
		std::wcout << L"성별 : ";
		if ((char)Gender::MAN == mapiter->second.m_Gender)
		{
			std::wcout << L"남자" << std::endl;
		}
		else if ((char)Gender::WOMAN == mapiter->second.m_Gender)
		{
			std::wcout << L"여자" << std::endl;
		}
		else
		{
			std::wcout << L"아무것도 찾지 못함" << std::endl;
		}
	}

	//위같은 경우는 문자열을 찾아서 했다고 볼수없다 
	//주소값을 비교해서 나온것이다 주소를 값을 찾은거다 .
	//우리가 원하는 문자열을 찾아서 가져올려고하면 string 함수를 사용해야된다.

	system("cls");

	std::map<std::wstring, FStdInfo> mapStdData;

	FStdInfo info3(L"김우람", 20, (char)Gender::MAN);
	FStdInfo info4(L"은진수", 29, (char)Gender::WOMAN);

	mapStdData.insert(std::make_pair(L"김우람",info3));
	mapStdData.insert(std::make_pair(L"은진수", info4));

	std::wstring stTest;

	stTest = L"은진수";

	std::map<std::wstring, FStdInfo>::iterator  mapiter2;

	mapiter2 = mapStdData.find(stTest);


	if (mapiter2 == mapStdData.end())
	{
		std::cout << "찾지 못했다" << std::endl;
	}
	else
	{
		std::wcout << L"이름 : " << mapiter2->second.m_stName << std::endl;
		std::wcout << L"나이 : " << mapiter2->second.m_Age << std::endl;
		std::wcout << L"성별 : ";
		if ((char)Gender::MAN == mapiter2->second.m_Gender)
		{
			std::wcout << L"남자" << std::endl;
		}
		else if ((char)Gender::WOMAN == mapiter2->second.m_Gender)
		{
			std::wcout << L"여자" << std::endl;
		}
		else
		{
			std::wcout << L"아무것도 찾지 못함" << std::endl;
		}
	}

	//가변 배열이랑 유사함
	std::wstring str;
	
	str = L"abcdef";
	str += L"ghi";
	str += L"jkl";
	str[1] = L'd';

	str = L"abcefekfkfkfkfkfkffkk";


	std::wstring str2;

	str2 = L"test";

	if (str == str2)
	{
		std::cout << "서로 문자열이 같습니다" << std::endl;
	}
	else
	{
		std::cout << "서로 문자열이 다릅니다" << std::endl;
	}

	//> < >= <=  다됨 


	//내가만든 클래스
	std::map<MyClass, FStdInfo> MyMap;

	MyClass a;

	//처음에 MYClass를 할때 사용을할수 없는데 operator가 없어서 그렇다 
	MyMap.insert(std::make_pair(a, info));

	system("cls");

	//우리가 만든 이진탐색트리
	
	CBST<int, int> BstInt;

	//FPair<int, int> pair;

	/*pair.first = 50;

	BstInt.insert(pair);

	pair.first = 100;

	BstInt.insert(pair);

	pair.first = 150;

	BstInt.insert(pair);*/
	
	BstInt.insert(make_mypair(100, 0));
	BstInt.insert(make_mypair(50, 0));
	BstInt.insert(make_mypair(25, 0));
	BstInt.insert(make_mypair(30, 0));
	BstInt.insert(make_mypair(200, 0));
	BstInt.insert(make_mypair(300, 0));

	CBST<int, int>::iterator iter = BstInt.begin();

	iter = BstInt.find(200);

	iter = BstInt.begin();
	++iter;
	++iter;

	--iter;

	for (iter = BstInt.begin(); iter != BstInt.end(); ++iter)
	{
		std::cout << iter->first << std::endl;
	}

	

	int testt = 0;

	return 0;
}