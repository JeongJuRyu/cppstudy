#pragma once

#include <assert.h>

template<typename T>
class CArr
{
private:
	T*		m_pData;
	int		m_iCount;
	int		m_iMaxCount;

public:
	void push_back(const T& _Data);
	void resize(int _iResizeCount);

	T& operator[](int idx);
	
public:
	CArr();
	~CArr();
};

template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2];

}
template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData;
}

template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	if (m_iMaxCount <= m_iCount)
	{
		resize(m_iMaxCount * 2);
	}
	this->m_pData[m_iCount++] = _Data;
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	T* pNew = new T[_iResizeCount];
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}
	delete[] m_pData;
	m_pData = pNew;
	m_iMaxCount = _iResizeCount;
}
template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}


