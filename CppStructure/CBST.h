#pragma once

#include <assert.h>
enum class NODE_TYPE
{
	PARENT, //0
	LCHILD, //1
	RCHILD, //2
	END,	//마감
};
template<typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};

template<typename T1, typename T2>
tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
	return tPair<T1, T2>{ _first, _second };
}
template<typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2> pair;
	
	tBSTNode* arrNode[(int)NODE_TYPE::END];
	
	bool IsRoot()
	{
		return (nullptr == arrNode[(int)NODE_TYPE::PARENT]);
	}
	bool IsLeftChild()
	{
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
			return true;
		return false;
	}
	bool IsLeftChild()
	{
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
			return true;
		return false;
	}
	tBSTNode()
	{}
	tBSTNode(const tPair<T1, T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLChild, tBSTNode* _pRChild)
		:pair(_pair)
		,arrNode{ _pParent, _pLChild, _pRChild}
	{}
};

template <typename T1, typename T2>
class CBST
{
private:
	tBSTNode<T1, T2>*	m_pRoot;
	int			m_iCount;

public:
	bool insert(const tPair<T1, T2>& _pair);
	tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2> _pNode);
	tBSTNode<T1, T2>* GetInOrderPredecessor(tBSTNode<T1, T2> _pNode);
	class iterator;
public:
	iterator begin();
	iterator end();
	iterator find(const T1& _find);
public:
	CBST()
		:m_pRoot(nullptr)
		,m_iCount(0)
	{}

	//iterator
	class iterator
	{
	private:
		CBST<T1, T2>* m_pBST;
		tBSTNode<T1, T2>* m_pNode; // null인 경우 end iterator

	public:
		bool operator ==(const iterator& _other)
		{
			if (m_pBST == _other.m_pBST && m_pNode == _other.m_pNode)
				return true;
			return false;
		}

		bool operator !=(const iterator& _other)
		{
			return !(*this == _other);
		}

		const tPair<T1, T2>& operator *()
		{
			// m_pNode nullptr 체크(end iterator인지 아닌지)
			assert(m_pNode);
			return m_pNode->pair;
		}
		
		const tPair<T1, T2>* operator ->()
		{
			assert(m_pNode);
			return &m_pNode->pair;
		}
		iterator& operator ++()
		{
			m_pNode = m_pBst->
		}
	public:
		iterator()
			:m_pBST(nullptr)
			, m_pNode(nullptr)
		{}

		iterator(CBST<T1, T2>* _pBST, tBSTNode<T1, T2>* _pNode)
			:m_pBST(_pBST)
			, m_pNode(_pNode)
		{}
	};
};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);

	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot;
		NODE_TYPE node_type = NODE_TYPE::END;

		while (true) {
			if (pNode->pair.first < pNewNode->pair.first)
				node_type = NODE_TYPE::RCHILD;
			else if (pNode->pair.first > pNewNode->pair.first)
				node_type = NODE_TYPE::LCHILD;
			else
				return false;
			if (nullptr == pNode->arrNode[(int)node_type])
			{
				pNode->arrNode[(int)node_type] = pNewNode;
				pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
				break;
			}
			else
			{
				pNode = pNode->arrNode[(int)node_type];
			}

		}
	}
	return true;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2> _pNode)
{
	tBSTNode<T1, T2>* pSuccessor = nullptr;
	// 1. 오른쪽 자식이 있는 경우, 오른쪽 자식으로 가서 왼쪽 자식이 없을 때 까지 내려감
	if (_pNode->arrNode[(int)NODE_TYPE::RCHILD] != nullptr)
	{
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];
		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccessor = _pNode->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}
	// 2. 부모로부터 왼쪽 자식인 경우 까지 위로 올라감
	
	else
	{
		pSuccessor = _pNode;
		while (true)
		{
			if (pSuccessor->IsRoot())
				return nullptr;
			if (pSuccessor->IsLeftChild())
			{
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}
			else
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
		}
	}
	return pSuccessor;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(tBSTNode<T1, T2> _pNode)
{
	return nullptr;
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	tBSTNode<T1, T2>* pNode = m_pRoot;
	while (pNode->arrNode[(int)NODE_TYPE::LCHILD])
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename CBST<T1,T2>::iterator CBST<T1, T2>::find(const T1& _find)
{
	tBSTNode<T1, T2>* pNode = m_pRoot;
	NODE_TYPE node_type = NODE_TYPE::END;

	if (pNode == nullptr) return iterator(this, nullptr);
	while (true) {
		if (pNode->pair.first < _find)
			node_type = NODE_TYPE::RCHILD;
		else if (pNode->pair.first > _find)
			node_type = NODE_TYPE::LCHILD;
		else // 찾고자 하는 노드를 찾았다.
			break;
		if (nullptr == pNode->arrNode[(int)node_type])
			pNode = nullptr;
		else
		{
			pNode = pNode->arrNode[(int)node_type];
		}
	}
	return iterator(this, pNode);
}
