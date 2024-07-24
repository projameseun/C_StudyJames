#include "CArray.h"
#include <iostream>
#include <assert.h>

CArray::CArray()
	:m_pInt(nullptr),
	m_iCount(0),
	m_iMaxCount(2)
{
	m_pInt = new int[2];

}

CArray::~CArray()
{
	if (m_pInt != nullptr)
	{
		delete[] m_pInt;
		
	}
}

void CArray::push_back(int _Data)
{
	if (m_iMaxCount <= m_iCount)
	{
		//���Ҵ�
		resize(m_iMaxCount * 2);
	}
	
	//this�� �����Ҽ��� �ְ� ���Ҽ����ִ�.
	//������ �߰�
	m_pInt[m_iCount++] = _Data;

}

void CArray::resize(int _Size)
{
	//����
	if (m_iMaxCount >= _Size)
	{
		//assert(nullptr);
		//std::cout << "�Ҵ��� ũ�Ⱑ MaxCount���� �۽��ϴ�" << std::endl;
		throw std::runtime_error("New size must be greater than current max count");
	}

	int* pTemp = new int[_Size];

	//�����͵��� ���� �Ҵ��Ѱ������� �����Ѵ�
	for (int i = 0; i < m_iCount; ++i)
	{
		pTemp[i] = m_pInt[i];
	}

	delete[]  m_pInt;
	

	m_pInt = pTemp;

	m_iMaxCount = _Size;
	std::cout << "Max : " << m_iMaxCount << std::endl;
}

void CArray::Delete(int _Num)
{

	if (_Num < 0 || _Num >= m_iCount)
	{
		throw std::out_of_range("Index out of range");
	}

	int* pTemp = new int[m_iCount-1];

	int k = 0;

	//�����͵��� ���� �Ҵ��Ѱ������� �����Ѵ�
	for (int i = 0; i < m_iCount; ++i)
	{
		if (i == _Num)continue;
		pTemp[k++] = m_pInt[i];

		

	}



	if (m_pInt != nullptr)
	{
		delete[] m_pInt;

		
	}
	
	m_pInt = pTemp;
	m_iCount--;

	m_iMaxCount = m_iCount;
	
	int a = 0;
	

	

}

//int CArray::operator[](int _idx)
//{
//	return this->m_pInt[_idx];
//}


int& CArray::operator[](int _idx)
{
	if (_idx < 0 || _idx >= m_iCount)
	{
		throw std::out_of_range("Index out of range");
	}

	return this->m_pInt[_idx];
}
