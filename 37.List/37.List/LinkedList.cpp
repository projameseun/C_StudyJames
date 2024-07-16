#include <iostream>
#include "LinkedList.h"

void InitList(FLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;

}

void PushBack(FLinkedList* _pList, int _data)
{
	//1.노드생성
	//노드는 프로그램이 실행될 동안 계속 존재 해야되서 동적할당 사용
	
	FNode* pNode = (FNode*)malloc(sizeof(FNode));
	//FNode* pNode = new FNode;

	//2.삽입
	pNode->iData = _data;
	pNode->pNextNode = nullptr;	 //노드 입장에서 다음노드는 마지막 노드이다.

	//3.추가 데이터가 처음인지 아닌지
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else //추가데이터가 이미 있다는거 
	{
		//헤드노드는 첫번째 주소를 알고있다
		//해당 노드의 nextNode를 생성시킨 노드의 주소로 채움
		FNode* pTempNode = _pList->pHeadNode;
		while (pTempNode->pNextNode) //true
		{
			/*if (pTempNode->pNextNode == nullptr)
			{
				break;
			}*/

			pTempNode = pTempNode->pNextNode;
			
		}

		pTempNode->pNextNode = pNode;
	}

	_pList->iCount++;
}

void PushFront(FLinkedList* _pList,int _data)
{
	//새로 생성시킨 노드의 다음을 기존의 헤드로 지정
	FNode* pNode = (FNode*)malloc(sizeof(FNode));

	pNode->iData = _data;
	pNode->pNextNode = _pList->pHeadNode;

	//해당 노드 포인터 갱신
	_pList->pHeadNode = pNode;

	//카운터증가
	++_pList->iCount;
	
}


//재귀방식
void Destroy(FNode* _pNode)
{
	if (nullptr == _pNode)
	{
		return;
	}

	Destroy(_pNode->pNextNode);

	free(_pNode);

}

void DestroyList(FLinkedList* _pList)
{
	//Destroy(_pList->pHeadNode);

	FNode* pDelNode = _pList->pHeadNode;

	while (pDelNode)
	{
		FNode* pNext = pDelNode->pNextNode;
		free(pDelNode);
		pDelNode = pNext;
	}
}

