#include <iostream>


typedef struct FStudent
{

	int iKor;
	int iEng;
	int iMath;
	int Total;
	char Name[25];


	void PrintStudent()
	{
		std::cout << "�л� ������α׷�" << std::endl;
	}

	void Initial(const char* name)
	{
		int iSize = 0;
		iKor = 0;
		iEng = 0;
		iMath = 0;
		Total = 0;
		//���ں���
		iSize = strlen(name) + 1;
		strcpy_s(Name, iSize, name);
	
	}

	void StudentStudy()
	{
		std::cout << "�л����� �����ϰ� �ֽ��ϴ� " << std::endl;
		std::cout << Name << std::endl;
	}

}MyStudent;


struct FSchool
{
	MyStudent Myst;
	int iScore;
};



int main()
{
	//����ü��? �ٸ������͸� �����ش� �迭���� ��쿡�� ���� ������(�ڷ���)���� ������ �ִµ�
	//����ü�� �������� �����͸� ������ �ִ�.
	
	//c++������ ����ü�� Ŭ������ ����ϸ鼭 �ٸ��� �ϳ� �ִµ�
	//���������ڸ� ���������� �ʾ�����
	//����ü�� public , class�� priavte�� �ȴ�.

	//���������� 
	//public , private, protected 

	//public ��� ���� (�ܺ� ���ٰ���)
	//pirvate �� �ش簴ü�� ���� �������� ������� ���� (�ܺ� ���� �Ұ���)
	//protected ��ӳ��� ���� ����ü�� ��� �Ұ���

	//�������� �Ұ��� ������ ������Ʈ�� ���־ �ʱ�ȭ�� �����Ѱǵ� ��Ȯ�� ����ϸ� �߸��� �ʱ�ȭ ���̴�
	//����ó�� �������� ������Ʈ �Ӽ����� c,c++���� ���-> c�����Ϸ��� �������ָ� c��� ���� ����ü�� ��� �Ҽ� �ִ�
	 MyStudent st = {};

	 int iSize = sizeof(MyStudent);

	 st.Initial("James");
	 st.PrintStudent();
	 st.StudentStudy();

	 FSchool sc = {};
	 
	 sc.Myst.Initial("Bille");
	 sc.Myst.StudentStudy();


	return 0;
}