#ifndef LINKED_LIST_ITERATOR
#define LINKED_LIST_ITERATOR
#include "node.h"
#include <iostream>

// To traverse a linked list, and iterator is needed.
// An iterator is an object that produces each element in the list, one
// element at a time.
template <class Type>
class LinkedListIterator {
public:
	// Default constructor
	// Postcondition: current = nullptr
	LinkedListIterator();

	// Parametized constructor
	// Postcondition: current = ptr
	LinkedListIterator(Node<Type> *ptr);

	// Overloaded dereferencing operator
	// Postcondition: returns data within node
	Type operator*();

	// Overloaded pre-increment operator
	// Postcondition: iterator advanced to next node
	LinkedListIterator<Type> operator++();

	// Overloaded equality operator
	// Postcondition: returns true if iterator is equal to rhs iterator
	// and returns false otherwise
	bool operator==(const LinkedListIterator<Type>& rhs) const;

	// Overloaded not equal operator
	// Postcondition: returns true if iterator is not equal to rhs iterator
	// and returns false otherwise
	bool operator !=(const LinkedListIterator<Type>& rhs) const;

private:
	Node<Type> *m_current;

};


template <class Type>
LinkedListIterator<Type>::LinkedListIterator() : m_current{nullptr} {}

template <class Type>
LinkedListIterator<Type>::LinkedListIterator(Node<Type> *ptr) : m_current{ptr} {}

template <class Type>
Type LinkedListIterator<Type>::operator*()
{
    return m_current->data;
}

template <class Type>
LinkedListIterator<Type> LinkedListIterator<Type>::operator++()
{
    m_current = m_current->link;
    return *this;
}

template <class Type>
bool LinkedListIterator<Type>::operator==(const LinkedListIterator &rhs) const
{
    return (m_current == rhs.m_current);
}

template <class Type>
bool LinkedListIterator<Type>::operator!=(const LinkedListIterator &rhs) const
{
    return (m_current != rhs.m_current);
}


#endif // LINKED_LIST_ITERATOR_H