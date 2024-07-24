#pragma once
class CArray
{
private:
	int*	m_pInt;
	int		m_iCount;
	int		m_iMaxCount;

public:
	CArray();
	~CArray();

public:
	int GetCount()
	{
		return m_iCount;
	}

	int GetMaxCount()
	{
		return m_iMaxCount;
	}

	int* GetpInt()
	{
		return m_pInt;
	}

public:
	void push_back(int _Data);
	void resize(int _Size);
	void Delete(int _Num);

	//int operator[] (int _idx);
	int& operator[] (int _idx);
};

