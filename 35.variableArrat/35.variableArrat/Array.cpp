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
		//���Ҵ�
		Reallcate(pArr);
	}
	
	//�������߰�
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
	//���������� �ִ� �����͸� ���� �Ҵ��� �������� ������ �ش�.
	for (int i = 0; i < pArr->iSize; ++i)
	{
		ptr[i] = pArr->pData[i];
	}

	//������
	//HEAP CORRUPTION DETECTED
	//malloc�̳� new�� �Ҵ��� �޸��� �������� �� ū ������ �����ϰ��� �߱� �����̴�.
	//�� ������ ������ �ٷ� �����°� �ƴ϶� ���߿� ���ͼ� ã�Ⱑ �ſ������.


	//���������� �޸� ���� 
	delete[] pArr->pData;
	//free(pArr->pInt);
	//�迭�� ���� �Ҵ�� ������ ����Ų��
	pArr->pData = ptr;
	//MaxSize �÷��ֱ�
	pArr->iMaxSize *= 2;
	
}

void Sort(FArray* pArr, void(*_SortFunc)(int*, int))
{
	_SortFunc(pArr->pData, pArr->iSize);
}

