#pragma once
#include <iostream>



class Om
{
	unsigned char m_Type;	//0이면 빈자리 , 1이면 흑돌 ,2 이면 백돌

	int m_Xpos;
	int m_Ypos;

public:
	void OmokMap(int colum, int row);
	


};

