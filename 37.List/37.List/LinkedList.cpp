#include <iostream>
#include "LinkedList.h"

void InitList(FLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;

}

void PushBack(FLinkedList* _pList, int _data)
{
	//1.������
	//���� ���α׷��� ����� ���� ��� ���� �ؾߵǼ� �����Ҵ� ���
	
	FNode* pNode = (FNode*)malloc(sizeof(FNode));
	//FNode* pNode = new FNode;

	//2.����
	pNode->iData = _data;
	pNode->pNextNode = nullptr;	 //��� ���忡�� �������� ������ ����̴�.

	//3.�߰� �����Ͱ� ó������ �ƴ���
	if (_pList->iCount == 0)
	{
		_pList->pHeadNode = pNode;
	}
	else //�߰������Ͱ� �̹� �ִٴ°� 
	{
		//������ ù��° �ּҸ� �˰��ִ�
		//�ش� ����� nextNode�� ������Ų ����� �ּҷ� ä��
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
	//���� ������Ų ����� ������ ������ ���� ����
	FNode* pNode = (FNode*)malloc(sizeof(FNode));

	pNode->iData = _data;
	pNode->pNextNode = _pList->pHeadNode;

	//�ش� ��� ������ ����
	_pList->pHeadNode = pNode;

	//ī��������
	++_pList->iCount;
	
}


//��͹��
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
