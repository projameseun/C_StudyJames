#pragma once

template<class T>
struct  tFNode
{
	T				tData;
	tFNode<T>*		pNextNode;
	tFNode<T>*		pPrevNode;

	tFNode():
		tData(),
		pNextNode(nullptr),
		pPrevNode(nullptr)
	{
		
	}
	tFNode(const T& _data, tFNode<T>* _pPrev, tFNode<T>* _pNext)
		:tData(_data),
		pPrevNode(_pPrev),
		pNextNode(_pNext)
	{

	}
};

template<class T>
class CList
{
private:
	tFNode<T>*	m_pHeadNode;
	//FNode* pTailNode;
	tFNode<T>*	m_pTailNode;
	int			m_iCount;

public:
	CList();
	~CList();

public:
	void Pushback(const T& _data);
	void PushFront(const T& _data);
};

template<class T>
CList<T>::CList() :
	m_pHeadNode(nullptr),
	m_pTailNode(nullptr),
	m_iCount(0)
{

}

template<class T>
 CList<T>::~CList()
{
	 
	 //Destroy(_pList->pHeadNode);

	 tFNode<T>* pDelNode = m_pHeadNode;

	 while (pDelNode)
	 {
		 tFNode<T>* pNext = pDelNode->pNextNode;
		 delete(pDelNode);
		 pDelNode = pNext;
	 }

}

 template<class T>
  void CList<T>::Pushback(const T& _data)
 {
	//�Էµ� ������ ������ ��带 �����Ҵ�

	  tFNode<T>* pNewNode = new tFNode<T>(_data,nullptr,nullptr);
	  //FNode* pNode = new FNode;

	  //2.����
	  //pNode->pNextNode = nullptr;
	  //pNode->pPrevNode = nullptr;
	  //pNode->tData = _dat;
	

	  //3.�߰� �����Ͱ� ó������ �ƴ���
	  if (nullptr ==  m_pHeadNode)
	  {
		  m_pHeadNode=	pNewNode;
		  m_pTailNode =		pNewNode;
	  }
	  else //�߰������Ͱ� �̹� �ִٴ°� 
	  {
		//���� ���� ������ ������(tail)�� �����ϰ� �ִ³���
		 //���� ������ ��尡 ���� ����Ű�� �� 
		  m_pTailNode->pNextNode = pNewNode;
		  pNewNode->pPrevNode = m_pTailNode;

		  //list�� ������ ����� �ּҰ��� ���� �Էµ� ���� ����
		  m_pTailNode = pNewNode;
	  }

	  ++m_iCount;

 }

 template<class T>
  void CList<T>::PushFront(const T& _data)
 {
	  //���� ������ ����� ������ ���� ������� �ּҰ����� ä��
	  tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, m_pHeadNode);

	  //���� ������� ������� �ּҰ��� ���λ����� ����� �ּҷ�ä��
	  m_pHeadNode->pPrevNode = pNewNode;

	  //���� ������ ��带 ���� ������ ����� �ּҸ�  ���ο� ����ּҷ� ���� 
	  m_pHeadNode = pNewNode;

	  ++m_iCount;
	  
 }
