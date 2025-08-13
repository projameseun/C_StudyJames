#pragma once
template<typename T>
class ArrayList
{
private:
	T* pData;
	int iSize;
	int	iMaxSize;

public:
	ArrayList()
	{
		pData = new T[2];
		iSize = 0;
		iMaxSize = 2;
	}
	ArrayList(ArrayList& _arr)
	{
		_arr.pData = new T[2];
		//_arr.pData = (int*)malloc(sizeof(int) * 2);
		_arr.iSize = 0;
		_arr.iMaxSize = 2;
	}

public:
	void push_back(T _data);
	void resize(int _size);
	void clear();
	bool empty()const;
	int size() const;
	size_t capacity();

public:
	T& operator[](int _idx)
	{
		return pData[_idx];
	}

	const T& operator[](int idx) const
	{
		return pData[idx];
	}
};

template<typename T>
inline void ArrayList<T>::push_back(T _data)
{

	//int* Mydata = malloc(_T.iMaxSize * 2 * sizeof(int));


	if (iMaxSize <= iSize)
	{
		//재할당
		resize(2);

	}

	//data 추가
	pData[iSize++] = _data;


}

template<typename T>
inline void ArrayList<T>::resize(int _size)
{
	T* Mydata = new T[iMaxSize * _size];

	//기존 공간에 데이터를 새로 할당한 공간으로 복사
	for (size_t i = 0; i < iSize; ++i)
	{
		Mydata[i] = pData[i];
	}

	delete[] pData;

	pData = Mydata;

	iMaxSize *= 2;

}

template<typename T>
inline void ArrayList<T>::clear()
{
	if (this != nullptr)
	{
		delete[] pData;
		iSize = 0;
		iMaxSize = 0;
	}
}


template<typename T>
inline bool ArrayList<T>::empty() const
{
	return iSize == 0;
}

template<typename T>
inline int ArrayList<T>::size() const
{
	return iSize;
}

template<typename T>
inline size_t ArrayList<T>::capacity()
{
	return iMaxSize;
}