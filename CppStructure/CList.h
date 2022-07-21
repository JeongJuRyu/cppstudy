#pragma once
// c++에서는 구조체도 클래스랑 거의 유사하다.

template <typename T>
struct tListNode
{
	T			data;
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
	void push_back(const T& data);
	void push_front(const T& _data);
public:
	CList();
	~CList();
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
