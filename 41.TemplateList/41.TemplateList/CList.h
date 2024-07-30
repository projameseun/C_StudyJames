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
	//입력된 데이터 저장할 노드를 동적할당

	  tFNode<T>* pNewNode = new tFNode<T>(_data,nullptr,nullptr);
	  //FNode* pNode = new FNode;

	  //2.삽입
	  //pNode->pNextNode = nullptr;
	  //pNode->pPrevNode = nullptr;
	  //pNode->tData = _dat;
	

	  //3.추가 데이터가 처음인지 아닌지
	  if (nullptr ==  m_pHeadNode)
	  {
		  m_pHeadNode=	pNewNode;
		  m_pTailNode =		pNewNode;
	  }
	  else //추가데이터가 이미 있다는거 
	  {
		//현재 가장 마지막 데이터(tail)을 저장하고 있는노드와
		 //새로 생성된 노드가 서로 가리키게 됨 
		  m_pTailNode->pNextNode = pNewNode;
		  pNewNode->pPrevNode = m_pTailNode;

		  //list가 마지막 노드의 주소값을 새로 입력된 노드로 갱신
		  m_pTailNode = pNewNode;
	  }

	  ++m_iCount;

 }

 template<class T>
  void CList<T>::PushFront(const T& _data)
 {
	  //새로 생성된 노드의 다음을 현재 헤드노드의 주소값으로 채움
	  tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, m_pHeadNode);

	  //현재 헤드노드의 이전노드 주소값을 새로생성된 노드의 주소로채움
	  m_pHeadNode->pPrevNode = pNewNode;

	  //새로 생성된 노드를 새로 생성된 노드의 주소를  새로운 헤드주소로 갱신 
	  m_pHeadNode = pNewNode;

	  ++m_iCount;
	  
 }
