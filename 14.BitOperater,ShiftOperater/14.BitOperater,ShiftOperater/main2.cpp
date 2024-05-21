#include <iostream>

int main()
{
	//Bit연산자 Shift연산자를 이용해서 RGB를 만들어보기
	//32비트칼라 0~255숫자만을 넣는다

	unsigned int iColor = 0;

	unsigned char iAlpha = 100;
	unsigned char iRed = 150;
	unsigned char iGreen = 50;
	unsigned char iBlue = 30;


	iColor = iAlpha;
	iColor <<= 8;

	iColor |= iRed;
	iColor <<= 8;

	iColor |= iGreen;
	iColor <<= 8;

	iColor |= iBlue;

	std::cout << "iColor = " << iColor << std::endl;


	// f : 15기 때문에 2진수로 1111 이 나오게된다. 11111111과 & 연산을 하는것이다.
	std::cout << "Blue = " << (iColor & 0x00000000ff) << std::endl;
	std::cout << "Green = " << (iColor >> 8 & 0x00000000ff) << std::endl;
	std::cout << "Red = " << (iColor >> 16 & 0x00000000ff) << std::endl;
	std::cout << "Alpha = " << (iColor >> 24 & 0x00000000ff) << std::endl;

	return 0;
}