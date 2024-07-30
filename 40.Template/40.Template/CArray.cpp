#include "CArray.h"
#include <iostream>
#include <assert.h>

//CArray::CArray()
//	:m_pData(nullptr),
//	m_iCount(0),
//	m_iMaxCount(2)
//{
//	m_pData = new int[2];
//
//}
//
//CArray::~CArray()
//{
//	if (m_pData != nullptr)
//	{
//		delete[] m_pData;
//
//	}
//}
//
//void CArray::push_back(const T& _Data)
//{
//	if (m_iMaxCount <= m_iCount)
//	{
//		//재할당
//		resize(m_iMaxCount * 2);
//	}
//
//	//this를 생략할수도 있고 안할수도있다.
//	//데이터 추가
//	m_pData[m_iCount++] = _Data;
//
//}
//
//void CArray::resize(int _Size)
//{
//	//예외
//	if (m_iMaxCount >= _Size)
//	{
//		//assert(nullptr);
//		//std::cout << "할당할 크기가 MaxCount보다 작습니다" << std::endl;
//		throw std::runtime_error("New size must be greater than current max count");
//	}
//
//	int* pTemp = new int[_Size];
//
//	//데이터들을 새로 할당한공간으로 복사한다
//	for (int i = 0; i < m_iCount; ++i)
//	{
//		pTemp[i] = m_pData[i];
//	}
//
//	delete[]  m_pData;
//
//
//	m_pData = pTemp;
//
//	m_iMaxCount = _Size;
//	std::cout << "Max : " << m_iMaxCount << std::endl;
//}
//
//void CArray::Delete(int _Num)
//{
//
//	if (_Num < 0 || _Num >= m_iCount)
//	{
//		throw std::out_of_range("Index out of range");
//	}
//
//	int* pTemp = new int[m_iCount - 1];
//
//	int k = 0;
//
//	//데이터들을 새로 할당한공간으로 복사한다
//	for (int i = 0; i < m_iCount; ++i)
//	{
//		if (i == _Num)continue;
//		pTemp[k++] = m_pData[i];
//
//
//
//	}
//
//
//
//	if (m_pData != nullptr)
//	{
//		delete[] m_pData;
//
//
//	}
//
//	m_pData = pTemp;
//	m_iCount--;
//
//	m_iMaxCount = m_iCount;
//
//	int a = 0;
//
//
//
//
//}
//
////int CArray::operator[](int _idx)
////{
////	return this->m_pInt[_idx];
////}
//
//
//T& CArray::operator[](int _idx)
//{
//	if (_idx < 0 || _idx >= m_iCount)
//	{
//		throw std::out_of_range("Index out of range");
//	}
//
//	return this->m_pData[_idx];
//}
