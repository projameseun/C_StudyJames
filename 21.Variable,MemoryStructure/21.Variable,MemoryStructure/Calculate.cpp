#include "Calculate.h"
#include <iostream>

int Add(int a, int b)
{
	return a + b;
}

int Minus(int a, int b)
{
	return a -b;
}

int Multi(int a, int b)
{
	return a * b;
}

int Module(int a, int b)
{
	return a % b;
}

int Divide(int a, int b)
{
	return a / b;
}


void CalFun()
{
	g_StaticNum++;
	g_StaticNum++;
	g_StaticNum++;

	std::cout << "Cal 함수의 스태틱 변수의 값 : " << g_StaticNum << std::endl;
}

void StaticAdress()
{
	std::cout << "Cal 함수의 스태틱 주소 : " << &g_StaticNum << std::endl;
}

void ExAddress()
{
	std::cout << "Ex의 주소 : " << &g_exNum << std::endl;
}

void ExFunc()
{
	g_exNum++;
	
	std::cout << "Ex의 값 :" << g_exNum << std::endl;
}

extern int g_exNum = 0;