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

	std::cout << "Cal �Լ��� ����ƽ ������ �� : " << g_StaticNum << std::endl;
}

void StaticAdress()
{
	std::cout << "Cal �Լ��� ����ƽ �ּ� : " << &g_StaticNum << std::endl;
}

void ExAddress()
{
	std::cout << "Ex�� �ּ� : " << &g_exNum << std::endl;
}

void ExFunc()
{
	g_exNum++;
	
	std::cout << "Ex�� �� :" << g_exNum << std::endl;
}

extern int g_exNum = 0;