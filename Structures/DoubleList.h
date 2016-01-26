#pragma once

#include "DoubleNode.h"
#include "List.h"

template<typename T>
class DoubleList : public List<T>
{
protected:
	DoubleNode<T>* m_pTail{ nullptr };

public:
	DoubleList() {}

	void Append(const T& value) override
	{
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

	void InsertAt(int index, const T& value) override
	{

	}

	void RemoveAt(int index) override
	{

	}

private:
};