#include <iostream>
#include "Array.h"

#define a 100

int main()
{
	//가변 배열
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//int a = 100;
	int Array[a] = {};

	FArray arr;
	InitArr(&arr);

	for (int i = 0; i < 10; ++i)
	{
		PushBack(&arr, i);
	}

	return 0;
}