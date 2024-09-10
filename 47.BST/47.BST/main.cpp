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


//iterator�� ���������� pair�� �̷��� ���������̴�
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

	//����Ž��Ʈ��
	//Ʈ���� ����� �뷱���� �������� ������ ����� �� Ž�� ȿ���� ������ �ʴ´�
	//�׷��� �ڰ��������ʿ��ϴ� �ٵ� �츮�� �̰� �������� �������̰� ����Ѱ� ������̴�.
	//�ڰ�������� (AVL,Red/Black)

	//map����
	
	std::set<int> setInt;

	setInt.insert(100);
	setInt.insert(55);
	setInt.insert(150);
	
	/*
			 100
			<===>
		55		150
	
	*/

	//������ set�� ���� ������� �ʰ� map�� ����Ѵ� map�츮�� ���߿� ���� red black Binary Search Tree �� �����Ǿ� �ִ�


	//���� Ÿ���� 2������ ����Ѵ�
	//���� key �� value�� ���������µ� key�� �������� ������������ �ڵ� ���ĵȴ�.
	//std::map<int, float>  mapData;

	//���� �׸����� ǥ���ϸ�
	/*
							100(float)�� ���մ� 
							<===>
		55 (float)�� ���մ� 		150(float)�� ���մ� 
	
		ã�ƿ��°� key�� ã�ƿ������� ���� �߿��� data�� float�� �ɰ��̴� 2�������ڰ� 

		���࿡ �л����� ���α׷��� ����ٰ� �����Ҷ�
		���ڿ��� ����Ͽ� �̸����� ã�´ٰ��ϸ� key���� ���ڿ��� �ɰ��̴�.
		<�̸�,����> �̷������� �ɰ��̴� 
	*/

	

	std::map<const wchar_t*, FStdInfo>  mapData;

	FStdInfo info(L"�̹���", 20, (char)Gender::MAN);
	FStdInfo info2(L"������", 29, (char)Gender::WOMAN);

	mapData.insert(std::make_pair(L"�̹���", info));
	mapData.insert(std::make_pair(L"������", info2));

	

	std::map<const wchar_t*, FStdInfo>::iterator  mapiter;

	//pair�� ù��°�� first, �ι�°�� second

	wchar_t szFind[20] = L"������";	//�ּҰ� �ƿ��ٸ��Ű�
	  
	const wchar_t* pStr = L"�̹���"; //��ģ���� �ּҰ� �����Ŵ� 

	//���͸� ��ȯ����
	mapiter = mapData.find(szFind);

	//��������
	_wsetlocale(LC_ALL, L"korean");

	if (mapiter == mapData.end())
	{
		std::cout << "ã�� ���ߴ�" << std::endl;
	}
	else
	{
		std::wcout << L"�̸� : " << mapiter->second.m_stName << std::endl;
		std::wcout << L"���� : " << mapiter->second.m_Age<< std::endl;
		std::wcout << L"���� : ";
		if ((char)Gender::MAN == mapiter->second.m_Gender)
		{
			std::wcout << L"����" << std::endl;
		}
		else if ((char)Gender::WOMAN == mapiter->second.m_Gender)
		{
			std::wcout << L"����" << std::endl;
		}
		else
		{
			std::wcout << L"�ƹ��͵� ã�� ����" << std::endl;
		}
	}

	//������ ���� ���ڿ��� ã�Ƽ� �ߴٰ� �������� 
	//�ּҰ��� ���ؼ� ���°��̴� �ּҸ� ���� ã���Ŵ� .
	//�츮�� ���ϴ� ���ڿ��� ã�Ƽ� �����÷����ϸ� string �Լ��� ����ؾߵȴ�.

	system("cls");

	std::map<std::wstring, FStdInfo> mapStdData;

	FStdInfo info3(L"����", 20, (char)Gender::MAN);
	FStdInfo info4(L"������", 29, (char)Gender::WOMAN);

	mapStdData.insert(std::make_pair(L"����",info3));
	mapStdData.insert(std::make_pair(L"������", info4));

	std::wstring stTest;

	stTest = L"������";

	std::map<std::wstring, FStdInfo>::iterator  mapiter2;

	mapiter2 = mapStdData.find(stTest);


	if (mapiter2 == mapStdData.end())
	{
		std::cout << "ã�� ���ߴ�" << std::endl;
	}
	else
	{
		std::wcout << L"�̸� : " << mapiter2->second.m_stName << std::endl;
		std::wcout << L"���� : " << mapiter2->second.m_Age << std::endl;
		std::wcout << L"���� : ";
		if ((char)Gender::MAN == mapiter2->second.m_Gender)
		{
			std::wcout << L"����" << std::endl;
		}
		else if ((char)Gender::WOMAN == mapiter2->second.m_Gender)
		{
			std::wcout << L"����" << std::endl;
		}
		else
		{
			std::wcout << L"�ƹ��͵� ã�� ����" << std::endl;
		}
	}

	//���� �迭�̶� ������
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
		std::cout << "���� ���ڿ��� �����ϴ�" << std::endl;
	}
	else
	{
		std::cout << "���� ���ڿ��� �ٸ��ϴ�" << std::endl;
	}

	//> < >= <=  �ٵ� 


	//�������� Ŭ����
	std::map<MyClass, FStdInfo> MyMap;

	MyClass a;

	//ó���� MYClass�� �Ҷ� ������Ҽ� ���µ� operator�� ��� �׷��� 
	MyMap.insert(std::make_pair(a, info));

	system("cls");

	//�츮�� ���� ����Ž��Ʈ��
	
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