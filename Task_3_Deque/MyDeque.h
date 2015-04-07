#pragma once
#include <vector>
#include <iostream>
#include <sstream>

template <class T>
class MyDeque
{
public:
	
	MyDeque() : begin(nullptr), end(nullptr), dequeSize(0) {}
	~MyDeque() { clear(); }

	void push_back(T const& element);
	void push_front(T const& element);

	bool empty();
	size_t size();
	
	T const& front();
	T const& back();

	T const& pop_back();
	T const& pop_front();

	T const& operator [](int index);
	void clear();

	operator std::string();
	
	friend std::ostream& operator << (std::ostream& out, MyDeque<T>& deque);

private:

	struct MyDequeNode {
		T data;
		MyDequeNode* next;

		MyDequeNode(const T& newData, MyDequeNode* nextNode) : data(newData), next(nextNode) {}
	};

	MyDequeNode *begin, *end;
	size_t dequeSize;
};

template <class T>
void MyDeque<T>::push_back(T const& element)
{
	if (end == nullptr) {
		push_front(element);
	}
	else
	{
		MyDequeNode *newNode = new MyDequeNode(element, nullptr);
		end->next = newNode;
		end = newNode;
		dequeSize++;
		std::cout << "I added " << element << " to back\n";
	}	
}

template <class T>
void MyDeque<T>::push_front(T const& element)
{
	begin = new MyDequeNode(element, begin);
	if (begin->next == nullptr)
		end = begin;
	dequeSize++;
	std::cout << "I added " << element << " to front\n";
}

template <class T>
bool MyDeque<T>::empty()
{
	return dequeSize == 0;
}

template <class T>
size_t MyDeque<T>::size()
{
	std::cout << "The size is " << dequeSize << "\n";
	return dequeSize;
}

template <class T>
T const& MyDeque<T>::front()
{
	if (empty())
		throw std::invalid_argument("Can't invoke FRONT on an empty deque");

	return begin->data;
}

template <class T>
T const& MyDeque<T>::back()
{
	if (empty())
		throw std::invalid_argument("Can't invoke BACK on an empty deque");

	return end->data;
}

template <class T>
T const& MyDeque<T>::pop_back()
{
	if (empty())
		throw std::invalid_argument("Can't invoke POP_BACK on an empty deque");

	MyDequeNode *temp = begin;
	while (temp != end && temp->next != end)
		temp = temp->next;
	
	T data = end->data;
	delete end;
	temp->next = nullptr;
	if (temp != end)
		end = temp;
	
	dequeSize--;
	return data;	
}

template <class T>
T const& MyDeque<T>::pop_front()
{
	if (empty())
		throw std::invalid_argument("Can't invoke POP_FRONT on an empty deque");

	MyDequeNode *temp = begin;
	begin = begin->next;
	if (begin == nullptr)
		end = nullptr;

	T data = temp->data;
	delete temp;
	dequeSize--;
	return data;
}

template <class T>
T const& MyDeque<T>::operator[](int index)
{
	if (empty())
		throw std::invalid_argument("Can't invoke indexer on an empty deque");
	if (index < 0)
		throw std::invalid_argument("Index can't be negative");

	MyDequeNode* temp = begin;
	for (int i = 0; i <= index - 1; i++)
	{
		if (temp->next != nullptr)
			temp = temp->next;
		else
			throw std::invalid_argument("Index was bigger than deque's length");
	}

	return temp->data;
}

template <class T>
void MyDeque<T>::clear()
{
	while (!empty())
	{
		pop_front();
	}
}

template <class T>
MyDeque<T>::operator std::basic_string<char>()
{
	if (empty())
		return "";

	std::stringstream ss;
	MyDequeNode* temp = begin;
	while (temp)
	{
		ss << temp->data;
		ss << ' ';
		temp = temp->next;
	}
	return ss.str();
}

template <class T>
std::ostream& operator << (std::ostream& out, MyDeque<T>& deque) {
	if (deque.empty())
	{
		return out;
	}
	
	for (int i = 0; i < deque.size(); i++)
	{
		out << deque[i] << ' ';
	}
	return out;
}