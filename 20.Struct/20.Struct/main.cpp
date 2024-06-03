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
		std::cout << "학생 출력프로그램" << std::endl;
	}

	void Initial(const char* name)
	{
		int iSize = 0;
		iKor = 0;
		iEng = 0;
		iMath = 0;
		Total = 0;
		//문자복사
		iSize = strlen(name) + 1;
		strcpy_s(Name, iSize, name);
	
	}

	void StudentStudy()
	{
		std::cout << "학생들이 공부하고 있습니다 " << std::endl;
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
	//구조체란? 다른데이터를 묶어준다 배열같은 경우에는 같은 데이터(자료형)끼리 묶을수 있는데
	//구조체는 여러가지 데이터를 묶을수 있다.
	
	//c++에서의 구조체는 클래스랑 비슷하면서 다른게 하나 있는데
	//접근지정자를 지정해주지 않았을때
	//구조체는 public , class는 priavte가 된다.

	//접근지정자 
	//public , private, protected 

	//public 모두 공유 (외부 접근가능)
	//pirvate 내 해당객체만 공유 안정성이 어느정도 보장 (외부 접근 불가능)
	//protected 상속끼리 공유 구조체는 사용 불가능

	//예전에는 불가능 지금은 업데이트가 되있어서 초기화가 가능한건데 정확히 얘기하면 잘못된 초기화 법이다
	//예전처럼 돌릴려면 프로젝트 속성에서 c,c++에서 고급-> c컴파일러로 변경해주면 c언어 전용 구조체로 사용 할수 있다
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