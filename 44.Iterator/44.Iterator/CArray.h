#pragma once
#include <assert.h>
#include <iostream>

template<class T>
class CArray
{
private:
	T*		m_pData;
	int		m_iCount;
	int		m_iMaxCount;

public:
	CArray();
	~CArray();


public:

	int size()
	{
		return m_iCount;
	}

	int capacity()
	{
		return m_iMaxCount;
	}

	T* data()
	{
		return m_pData;
	}


public:
	//������ �������� T�� ���� Ÿ���̵� �ٵ� 
	void push_back(const T& _Data);
	void resize(int _Size);
	void Delete(int _Num);


	T& operator[] (int _idx);
	//int operator[] (int _idx);

	class iterator; //���漱��
	iterator begin();
	iterator end();
	//const _Iterator_base12& _Right
	iterator erase( iterator& _rIter );


	void clear()
	{
		m_iCount = 0;
	}
public:
	//�̳�Ŭ����
	//�ݺ���
	//�̳�Ŭ������ �����ϰ� �ִ� Ŭ������ pirivate��� ���ٰ���
	class iterator
	{
	private:
		//���Ͱ� �߰������� ���簡 �Ͼ�� �����Ҵ�ɶ��ٵ� �̶� ������ ����� �ִ� 
		//iterator�� �ᱹ ���Ͱ�ü�ڽ��� �˰� ������ȴ� �׷��� ���� �Ҵ�ǰ� �Ȱ��� ���ּҸ� �������ָ� �Ǵϱ� 
		//���������� ������ �����ڱ��ڽ��� ũ�Ⱑ ����Ǿ� ù��° �ּҸ� ����Ű�� , iter�� ����Ű�� ù��°�ּҸ� ����Ű�°� ���� �ٸ��°� ������� ����Ŷ�� �ΰ� �� �־�� �ȴ�.
		//���� ���ʹ� �̰� ������ �����ִ�.
			CArray*		m_pArr;	//iterator�� ����ų �����͸� �����ϴ� �����迭�ּ�
			T*		m_pData;	//������ �����ּ�
			int		m_iIdx;		//����Ű�� �ε���
			bool	m_bValid;		//��ȿ
	public:
		iterator() :
			m_pArr(nullptr),
			m_pData(nullptr),
			m_iIdx(-1),
			m_bValid(false)
		{

		}

		iterator(CArray* _pArr ,T* _data, int _idx) :
			m_pArr(_pArr),
			m_pData(_data),
			m_iIdx(_idx),
			m_bValid(false)
		{
			if (_pArr != nullptr && _idx >= 0)
			{
				m_bValid = true;
			}
			
		}
		~iterator()
		{

		}

		friend class CArray;	
		//�̳�Ŭ������ private�� �����Ҽ� �ִµ� CArray�� iterator�� ���ٸ��Ѵ� �̷��� ������ Ŭ������ ����ؼ� �����Ҽ� �ִ�
		//�ʳ���ģ�� 
	public:
		T& operator * ()
		{
			//�� iterator�� �˰� �ִ� �ּҿ�, �����迭�� �˰� �ִ� �ּҰ� �޶������(������ Ȯ���ϰ� �ּҰ� �޶��� ���)
			//iterator end iterator�� ���
			if (m_pArr->m_pData != m_pData || m_iIdx == -1 || m_bValid == false)
			{
				std::cout << "can't dereference value-initialized vector iterator" << std::endl;
				assert(nullptr);
			}

			return m_pData[m_iIdx];
		}

		iterator& operator++()
		{
			
			//2. end iterator �ΰ�� 
			//3.itator�� �˰� �ִ� �ּҿ� �����迭�� �ּҰ� �ٸ����
			if (m_pArr->m_pData != m_pData || m_iIdx == -1)
			{
				std::cout << "can't dereference value-initialized vector iterator" << std::endl;
				assert(nullptr);
			}

			//1.iterator�� ������ �����͸� ����Ű�� ��� 
		//end ierator�� �Ǵ°��
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;

			}

		

			return *this;
		}


		//�����Ϸ��� �������� ��������� �˱����ؼ� int�� �� �־���ߵȴ�.
		//����++ ���۷������ƴ� ���縦 �ش� 
		iterator operator++(int)
		{
			//���� �����ڰ� ȣ��ȰŴ� 
			//�ڵ����θ���� ���Ŵ� 
			iterator copy_iter = *this;

			++(*this);

			return copy_iter;
		}

		iterator& operator --()
		{
			
			
			//2. end iterator �ΰ�� 
			//3.itator�� �˰� �ִ� �ּҿ� �����迭�� �ּҰ� �ٸ����
			if (m_pData != m_pArr->m_pData || m_iIdx == -1 || m_iIdx == 0)
			{
				std::cout << "can't dereference value-initialized vector iterator" << std::endl;
				assert(nullptr);
			}
		
			--m_iIdx;

			//1.iterator�� ������ �����͸� ����Ű�� ��� 
			//end ierator�� �Ǵ°��
			

			return *this;
		}

		//�����Ϸ��� �������� ��������� �˱����ؼ� int�� �� �־���ߵȴ�.
		iterator operator--(int)
		{
			//���� �����ڰ� ȣ��ȰŴ� 
			//�ڵ����θ���� ���Ŵ� 
			iterator copy_iter = *this;

			--(*this);

			return copy_iter;
		}


		//�񱳿�����
		bool operator == (const iterator& _otheriter)
		{
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return true;
			}
			return false;
		}

		bool operator != (const iterator& _otheriter)
		{
			if (m_pData == _otheriter.m_pData && m_iIdx == _otheriter.m_iIdx)
			{
				return false;
			}
			return true;

			//���ϼ�����
			//return !(*this == _otheriter);
		}
	};

};


template<class T>
CArray<T>::CArray()
	:m_pData(nullptr),
	m_iCount(0),
	m_iMaxCount(2)
{
	m_pData = new T[2];

}

template<class T>
CArray<T>::~CArray()
{
	if (m_pData != nullptr)
	{
		delete[] m_pData;

	}
}


template<class T>
void CArray<T>::push_back(const T& _Data)
{
	if (m_iMaxCount <= m_iCount)
	{
		//���Ҵ�
		resize(m_iMaxCount * 2);
	}

	//this�� �����Ҽ��� �ְ� ���Ҽ����ִ�.
	//������ �߰�
	m_pData[m_iCount++] = _Data;

}

template<class T>
void CArray<T>::resize(int _Size)
{
	//����
	if (m_iMaxCount >= _Size)
	{
		//assert(nullptr);
		//std::cout << "�Ҵ��� ũ�Ⱑ MaxCount���� �۽��ϴ�" << std::endl;
		throw std::runtime_error("New size must be greater than current max count");
	}

	T* pTemp = new T[_Size];

	//�����͵��� ���� �Ҵ��Ѱ������� �����Ѵ�
	for (int i = 0; i < m_iCount; ++i)
	{
		pTemp[i] = m_pData[i];
	}

	delete[]  m_pData;


	m_pData = pTemp;

	m_iMaxCount = _Size;
	std::cout << "Max : " << m_iMaxCount << std::endl;
}

template<class T>
void CArray<T>::Delete(int _Num)
{
	//�̹���� ���� �ʴ� �׷��Ƿ� �����͸� ������ �ű�� ������θ� 
	if (_Num < 0 || _Num >= m_iCount)
	{
		throw std::out_of_range("Index out of range");
	}

	for (int i = _Num; i < size() - 1; ++i)
	{
		m_pData[i] = m_pData[i + 1];
	}

	//T* pTemp = new T[m_iCount - 1];

	//int k = 0;

	////�����͵��� ���� �Ҵ��Ѱ������� �����Ѵ�
	//for (int i = 0; i < m_iCount; ++i)
	//{
	//	if (i == _Num)continue;
	//	pTemp[k++] = m_pData[i];



	//}



	//if (m_pData != nullptr)
	//{
	//	delete[] m_pData;


	//}

	//m_pData = pTemp;
	m_iCount--;

	//m_iMaxCount = m_iCount;

	int a = 0;




}

//int CArray::operator[](int _idx)
//{
//	return this->m_pInt[_idx];
//}

template<class T>
T& CArray<T>::operator[](int _idx)
{
	if (_idx < 0 || _idx >= m_iCount)
	{
		throw std::out_of_range("Index out of range");
	}

	return this->m_pData[_idx];
}

//�̳�Ŭ��������Ҷ�
template<class T>
typename CArray<T>::iterator CArray<T>::begin()
{
	//������ ����Ű�� iterator�� ���� ��ȯ����
	//iterator iter(m_pData, 0);
	/*iter.m_pData = this->m_pData;
	iter.m_iIdx = 0;*/


	if (m_iCount == 0)
	{
		return iterator(this, m_pData, -1);	//�����Ͱ� ���°�� begin() == end()
	}

	//�ӽð�ü
	return iterator(this,m_pData, 0);
}


template<class T>
typename CArray<T>::iterator CArray<T>::end()
{
	
	//���� ������ ����Ű�� iteator�� ���� ��ȯ
	return iterator(this, m_pData, -1);


}

template<class T>
typename CArray<T>::iterator CArray<T>::erase(iterator& _rIter)
{
	//�ٸ����� iter�� ����Ų�ٸ� 
	if (_rIter.m_pArr != this || end() == _rIter || m_iCount  <= _rIter.m_iIdx)
	{
		assert(nullptr);
	}

	//iterator�� ����Ű�� �����͸� �迭 ������ �����Ѵ�.

	int iLoop = m_iCount - (_rIter.miIdx + 1);
		//ī��Ʈ -1 

	for (int i = 0; i < iLoop; ++i)
	{
		m_pData[i + _rIter.m_iIdx] = m_pData[i + _rIter.miIdx + 1];
	}

	//����ȸ��
	_rIter.m_bValid = false;
	
	--m_iCount;
	
	//�ǵ����ٶ� true
	return iterator(this, m_pData,_rIter.m_iIdx);
}


//�̳�Ŭ��������Ҷ�