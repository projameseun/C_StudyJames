#pragma once
#include <assert.h>

template<class T>
struct  tFNode
{
	T				tData;
	tFNode<T>* pNextNode;
	tFNode<T>* pPrevNode;

	tFNode() :
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
	tFNode<T>* m_pHeadNode;
	//FNode* pTailNode;
	tFNode<T>* m_pTailNode;
	int			m_iCount;

public:
	CList();
	~CList();

public:
	void Pushback(const T& _data);
	void PushFront(const T& _data);
	int size()
	{
		return m_iCount;
	}

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);	//과제
	iterator insert(const iterator& _iter, const T& _data);

	class iterator
	{
	private:
		CList<T>*		m_pList;
		tFNode<T>*		m_pNode;		//nullptr인경우 end iterator이다
		bool			m_bValid;

	public:
		T& operator *()
		{
			return m_pNode->tData;
		}

		bool operator ==(const iterator& _otheriter)
		{
			if (m_pList == _otheriter.m_pList && m_pNode == _otheriter.m_pNode)
			{
				return true;
			}

			return false;
		}

		bool operator !=(const iterator& _otheriter)
		{
			/*if (m_pList == _otheriter.m_pList && m_pNode == _otheriter.m_pNode)
			{
				return true;
			}

			false;*/

			return !(*this == _otheriter);
		}

		iterator& operator ++()
		{
			//end 에서 ++ 한경우0
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}
			
			m_pNode = m_pNode->pNextNode;

			return *this;


		}
		iterator operator ++(int)
		{
			iterator copyiter = (*this);

			++(*this);

			return copyiter;

		}
		iterator& operator --()
		{
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pPrevNode;

			return *this;
		}
		iterator operator --(int)
		{
			iterator copyiter = (*this);

			--(*this);

			return copyiter;
		}


	public:
		iterator():
			m_pList(nullptr),
			m_pNode(nullptr),
			m_bValid(false)
		{
			
		}
		iterator(CList<T>* _pList, tFNode<T>* _pNode) :
			m_pList(_pList),
			m_pNode(_pNode),
			m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bValid = true;
			}
		}
		~iterator()
		{

		}

		friend class CList;

	};

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

	tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, nullptr);
	//FNode* pNode = new FNode;

	//2.삽입
	//pNode->pNextNode = nullptr;
	//pNode->pPrevNode = nullptr;
	//pNode->tData = _dat;


	//3.추가 데이터가 처음인지 아닌지
	if (nullptr == m_pHeadNode)
	{
		m_pHeadNode = pNewNode;
		m_pTailNode = pNewNode;
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

	if (nullptr == m_pHeadNode)
	{
		m_pHeadNode = pNewNode;
		m_pTailNode = pNewNode;
	}
	else
	{
		//현재 헤드노드의 이전노드 주소값을 새로생성된 노드의 주소로채움
		m_pHeadNode->pPrevNode = pNewNode;

		//리스트가 새로 생성된 노드를 새로운 헤드로 갱신
		m_pHeadNode = pNewNode;
	}



	++m_iCount;

}

template<class T>
inline typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this,m_pHeadNode);
}

template<class T>
inline typename CList<T>::iterator CList<T>::end()
{
	return iterator(this,nullptr);
}

template<class T>
inline typename CList<T>::iterator CList<T>::erase(iterator& _iter)
{
	// 1. 유효성 검사: iterator가 가리키는 리스트와 노드가 유효한지 확인
	if (_iter.m_pList != this || !_iter.m_bValid || _iter.m_pNode == nullptr)
	{
		assert(false); // Invalid iterator
		return end();
	}


	//삭제할 노드 가져오기
	tFNode<T>* pDeleteNode = _iter.m_pNode;


	
	//이전 노드와 다음노드 저장
	tFNode<T>* pPrevNode = _iter.m_pNode->pPrevNode;
	tFNode<T>* pNextNode = _iter.m_pNode->pNextNode;

	//삭제할 노드가 첫번째인경우
	if (m_pHeadNode == pDeleteNode)
	{
		m_pHeadNode = pNextNode;
	}
	else
	{
		pPrevNode->pNextNode = pNextNode;
	}

	//삭제할 노드가 마지막
	if (pDeleteNode == m_pTailNode)
	{
		m_pTailNode = pPrevNode;
	}
	else
	{
		pNextNode->pPrevNode = pPrevNode;
	}

	//노드 삭제
	delete pDeleteNode;
	--m_iCount;
	
	

	return iterator(this,pNextNode);
}

template<class T>
inline typename CList<T>::iterator CList<T>::insert(const iterator& _iter,const T& _data)
{
	if (end() == _iter)
	{
		assert(nullptr);
	}

	tFNode<T>* pNewNode = new tFNode<T>(_data,nullptr,nullptr);

	if (_iter.m_pNode == m_pHeadNode)
	{
		_iter.m_pNode->pPrevNode = pNewNode;
		pNewNode->pNextNode = _iter.m_pNode;

		m_pHeadNode = pNewNode;
		
	}
	else
	{
		//iterator가 가리키고 있는 노드의 이전으로가서
		//다음 노두 주소 파트를 새로 생성한 노드로 지정
		_iter.m_pNode->pPrevNode->pNextNode = pNewNode;
		pNewNode->pPrevNode = _iter.m_pNode->pPrevNode;

		//iterator가 가리키고 있는 노드의 이전을 새로운 노드로 지정
		//새로운 노드의 next를 iterator가 가리키고 잇는 노드로 지정
		_iter.m_pNode->pPrevNode = pNewNode;
		pNewNode->pNextNode = _iter.m_pNode;
	}


	++m_iCount;

	return iterator(this,pNewNode);
}

