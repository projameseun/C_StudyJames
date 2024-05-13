#include <iostream>

int main()
{
	/*
		조건문:if , switch
		조건문이란? 어떤 특정 조건식을 부여하고 해당 조건을 만족하면 지정한 문장을 수행하는 문법
		if문
		if(조건식)
		{

		}코드블럭
		
		조건식이  true일 경우 코드블럭이 작동이 되고, false면 if조건문을 나가게 된다.

	*/
	
	if (true)
	{
		std::cout << "진실 입니다" << std::endl;
	}
	if (false)
	{
		std::cout << "거짓 입니다" << std::endl;
	}

	/*
		else : if문과 같이 사용수 있다.
		if문 1개당 1개의 else가 올수 있다.
		else 독립적으로 사용이 불가능 하다.

	*/

	int iNumber = 100;

	if (iNumber == 100)
	{
		std::cout << "iNumber = " << iNumber << std::endl;
	}
	else
	{
		std::cout << "iNumber는 100이 아닙니다" << std::endl;
	}
	
	/*
		else if: if문 아래올수 있다. else와 다르게 여러개를 만들수 있다.
		else if는 독립적으로 사용이 불가능 하다.
	*/

	//예를들어 로스트아크
	//int iEchidnaHP = 100000000;

	//if (iEchidnaHP == 100000000)
	//{
	//	//첫번째 이벤트 발생
	//	std::cout << "1번째 이벤트 발생" << std::endl;
	//}
	//else if (iEchidnaHP < 800000 && iEchidnaHP > 50000)
	//{
	//	std::cout << "2번째 이벤트 발생" << std::endl;
	//}
	//else if (iEchidnaHP < 50000 && iEchidnaHP > 13000)
	//{
	//	std::cout << "3번째 이벤트 발생" << std::endl;
	//}
	//else if (iEchidnaHP < 13000 && iEchidnaHP > 1200)
	//{
	//	std::cout << "4번째 이벤트 발생" << std::endl;
	//}
	//else
	//{
	//	std::cout << "5번째 이벤트 발생" << std::endl;
	//}
	
	//학생평균 프로그램

	int iKor = 0;
	int iEng = 0;
	int iMath = 0;
	int iTotal = 0;


	//소수점 자리가 없는 float일경우에는 .f로 수소점 0을 생략할수 있다 ex) 1.0f == 1.f;
	float fAvg = 0.f;
	//평균(Average)
	// 화면을 아에 깨끗이 지우는 함수 Winodws.h 파일이 필요하다
	system("cls");

	std::cout << "국어점수 : ";
	std::cin >> iKor;
	system("cls");
	std::cout << "영어점수 : ";
	std::cin >> iEng;
	system("cls");
	std::cout << "수학점수 : ";
	std::cin >> iMath;
	system("cls");

	std::cout << iKor << std::endl;
	std::cout << iEng << std::endl;
	std::cout << iMath << std::endl;

	iTotal = iKor + iEng + iMath;

	fAvg = iTotal / 3.f;

	std::cout << "평균 : " << static_cast<int>(fAvg) << "입니다" << std::endl;


	if (fAvg >= 90.f)
	{
		std::cout << "축하드립니다 A학점입니다." << std::endl;
	}
	//평균이 80보다 크거나 같고 평균이 90보다 작을때  //  80 ~ 89
	else if (fAvg >= 80.f && fAvg < 90.f)
	{
		std::cout << "축하드립니다 B학점입니다." << std::endl;
	}
	else if (fAvg >= 70.f && fAvg < 80.f)
	{
		std::cout << "축하드립니다 C학점입니다." << std::endl;
	}
	else
	{
		std::cout << "F학점입니다." << std::endl;
	}

	return 0;
}