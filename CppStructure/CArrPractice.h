#pragma once

template <typename T>
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

	class iterator;
	iterator begin();
	iterator end();

public:
	CArr();
	~CArr();

	class iterator
	{
	private:
		CArr*	m_pArr;
		T*		m_pData;
		int		m_iIdx;

	public:
		T& operator * ()
		{
			if (m_pArr->m_pData != m_pData || -1)
				assert(nullptr);
			return m_pData[m_iIdx];
		}

		iterator& operator ++()
		{
			return *this;
		}

		iterator& operator --()
		{
			return *this;
		}
	public:
		iterator()
			:m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
		{

		}
		iterator(CArr* _pArr, T* _pData, int _iIdx)
			:m_pArr(_pArr)
			,m_pData(_pDAta)
			,m_iIdx(_iIdx)
		{}
		~iterator()
		{

		}
	};
};

template<typename T>
CArr<T>::CArr()
	:m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(0)
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
	if (m_imaxCount <= m_iCount) {
		resize(m_iMaxCount * 2);
	}
	this->m_pData[m_iCount++] = _Data;
}