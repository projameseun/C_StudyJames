#pragma once
#include <assert.h>
#include <iostream>

template<class T>
class CArray
{
private:
	T* m_pData;
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
	//앞으로 내가만들 T는 무슨 타입이든 다되 
	void push_back(const T& _Data);
	void resize(int _Size);
	void Delete(int _Num);
	

	T& operator[] (int _idx);
	//int operator[] (int _idx);

	class iterator; //전방선언
	iterator begin();

public:
	//이너클래스
	//반복자
	class iterator
	{
	private:
		T*		m_pData;
		int		m_iIdx;
	public:
		iterator() :
			m_pData	(nullptr),
			m_iIdx(-1)
		{
			
		}

		iterator(T _data, int _idx) :
			m_pData(_data),
			m_iIdx(-_idx)
		{

		}
		~iterator()
		{
		
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
		//재할당
		resize(m_iMaxCount * 2);
	}

	//this를 생략할수도 있고 안할수도있다.
	//데이터 추가
	m_pData[m_iCount++] = _Data;

}

template<class T>
void CArray<T>::resize(int _Size)
{
	//예외
	if (m_iMaxCount >= _Size)
	{
		//assert(nullptr);
		//std::cout << "할당할 크기가 MaxCount보다 작습니다" << std::endl;
		throw std::runtime_error("New size must be greater than current max count");
	}

	T* pTemp = new T[_Size];

	//데이터들을 새로 할당한공간으로 복사한다
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

	if (_Num < 0 || _Num >= m_iCount)
	{
		throw std::out_of_range("Index out of range");
	}

	T* pTemp = new T[m_iCount - 1];

	int k = 0;

	//데이터들을 새로 할당한공간으로 복사한다
	for (int i = 0; i < m_iCount; ++i)
	{
		if (i == _Num)continue;
		pTemp[k++] = m_pData[i];



	}



	if (m_pData != nullptr)
	{
		delete[] m_pData;


	}

	m_pData = pTemp;
	m_iCount--;

	m_iMaxCount = m_iCount;

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

//이너클래스사용할때
template<class T>
typename CArray<T>::iterator CArray<T>::begin()
{
	//시작을 가리키는 iterator를 만들어서 반환해줌
	//iterator iter(m_pData, 0);
	/*iter.m_pData = this->m_pData;
	iter.m_iIdx = 0;*/
	
	//임시객체
	return iterator(m_pData,0);
}


