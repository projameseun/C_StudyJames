#include <iostream>

int main()
{
	//Bit������ Shift�����ڸ� �̿��ؼ� RGB�� ������
	//32��ƮĮ�� 0~255���ڸ��� �ִ´�

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


	// f : 15�� ������ 2������ 1111 �� �����Եȴ�. 11111111�� & ������ �ϴ°��̴�.
	std::cout << "Blue = " << (iColor & 0x00000000ff) << std::endl;
	std::cout << "Green = " << (iColor >> 8 & 0x00000000ff) << std::endl;
	std::cout << "Red = " << (iColor >> 16 & 0x00000000ff) << std::endl;
	std::cout << "Alpha = " << (iColor >> 24 & 0x00000000ff) << std::endl;

	return 0;
}