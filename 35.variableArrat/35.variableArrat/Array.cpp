#include <iostream>
#include "Array.h"

void FArray::InitArr(FArray* pArr)
{
	pArr->pData = new int[];
	pArr->pData = (int*)malloc(sizeof(int) * 2);
	pArr->iSize = 0;
	pArr->iMaxSize = 2;
}
