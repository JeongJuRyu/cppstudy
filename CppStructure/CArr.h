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
	int size();
	T& operator[](int idx);
	void clear();
	
	class iterator;
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
public:
	CArr();
	~CArr();
	// inner 클래스를 포함하고 있는 클래스의 private 멤버에 접근 가능
	class iterator
	{
	private:
		CArr*	m_pArr; // iterator가 가리킬 데이터를 관리하는 가변배열 주소
		T*		m_pData; // 데이터들의 시작 주소
		int		m_iIdx;// 가리키는 데이터의 인덱스
		bool	m_bValid;
	public:
		int getIndex()
		{
			return this->m_iIdx;
		}
		T& operator * ()
		{
			// iterator가 알고있는 주소와, 가변배열이 알고있는 주소가 달라진 경우(벡터의 공간 확장으로 주소가 달라진 경우)
			// iterator가 end iterator인 경우
			if(m_pArr->m_pData != m_pData || -1 == m_iIdx || !m_bValid)
				assert(nullptr);
		
			return m_pData[m_iIdx];
		}
		// ++ 전위
		iterator& operator ++()
		{
			// 1. (이전에도 했지만) 가변배열의 주소와 iterator가 가리키는 주소가 다른 경우
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
			{
				assert(nullptr);
			}

			// 2. end itarator인 경우(더이상 증가 x)
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

		// ++ 후위
		// 의미없는 인자 int를 쓰는 경우 후위연산자 사용 시 이 함수가 호출된다.
		// 이처럼 복사 작업이 이루어지는 이유 때문에, 최대한 전위연산자를 사용하는 것이 성능상 좋다.
		iterator operator ++(int)
		{
			iterator copy_iter = *this;
			
			++(*this);
			return copy_iter;
		}

		iterator& operator --()
		{
			return *this;
		}
		
		// 비교연산자 ==, !=
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
			return !(*this == _otheriter);
		}
	public:
		iterator()
			:m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
			, m_bValid(false)
		{
		}
		iterator(CArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
			, m_bValid(true)
		{
			if (nullptr != _pArr && _iIdx)
			{
				m_bValid = true;
			}
		}
		~iterator()
		{
		}
		friend class CArr;
	};
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
int CArr<T>::size()
{
	return this->m_iCount;
}
template<typename T>
T& CArr<T>::operator[](int idx)
{
	return m_pData[idx];
}

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	if (0 == m_iCount)
		return iterator(this, m_pData, -1);
	return iterator(this, m_pData, 0);
}
template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	return iterator(this, m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{
	// this가 아닌 다른 가변배열의 iterator가 인자로 들어온 경우나
	// end iterator가 들어오는 경우, 예외처리
	if (_iter.m_pArr != this || _iter == end() || m_iCount <= _iter.m_iIdx)
	{
		assert(nullptr);
	}
	for (int i = _iter.m_iIdx; i < m_iCount - 1; ++i) {
		m_pData[i] = m_pData[i + 1];
	}

	_iter.m_bValid = false;

	// 카운트 감소
	--m_iCount;

	
	return iterator(this, m_pData, _iter.m_iIdx);
}


