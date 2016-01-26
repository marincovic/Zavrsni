#pragma once

#include "Node.h"

template<typename T>
class DoubleNode : public Node<T>
{
private:
	Node<T>* m_pPreviousNode{ nullptr };
public:
	DoubleNode(const T& data, Node<T>* pNextNode, Node<T>* pPreviousNode) : Node(data, pNextNode)
	{
		m_pPreviousNode = pPreviousNode;
	}
	~DoubleNode() override { }

	void SetPrevious(DoubleNode<T>* pPrevious) { m_pPreviousNode = pPreviousNode; }
	DoubleNode<T>* GetPrevious() const { return m_pPreviousNode; }
};