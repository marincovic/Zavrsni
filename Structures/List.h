#pragma once

#include <memory>
#include <stdexcept>

#include "Node.h"

template<typename T>
class List
{
protected:
	Node<T>* m_pHead{ nullptr };

public:
	List() {}

	virtual ~List()
	{
		Node<T>* pNext = m_pHead;
		while (pNext)
		{
			Node<T>* pCurrent = pNext;
			pNext = pNext->GetNext();
			delete pCurrent;
		}
	}

	virtual void Append(const T& value)
	{
		Node<T>* pNewNode = new Node<T>(value);
		if (!m_pHead)
		{
			m_pHead = pNewNode;
			return;
		}
		Node<T>* pNode = m_pHead;
		while (pNode->GetNext())
			pNode = pNode->GetNext();
		pNode->SetNext(pNewNode);
	}

	virtual void InsertAt(int index, const T& value)
	{
		if (index == 0)
			m_pHead = new Node<T>{ value, m_pHead };
		else
		{
			Node<T>* pPrev = GetNextPtrAt(index - 1);
			Node<T>* pNext = pPrev->GetNext();
			pPrev->SetNext(new Node<T>{ value, pNext });
		}
	}

	const T& GetAt(int index)
	{
		Node<T>* pNode = GetNextPtrAt(index);
		return pNode->GetData();
	}

	int Size() const
	{
		int i = 0;
		Node<T>* pNode = m_pHead;
		while (pNode)
		{
			++i;
			pNode = pNode->GetNext();
		}
		return i;
	}

	virtual void RemoveAt(int index)
	{
		if (index == 0)
			m_pHead = DeleteAndReturnNext(GetNextPtrAt(0));
		else
		{
			Node<T>* pPrevious = GetNextPtrAt(index - 1);
			pPrevious->SetNext(DeleteAndReturnNext(pPrevious->GetNext()));
		}
	}

private:
	Node<T>* GetNextPtrAt(int index) const
	{
		if (!m_pHead)
			throw std::out_of_range("list is empty");
		Node<T>* pNext = m_pHead;
		while (--index >= 0)
		{
			if (!pNext)
				throw std::out_of_range("invalid index");
			pNext = pNext->GetNext();
		}
		if (!pNext)
			throw std::out_of_range("invalid index");
		return pNext;
	}

	Node<T>* DeleteAndReturnNext(Node<T>* pToRemove)
	{
		Node<T>* pNext = pToRemove->GetNext();
		delete pToRemove;
		return pNext;
	}
};