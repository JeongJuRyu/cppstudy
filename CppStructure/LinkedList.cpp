#include "LinkedList.h"

#include <iostream>

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
	
}

void PushBack(tLinkedList* _pList, int _iData)
{
	tNode* tempNode = _pList->pHeadNode;
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	if (_pList->iCount == 0) _pList->pHeadNode = pNode;
	else 
	{
		while (tempNode->pNextNode != nullptr) tempNode = tempNode->pNextNode;
		tempNode->pNextNode = pNode;
	}
	_pList->iCount++;
}

void PushFront(tLinkedList* _pList, int _iData)
{
	tNode* tempNode = (tNode*)malloc(sizeof(tNode));
	tempNode->iData = _iData;
	tempNode->pNextNode = nullptr;
	if (_pList->iCount == 0) _pList->pHeadNode = tempNode;
	else {
		tempNode->pNextNode = _pList->pHeadNode->pNextNode;
		_pList->pHeadNode = tempNode;
	}
	_pList->iCount++;
}

void ReleaseList(tLinkedList* _pList)
{
	tNode* pDeleteNode = _pList->pHeadNode;
	while (pDeleteNode != nullptr) {
		tNode* pNext = pDeleteNode->pNextNode;
		free(pDeleteNode);
		pDeleteNode = pNext;
	}
}
