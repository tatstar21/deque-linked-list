#pragma once
#include <iostream> 

template <typename T>
class Node
{
public:
    T data;
    Node* next, * prev;

    Node* clone();
    Node(T dataNode);

};

template <typename T>
inline Node<T>::Node(T dataNode)
{
    data = dataNode;
    next = prev = nullptr;
}

template <typename T>
Node<T>* Node<T>::clone()
{
	Node* cloneNode = new Node(data);
	if (next != nullptr) {
		Node* cloneNext = next->clone();
		cloneNode->next = cloneNext;
	}
	return cloneNode;
}

template <typename T>
class Deque
{
public:
    Deque();
    ~Deque();
    void insertFront(T data);
    void insertRear(T data);
    void deleteFront();
    void deleteRear();
    T getFront();
    T getRear();
    int size();
    bool isEmpty();
    void erase();
	void display();

	Deque* clone();
	Deque& operator+(const Deque& queue);
	Deque& operator*(const Deque& queue);

private:

    Node<T>* front;
    Node<T>* rear;
    int sizeQueue;
};

template <typename T>
Deque<T>::Deque() 
{
    front = rear = nullptr;
    sizeQueue = 0;
}

template <typename T>
inline bool Deque<T>::isEmpty()
{
    return front == nullptr;
}

template <typename T>
inline int Deque<T>::size()
{
    return  sizeQueue;
}

template <typename T>
void Deque<T>::insertFront(T data)
{
	Node<T>* newNode = new Node<T>(data);

	if (front == nullptr) {
		rear = front = newNode;
	}
	else
	{
		newNode->next = front;
		front->prev = newNode;
		front = newNode;
	}
	sizeQueue++;
}

template <typename T>
void Deque<T>::insertRear(T data)
{
	Node<T>* newNode = new Node<T>(data);

	if (rear == nullptr) {
		front = rear = newNode;
	}
	else
	{
		newNode->prev = rear;
		rear->next = newNode;
		rear = newNode;
	}
	sizeQueue++;
}

template <typename T>
void Deque<T>::deleteFront()
{
	if (isEmpty())
		throw std::exception("\a\x1b[31mStack is empty!\n\x1b[0m");
	else
	{
		Node<T>* temp = front;
		front = front->next;

		if (front == nullptr)
			rear = nullptr;
		else
			front->prev = nullptr;
		delete temp;
	}
	sizeQueue--;
}

template <typename T>
void Deque<T>::deleteRear()
{
	if (isEmpty())
		throw std::exception("\a\x1b[31mStack is empty!\n\x1b[0m");
	else
	{
		Node<T>* temp = rear;
		rear = rear->prev;

		if (rear == nullptr)
			front = nullptr;
		else
			rear->next = nullptr;
		sizeQueue--;
	}
}

template <typename T>
T Deque<T>::getFront()
{
	if (isEmpty())
		return -1;
	return front->data;
}

template <typename T>
T Deque<T>::getRear()
{
	if (isEmpty())
		return -1;
	return rear->data;
}

template <typename T>
void Deque<T>::erase()
{
	rear = nullptr;
	while (front != nullptr) {
		Node<T>* temp = front;
		front = front->next;
		delete temp;
	}
	sizeQueue = 0;
}

template <typename T>
Deque<T>::~Deque()
{
	while (front != nullptr) {
		Node<T>* temp = front;
		front = front->next;
		delete temp;
	}
}

template <typename T>
void Deque<T>::display()
{
	if (front == nullptr) {
		std::cout << "\nQueue is empty" << std::endl;
	}
	else
	{
		Node<T>* tmpNode = front;
		while (tmpNode != nullptr) {
			std::cout << tmpNode->data;
			tmpNode = tmpNode->next;
			if (tmpNode != nullptr)
				std::cout << " <-> ";
		}
	}
}

template <typename T>
Deque<T>* Deque<T>::clone()
{
	Deque<T>* cloneQueue = new Deque<T>();
	if (front == nullptr)
		throw std::exception("\a\x1b[31mQueue is empty!\n\x1b[0m");
	else
		cloneQueue->front = front->clone();
	return cloneQueue;
}

template <typename T>
Deque<T>& Deque<T>::operator+(const Deque<T>& queue)
{
	Deque<T>* result = this->clone();

	Node<T>* temp = queue.front;

	while (temp != nullptr)
	{
		result->insertFront(temp->data);
		temp = temp->next;
	}
	return *result;
}

template <typename T>
Deque<T>& Deque<T>::operator*(const Deque<T>& queue)
{
	Deque<T>* result = new Deque<T>();

	if (front == nullptr)
		throw std::exception("\a\x1b[31mQueue is empty!\n\x1b[0m");
	else
	{
		Node<T>* temp1 = front;

		while (temp1 != nullptr)
		{
			Node<T>* temp2 = queue.front;

			while (temp2 != nullptr) {
				if (temp1->data == temp2->data) {
					result->insertFront(temp2->data);
				}
				temp2 = temp2->next;
			}
			temp1 = temp1->next;
		}
	}
	return *result;
}




