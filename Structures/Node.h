#pragma once

template<typename T>
class Node
{
private:
	T m_data;
	Node<T>* m_pNextNode = nullptr;
public:
	Node(T data, Node<T>* pNextNode = nullptr)
	{
		m_data = data;
		m_pNextNode = pNextNode;
	}
	virtual ~Node() { }

	//void SetData(const T& data) { m_data = data; }
	const T& GetData() const { return m_data; }
	
	void SetNext(Node<T>* pNext) { m_pNextNode = pNext; }
	Node<T>* GetNext() const { return m_pNextNode; }
};