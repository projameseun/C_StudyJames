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
	//앞으로 내가만들 T는 무슨 타입이든 다되 
	void push_back(const T& _Data);
	void resize(int _Size);
	void Delete(int _Num);


	T& operator[] (int _idx);
	//int operator[] (int _idx);

	class iterator; //전방선언
	iterator begin();
	iterator end();
	//const _Iterator_base12& _Right
	iterator erase( iterator& _rIter );


	void clear()
	{
		m_iCount = 0;
	}
public:
	//이너클래스
	//반복자
	//이너클래스는 포함하고 있는 클래스의 pirivate멤버 접근가능
	class iterator
	{
	private:
		//백터가 추가됬을때 복사가 일어나서 새로할당될때텐데 이때 문제가 생길수 있다 
		//iterator는 결국 백터객체자신을 알고 잇으면된다 그러면 새로 할당되고 똑같이 그주소를 가리켜주면 되니까 
		//설계적으로 봤을때 백터자기자신이 크기가 변경되어 첫번째 주소를 가리키고 , iter가 가리키는 첫번째주소를 가리키는게 서로 다르는게 문제라고 만들거라면 두개 다 있어야 된다.
		//실제 백터는 이걸 문제로 보고있다.
			CArray*		m_pArr;	//iterator가 가리킬 데이터를 관리하는 가변배열주소
			T*		m_pData;	//데이터 시작주소
			int		m_iIdx;		//가리키는 인덱스
			bool	m_bValid;		//유효
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
		//이너클래스는 private를 접근할수 있는데 CArray는 iterator를 접근못한다 이럴때 프렌드 클래스를 사용해서 접근할수 있다
		//너나랑친구 
	public:
		T& operator * ()
		{
			//비교 iterator가 알고 있는 주소와, 가변배열이 알고 있는 주소가 달라진경우(공간을 확장하고 주소가 달라질 경우)
			//iterator end iterator일 경우
			if (m_pArr->m_pData != m_pData || m_iIdx == -1 || m_bValid == false)
			{
				std::cout << "can't dereference value-initialized vector iterator" << std::endl;
				assert(nullptr);
			}

			return m_pData[m_iIdx];
		}

		iterator& operator++()
		{
			
			//2. end iterator 인경우 
			//3.itator가 알고 있는 주소와 가변배열의 주소가 다를경우
			if (m_pArr->m_pData != m_pData || m_iIdx == -1)
			{
				std::cout << "can't dereference value-initialized vector iterator" << std::endl;
				assert(nullptr);
			}

			//1.iterator가 마지막 데이터를 가리키는 경우 
		//end ierator가 되는경우
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


		//컴파일러가 후위인지 명시적으로 알기위해서 int를 꼭 넣어줘야된다.
		//후위++ 레퍼런스가아닌 복사를 준다 
		iterator operator++(int)
		{
			//복사 생성자가 호출된거다 
			//자동으로만들어 진거다 
			iterator copy_iter = *this;

			++(*this);

			return copy_iter;
		}

		iterator& operator --()
		{
			
			
			//2. end iterator 인경우 
			//3.itator가 알고 있는 주소와 가변배열의 주소가 다를경우
			if (m_pData != m_pArr->m_pData || m_iIdx == -1 || m_iIdx == 0)
			{
				std::cout << "can't dereference value-initialized vector iterator" << std::endl;
				assert(nullptr);
			}
		
			--m_iIdx;

			//1.iterator가 마지막 데이터를 가리키는 경우 
			//end ierator가 되는경우
			

			return *this;
		}

		//컴파일러가 후위인지 명시적으로 알기위해서 int를 꼭 넣어줘야된다.
		iterator operator--(int)
		{
			//복사 생성자가 호출된거다 
			//자동으로만들어 진거다 
			iterator copy_iter = *this;

			--(*this);

			return copy_iter;
		}


		//비교연산자
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

			//줄일수잇음
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
	//이방식은 좋지 않다 그러므로 데이터를 옆으로 옮기는 방식으로만 
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

	////데이터들을 새로 할당한공간으로 복사한다
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

//이너클래스사용할때
template<class T>
typename CArray<T>::iterator CArray<T>::begin()
{
	//시작을 가리키는 iterator를 만들어서 반환해줌
	//iterator iter(m_pData, 0);
	/*iter.m_pData = this->m_pData;
	iter.m_iIdx = 0;*/


	if (m_iCount == 0)
	{
		return iterator(this, m_pData, -1);	//데이터가 없는경우 begin() == end()
	}

	//임시객체
	return iterator(this,m_pData, 0);
}


template<class T>
typename CArray<T>::iterator CArray<T>::end()
{
	
	//끝의 다음을 가리키는 iteator를 만들어서 반환
	return iterator(this, m_pData, -1);


}

template<class T>
typename CArray<T>::iterator CArray<T>::erase(iterator& _rIter)
{
	//다른곳을 iter가 가르킨다면 
	if (_rIter.m_pArr != this || end() == _rIter || m_iCount  <= _rIter.m_iIdx)
	{
		assert(nullptr);
	}

	//iterator가 가리키는 데이터를 배열 내에서 제거한다.

	int iLoop = m_iCount - (_rIter.miIdx + 1);
		//카운트 -1 

	for (int i = 0; i < iLoop; ++i)
	{
		m_pData[i + _rIter.m_iIdx] = m_pData[i + _rIter.miIdx + 1];
	}

	//원본회손
	_rIter.m_bValid = false;
	
	--m_iCount;
	
	//되돌려줄때 true
	return iterator(this, m_pData,_rIter.m_iIdx);
}


//이너클래스사용할때