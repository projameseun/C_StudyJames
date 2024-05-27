#include <iostream>
#include <stdio.h>

int main()
{
	//c++ 입출력방식
	std::cout << "Hellow Word\n";

	int iNum = 0;

	//std::cin >> iNum;

	//C언어 입출력 방식
	printf("안녕하세요\n");
	printf("방갑습니다\n");
	printf("ProJamesEun\n");

	iNum = 10;

	float fNum = 3.14f;

	printf("James Hellow%d", iNum);
	printf("James Hellow%.1f\n",fNum);


	//c언어 입력
	//주소 & 
	scanf_s("%d", &iNum);

	std::cout << "iNum = " << iNum << std::endl;

	scanf_s("%f", &fNum);

	std::cout << "fNum = " << fNum << std::endl;

	return 0;
}