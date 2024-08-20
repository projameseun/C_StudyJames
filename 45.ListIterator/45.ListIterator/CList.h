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
	iterator erase(iterator& _iter);	//����
	iterator insert(const iterator& _iter, const T& _data);

	class iterator
	{
	private:
		CList<T>*		m_pList;
		tFNode<T>*		m_pNode;		//nullptr�ΰ�� end iterator�̴�
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
			//end ���� ++ �Ѱ��0
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
	//�Էµ� ������ ������ ��带 �����Ҵ�

	tFNode<T>* pNewNode = new tFNode<T>(_data, nullptr, nullptr);
	//FNode* pNode = new FNode;

	//2.����
	//pNode->pNextNode = nullptr;
	//pNode->pPrevNode = nullptr;
	//pNode->tData = _dat;


	//3.�߰� �����Ͱ� ó������ �ƴ���
	if (nullptr == m_pHeadNode)
	{
		m_pHeadNode = pNewNode;
		m_pTailNode = pNewNode;
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

	if (nullptr == m_pHeadNode)
	{
		m_pHeadNode = pNewNode;
		m_pTailNode = pNewNode;
	}
	else
	{
		//���� ������� ������� �ּҰ��� ���λ����� ����� �ּҷ�ä��
		m_pHeadNode->pPrevNode = pNewNode;

		//����Ʈ�� ���� ������ ��带 ���ο� ���� ����
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
	// 1. ��ȿ�� �˻�: iterator�� ����Ű�� ����Ʈ�� ��尡 ��ȿ���� Ȯ��
	if (_iter.m_pList != this || !_iter.m_bValid || _iter.m_pNode == nullptr)
	{
		assert(false); // Invalid iterator
		return end();
	}


	//������ ��� ��������
	tFNode<T>* pDeleteNode = _iter.m_pNode;


	
	//���� ���� ������� ����
	tFNode<T>* pPrevNode = _iter.m_pNode->pPrevNode;
	tFNode<T>* pNextNode = _iter.m_pNode->pNextNode;

	//������ ��尡 ù��°�ΰ��
	if (m_pHeadNode == pDeleteNode)
	{
		m_pHeadNode = pNextNode;
	}
	else
	{
		pPrevNode->pNextNode = pNextNode;
	}

	//������ ��尡 ������
	if (pDeleteNode == m_pTailNode)
	{
		m_pTailNode = pPrevNode;
	}
	else
	{
		pNextNode->pPrevNode = pPrevNode;
	}

	//��� ����
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
		//iterator�� ����Ű�� �ִ� ����� �������ΰ���
		//���� ��� �ּ� ��Ʈ�� ���� ������ ���� ����
		_iter.m_pNode->pPrevNode->pNextNode = pNewNode;
		pNewNode->pPrevNode = _iter.m_pNode->pPrevNode;

		//iterator�� ����Ű�� �ִ� ����� ������ ���ο� ���� ����
		//���ο� ����� next�� iterator�� ����Ű�� �մ� ���� ����
		_iter.m_pNode->pPrevNode = pNewNode;
		pNewNode->pNextNode = _iter.m_pNode;
	}


	++m_iCount;

	return iterator(this,pNewNode);
}

