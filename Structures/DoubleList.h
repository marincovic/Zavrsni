#pragma once

#include <stdexcept>

#include "DoubleNode.h"

template<typename T>
class DoubleList
{
private:
	DoubleNode<T>* m_pTail{ nullptr };
	DoubleNode<T>* m_pHead{ nullptr };

	int m_listSize = 0;

public:
	DoubleList() {}

	const T& GetAt(int index)
	{
		if (!m_pHead) throw std::out_of_range("List is empty");
		if (index > Size()) throw std::out_of_range("index out of range");

		DoubleNode<T>* walkerNode = m_pHead;

		while (index--)
		{
			if (index) walkerNode = walkerNode->GetNext();
			else
			{
				return walkerNode->GetData();
			}

		}

	}

	int Size()
	{
		return m_listSize;
	}

	void Append(const T& value) 
	{
		++m_listSize;
		if (!m_pHead)
			m_pHead = m_pTail = new DoubleNode<T>{ value, nullptr, nullptr };
		else
		{
			DoubleNode<T>* pPrevious = m_pTail;
			DoubleNode<T>* pNew = new DoubleNode<T>{ value, nullptr, pPrevious};
			m_pTail = pNew;
			pPrevious->SetNext(pNew);
		}
	}

	void InsertAt(int index, const T& value) 
	{
		
		if (!m_pHead)
		{
			m_pHead = m_pTail = new DoubleNode<T>{ value,nullptr,nullptr };
			++m_listSize;
			return;
		}
		if (index > Size()) std::out_of_range("Index out of range");
		
		else
		{
			if (index == 1)
			{
				DoubleNode<T>* newNode = new DoubleNode<T>{ value,m_pHead,nullptr };
				m_pHead->SetPrevious(newNode);
				m_pHead = newNode;
				++m_listSize; 
				return;
			}

			DoubleNode<T>* walkerNode = m_pHead;
			--index;//index se umanjuje kako bi se racunanje pozicije prebacino na 0-base
			while (--index)
			{
				if (index) walkerNode=walkerNode->GetNext();
				else
				{
					DoubleNode<T>* newNode = new DoubleNode<T>( value,walkerNode,walkerNode->GetNext() );
					walkerNode->GetNext()->SetPrevious(newNode);
					walkerNode->SetNext(newNode);
					++m_listSize;
					return;
				}
			}
		}
	}

	void RemoveAt(int index) 
	{
		if (!m_pHead)
			throw std::out_of_range("List is empty");

		if (index > Size())
			throw std::out_of_range("Index out of range");

		if (index == 1)
		{
			DoubleNode<T>* toBeRemoved = m_pHead;
			m_pHead = m_pHead->GetNext();
			delete toBeRemoved;
		}
		else
		{
			--index;
			DoubleNode<T>* walkerNode = m_pHead;
			while (--index)
			{
				if (index) walkerNode = walkerNode->GetPrevious();
				else 
				{
					DoubleNode<T>* toBeRemoved = walkerNode->GetNext();
					walkerNode->SetNext(toBeRemoved->GetNext());
					toBeRemoved->GetNext()->SetPrevious(walkerNode);
					delete toBeRemoved;
					return;
				}
			}
		}
	}

private:
};