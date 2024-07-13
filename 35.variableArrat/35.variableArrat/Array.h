#pragma once

struct FArray
{
	int*	pData;
	int		iSize;
	int		iMaxSize;
	


};


void InitArr(FArray* pArr);

//해제 함수
void ReleaseArr(FArray* pArr);

//추가함수
void PushBack(FArray* pArr, int idata);

//삭제함수
void DestroyArr(FArray* pArr);

void Reallcate(FArray* pArr);

//정렬
void Sort(FArray* pArr,void(*_SortFunc)(int*,int));