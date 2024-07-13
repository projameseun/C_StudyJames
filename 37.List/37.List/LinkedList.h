#pragma once

struct FNode
{
	int iData;
	FNode* pNextNode;
};

struct FLinkedList
{
	FNode* pHeadNode; 
	//FNode* pTailNode;
	int iCount;
};

//초기화 연결형 리스트
void InitList(FLinkedList* _pList);

//연결형 리스트 데이터 추가
void PushBack(FLinkedList* _pList, int _data);

//연결형 리스트 메모리해제
void DestroyList(FLinkedList* _pList);