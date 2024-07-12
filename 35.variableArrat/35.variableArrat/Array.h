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

void Reallcate(FArray* pArr);