#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CPlayer
{
	string	m_Name;
	int		m_iAge;

public:
	CPlayer(const string& _name, int _age) :
		m_Name(_name), m_iAge(_age)
	{
		
	}

public:
	string info()
	{
		return "이름 : " +  m_Name +  "나이 :" + to_string(m_iAge);
	}



};

ofstream& operator<<(ofstream& of, CPlayer& p)
{
	of << p.info();

	return of;
}


int main()
{


	setlocale(LC_ALL, "ko-KR");	//언어 지역코드를 ko-kr로설정

	//c++파일 스트림 방식

   //istream, ostream클래스보다 파일스트림이 지원하는 기능이 더 많다
   //이를 상속받아서 작성되어 있으면 각각 상속받은것이 ifstream, ofstream이다.

   //ifstream -> 파일에서 읽기를 위한 입력 스트림
   //ofstream -> 파일에서 쓰기를 위한 출력 스트림 


	std::ifstream pFile("test.txt");	//파일의 경로를 전달하면되는데 비쥬얼 스튜디오에서 실행할경우에는 소스파일 과같은경로에 서 찾는다

	string str;

	if (pFile.is_open())		//기존의 istream에는 없고 ifstream에 상속받으면서 추가된 함수이다 파일이 열려있는지 확인한다
	{
		pFile >> str;		//cin처럼 pFile객체를 이용해서 파일로 부터 읽어들일수 있다(cin에세ㅓ >> 로 읽을때 공백문자가 나올때까지 읽은것처럼 동일하다)
		std::cout << "입력받은 문자열 : " << str << std::endl;

	}



	pFile.close();	//c언에서는 항상 close를 사용해서 파일을 닫아 줘야됬는데 c++에서는 이미 ifstream객체의 소멸자에서 자동적으로 close를 해주기때문에 안해줘도 된다.
	//단, 새로운 파일을 열려면 close를 해주고 open으로 열어줘야된다.

	pFile.open("newFile.txt");

	if (pFile.is_open())
	{
		pFile >> str;
		std::cout << "입력받은 문자열 : " << str << std::endl;

	}


	////파일 전체 읽어들이기 
	////파일위치를 끝으로 옮긴다
	//pFile.seekg(0, ios::end);

	////파일 전체읽기
	//size_t iSize = pFile.tellg();		//파일의크기를 읽어들이는 함수 

	//str.resize(iSize);		//문자열 할당

	//pFile.seekg(0, ios::beg);

	//pFile.read(&str[0], iSize);			//파일 전체를 읽어서 문자열에저장 

	//std::cout << str << std::endl;
	////파일 전체 읽어들이기 


	/*pFile.seekg(0, ios::end);
	size_t iSize = pFile.tellg();
	pFile.seekg(0, ios::beg);*/

	pFile.seekg(0, ios::beg);

	//한줄 씩 모두 읽기
	while (getline(pFile, str))
	{

		std::cout << str << std::endl;
	}
	//파일 한줄읽기 
	//getline(pFile, str);
	//파일 한줄읽기 

	{

		//파일 쓰기
		
		//ofstream outFile("test2.txt",ios::app);	//append
		ofstream outFile("test2.txt");	//append
		string str;
		

		if (outFile.is_open())
		{
			/*outFile << " 덧붙이기";
			outFile << " 여러개가 되나?";*/

			//연산자 오버로딩을 사용해서 저장
			CPlayer player("힐바드세여", 20);

			outFile << player << std::endl;
		}


		
	}

	
	
	return 0;
}