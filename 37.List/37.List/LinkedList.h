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

//�ʱ�ȭ ������ ����Ʈ
void InitList(FLinkedList* _pList);

//������ ����Ʈ ������ �߰�
void PushBack(FLinkedList* _pList, int _data);

//������ ����Ʈ �޸�����
void DestroyList(FLinkedList* _pList);