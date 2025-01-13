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
		return "�̸� : " +  m_Name +  "���� :" + to_string(m_iAge);
	}



};

ofstream& operator<<(ofstream& of, CPlayer& p)
{
	of << p.info();

	return of;
}


int main()
{


	setlocale(LC_ALL, "ko-KR");	//��� �����ڵ带 ko-kr�μ���

	//c++���� ��Ʈ�� ���

   //istream, ostreamŬ�������� ���Ͻ�Ʈ���� �����ϴ� ����� �� ����
   //�̸� ��ӹ޾Ƽ� �ۼ��Ǿ� ������ ���� ��ӹ������� ifstream, ofstream�̴�.

   //ifstream -> ���Ͽ��� �б⸦ ���� �Է� ��Ʈ��
   //ofstream -> ���Ͽ��� ���⸦ ���� ��� ��Ʈ�� 


	std::ifstream pFile("test.txt");	//������ ��θ� �����ϸ�Ǵµ� ����� ��Ʃ������� �����Ұ�쿡�� �ҽ����� ��������ο� �� ã�´�

	string str;

	if (pFile.is_open())		//������ istream���� ���� ifstream�� ��ӹ����鼭 �߰��� �Լ��̴� ������ �����ִ��� Ȯ���Ѵ�
	{
		pFile >> str;		//cinó�� pFile��ü�� �̿��ؼ� ���Ϸ� ���� �о���ϼ� �ִ�(cin������ >> �� ������ ���鹮�ڰ� ���ö����� ������ó�� �����ϴ�)
		std::cout << "�Է¹��� ���ڿ� : " << str << std::endl;

	}



	pFile.close();	//c�𿡼��� �׻� close�� ����ؼ� ������ �ݾ� ��߉�µ� c++������ �̹� ifstream��ü�� �Ҹ��ڿ��� �ڵ������� close�� ���ֱ⶧���� �����൵ �ȴ�.
	//��, ���ο� ������ ������ close�� ���ְ� open���� ������ߵȴ�.

	pFile.open("newFile.txt");

	if (pFile.is_open())
	{
		pFile >> str;
		std::cout << "�Է¹��� ���ڿ� : " << str << std::endl;

	}


	////���� ��ü �о���̱� 
	////������ġ�� ������ �ű��
	//pFile.seekg(0, ios::end);

	////���� ��ü�б�
	//size_t iSize = pFile.tellg();		//������ũ�⸦ �о���̴� �Լ� 

	//str.resize(iSize);		//���ڿ� �Ҵ�

	//pFile.seekg(0, ios::beg);

	//pFile.read(&str[0], iSize);			//���� ��ü�� �о ���ڿ������� 

	//std::cout << str << std::endl;
	////���� ��ü �о���̱� 


	/*pFile.seekg(0, ios::end);
	size_t iSize = pFile.tellg();
	pFile.seekg(0, ios::beg);*/

	pFile.seekg(0, ios::beg);

	//���� �� ��� �б�
	while (getline(pFile, str))
	{

		std::cout << str << std::endl;
	}
	//���� �����б� 
	//getline(pFile, str);
	//���� �����б� 

	{

		//���� ����
		
		//ofstream outFile("test2.txt",ios::app);	//append
		ofstream outFile("test2.txt");	//append
		string str;
		

		if (outFile.is_open())
		{
			/*outFile << " �����̱�";
			outFile << " �������� �ǳ�?";*/

			//������ �����ε��� ����ؼ� ����
			CPlayer player("���ٵ弼��", 20);

			outFile << player << std::endl;
		}


		
	}

	
	
	return 0;
}