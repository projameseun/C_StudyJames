#pragma once

struct FArray
{
	int*	pData;
	int		iSize;
	int		iMaxSize;
	


};


void InitArr(FArray* pArr);

//���� �Լ�
void ReleaseArr(FArray* pArr);

//�߰��Լ�
void PushBack(FArray* pArr, int idata);

//�����Լ�
void DestroyArr(FArray* pArr);

void Reallcate(FArray* pArr);