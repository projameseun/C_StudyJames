#include <iostream>
#include "Array.h"

void InitArr(FArray* pArr)
{
	//pArr->pData = new int;
	pArr->pData = (int*)malloc(sizeof(int) * 2);
	pArr->iSize = 0;
	pArr->iMaxSize = 2;
}

void ReleaseArr(FArray* pArr)
{
	if (pArr != nullptr)
	{
		
		//free(pArr->pData);
			
		delete pArr->pData;
		pArr->iSize = 0;
		pArr->iMaxSize = 0;
	}
}

void PushBack(FArray* pArr, int idata)
{
	if (pArr->iMaxSize <= pArr->iSize)
	{
		//재할당
		Reallcate(pArr);
	}
	
	//데이터추가
	pArr->pData[pArr->iSize++] = idata;
}

void DestroyArr(FArray* pArr)
{
	//if (pArr != nullptr)
	//{
	//	delete[] pArr;
	//	pArr = nullptr;
	//}

	

	if (pArr != nullptr)
	{
		//free(pArr->pInt);
		delete[] pArr->pData;
		pArr->iSize = 0;
		pArr->iMaxSize = 0;

	}

}

void Reallcate(FArray* pArr)
{
	int* ptr = (int*)malloc(pArr->iMaxSize * 2 * sizeof(int));


	//int* ptr = new int[pArr->iMaxSize * 2 ];
	//기존공간에 있던 데이터를 새로 할당한 공간으로 복사해 준다.
	for (int i = 0; i < pArr->iSize; ++i)
	{
		ptr[i] = pArr->pData[i];
	}

	//힙에러
	//HEAP CORRUPTION DETECTED
	//malloc이나 new로 할당한 메모리의 영역보다 더 큰 영역에 접근하고자 했기 때문이다.
	//이 에러의 문제는 바로 나오는게 아니라 나중에 나와서 찾기가 매우힘들다.


	//기존공간은 메모리 해제 
	delete[] pArr->pData;
	//free(pArr->pInt);
	//배열이 새로 할당된 공간을 가리킨다
	pArr->pData = ptr;
	//MaxSize 늘려주기
	pArr->iMaxSize *= 2;
	
}

void Sort(FArray* pArr, void(*_SortFunc)(int*, int))
{
	_SortFunc(pArr->pData, pArr->iSize);
}

