#pragma once
#include <vector>
#include <iostream>

template <class T>
class MyDeque
{
public:
	void push_back(T const& element);
	void push_front(T const& element);

	bool empty();
	size_t size();
	
	T const& front();
	T const& back();

	T const& pop_back();
	T const& pop_front();

	T const& operator [](size_t index);

	friend std::ostream& operator << (std::ostream& out, MyDeque* deque);
	friend std::ostream& operator << (std::ostream& out, MyDeque deque);

private:
	std::vector<T> elements_;

};

template <class T>
void MyDeque<T>::push_back(T const& element)
{
	elements_.push_back(element);
	std::cout << "I added " << element << " to back\n";
}


template <class T>
void MyDeque<T>::push_front(T const& element)
{
	elements_.insert(elements_.begin(), element);
	std::cout << "I added " << element << " to front\n";
}

template <class T>
bool MyDeque<T>::empty()
{
	bool test = elements_.size() == 0;
	std::cout << "Emptiness: " << test << '\n';

	return elements_.size() == 0;
}

template <class T>
size_t MyDeque<T>::size()
{
	std::cout << elements_.size() << '\n';
	return elements_.size();
}

template <class T>
T const& MyDeque<T>::front()
{
	if (empty())
		throw std::invalid_argument("Can't invoke FRONT on an empty deque");

	std::cout << elements_[0] << '\n';
	return elements_[0];
}

template <class T>
T const& MyDeque<T>::back()
{
	if (empty())
		throw std::invalid_argument("Can't invoke BACK on an empty deque");

	std::cout << elements_[elements_.size() - 1] << '\n';
	return elements_[elements_.size() - 1];
}

template <class T>
T const& MyDeque<T>::pop_back()
{
	if (empty())
		throw std::invalid_argument("Can't invoke POP_BACK on an empty deque");

	T const& result = elements_[elements_.size() - 1];
	elements_.erase(elements_.end() - 1);
	return result;
}

template <class T>
T const& MyDeque<T>::pop_front()
{
	if (empty())
		throw std::invalid_argument("Can't invoke POP_FRONT on an empty deque");

	T const& result = elements_[0];
	elements_.erase(elements_.begin());
	return result;
}

template <class T>
T const& MyDeque<T>::operator[](size_t index)
{
	if (index < 0 || index >= elements_.size())
		throw std::invalid_argument("Index must be correct");

	return elements_[index];
}

template <class T>
std::ostream& operator << (std::ostream& out, MyDeque<T>* deque) {
	for (size_t i = 0; i < deque->size(); i++)
		out << (*deque)[i] << " ";
	return out;
}

template <class T>
std::ostream& operator << (std::ostream& out, MyDeque<T> deque) {
	for (size_t i = 0; i < deque.size(); i++)
		out << deque[i] << " ";
	return out;
}