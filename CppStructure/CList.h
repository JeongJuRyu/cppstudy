#pragma once
// c++에서는 구조체도 클래스랑 거의 유사하다.
#include <assert.h>
template <typename T>
struct tListNode
{
	T				data;
	tListNode<T>*	pNext;
	tListNode<T>*	pPrev;

	tListNode()
		: data()
		, pNext(nullptr)
		, pPrev(nullptr)
	{
				
	}
	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{

	}
};

template <typename T>
class CList
{
private:
	tListNode<T>*	m_pHead;
	tListNode<T>*	m_pTail;
	int				m_iCount;

public:
	void push_back(const T& _data);
	void push_front(const T& _data);
	int size() { return m_iCount; }
public:
	class iterator; 
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);
	iterator insert(iterator& _iter, const T& _data);

public:
	CList();
	~CList();

	class iterator
	{
	private:
		CList<T>*		m_pList;
		tListNode<T>*	m_pNode; // null인 경우 end로 
		bool			m_bValid;
	public:
		T& operator* ()
		{
			return m_pNode->data;
		}

		bool operator ==(const iterator& _otheriter)
		{
			if (m_pList == _otheriter.m_pList && m_pNode == _otheriter.m_pNode)
			{
				return true;
			}
			return false;
		}

		bool operator !=(const iterator& _otheriter)
		{
			return !(*this == _otheriter);
		}

		iterator& operator ++()
		{
			if (m_pNode == nullptr || !this->m_bValid)
			{
				assert(nullptr);
			}
			m_pNode = m_pNode->pNext;

			return *this;
		}
		iterator& operator ++(int)
		{
			iterator copyiter(*this);

			++(*this);

			return copyiter;
		}
		iterator& operator --()
		{
			if (m_pNode == nullptr || !this->m_bValid)
			{
				assert(nullptr);
			}
			m_pNode = m_pNode->pPrev;

			return *this;
		}
		iterator& operator --(int)
		{
			iterator copyiter(*this);

			--(*this);

			return copyiter;
		}
		
	public:
		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_bValid(false)
		{

		}

		iterator(CList<T>* _pList, tListNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bValid = true;
			}
		}
		~iterator()
		{}
		
		friend class CList;
	};
};
template<typename T>
void CList<T>::push_back(const T& _data)
{
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);
	//처음 입력된 데이터라면
	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;
		m_pTail = pNewNode;
	}
	++m_iCount;
}

template<typename T>
inline void CList<T>::push_front(const T& _data)
{
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr);
	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode;
		m_pTail = pNewNode;
	}
	else
	{
		m_pHead->pPrev = pNewNode;
		pNewNode->pNext = m_pHead;
		m_pHead = pNewNode;
	}
	++m_iCount;
}

template<typename T>
typename CList<T>::iterator CList<T>::begin()
{
	return iterator(this, m_pHead);
}

template<typename T>
typename CList<T>::iterator CList<T>::end()
{
	return iterator(this, nullptr);
}
template<typename T>
typename CList<T>::iterator CList<T>::insert(CList<T>::iterator& _iter, const T& _data)
{
	if (end() == _iter)
	{
		assert(nullptr);
	}
	tListNode<T>* pNode = new tListNode<T>(_data, nullptr, nullptr);
	
	// iterator가 가리키고 있는 노드의 이전으로 가서
	// 다음 노드 주소 파트를 새로 생성한 노드로 지정

	if (_iter.m_pNode == m_pHead)
	{
		m_pHead->pPrev = pNode;
		pNode->pNext = m_pHead;
		m_pHead = pNode;
	}
	else
	{
		_iter.m_pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.m_pNode->pPrev;

		pNode->pNext = _iter.m_pNode;
		_iter.m_pNode->pPrev = pNode;
	}
	++m_iCount;
	return iterator(this, pNode);
}

template<typename T>
typename CList<T>::iterator CList<T>::erase(CList<T>::iterator& _iter)
{
	return iterator();
}



// template은 생성자 소멸자 정의를 header에 해야 한다.
template<typename T>
CList<T>::CList()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
	, m_iCount(0)
{

}

template<typename T>
CList<T>::~CList()
{
	tListNode<T>* pDeleteNode = m_pHead;
	while (pDeleteNode)
	{
		tListNode<T>* pNextNode = pDeleteNode->pNext;
		delete pDeleteNode;
		pDeleteNode = pNextNode;
	}
}
