#ifndef LINKED_LIST
#define LINKED_LIST

#include "linked_list_iterator.h"
#include <cassert>
#include <iostream>

// Create a linked list class
template <class Type>
class LinkedList
{
public:
	// Overloaded assignment operator
	// Remember, when a class contains pointer member variables
	// the assignment operator must be overloaded! See chapters 12 and 13
	// in Malik for more information
	const LinkedList<Type> &operator=(const LinkedList<Type> &otherList);

	// Initialize list to empty state
	// Postcondition: m_count = 0, m_first = nullptr, m_last = nullptr
	void initList();

	// Determine if list is empty.
	// Postcondition: returns true if list is empty and false otherwise
	bool isEmpty() const;

	// Function to output each node's data
	void print() const;

	// Function to return the number of nodes in the list
	// Postcondition: returns value of m_count
	int length() const;

	// Function to delete all the nodes in a list
	// Postcondition: m_first = nullptr, m_last = nullptr, m_count = 0
	void destroyList();

	// Function to return the first element in the list
	// Postcondition: If the list is empty the program terminates otherwise
	// the first element is returned
	Type front() const;

	// Function to return the last element in the list
	// Postcondition: If the list is empty the program terminates otherwise
	// the first element is returned
	Type back() const;

	// Function to determine if item is present in the list
	// Postcondition: returns true if item is in the list and false otherwise
	virtual bool search(const Type &item) const = 0;

	// Function to insert item at beginning of the list
	// Postcondition: first points to new list, item is inserted at the
	// beginning of the list, last points to the last node in the list, and count
	// is incremented by 1.
	virtual void insertFirst(const Type &item) = 0;

	// Function to insert item at beginning of the list
	// Postcondition: first points to new list, item is inserted at the
	// end of the list, last points to the last node in the list, and count
	// is incremented by 1.
	virtual void insertLast(const Type &item) = 0;

	// Function to delete item from the list
	// Postcondition: If found, the node containing item is deleted from the list
	// first points to the first node in the list, last points to the last node in
	// the list, and count is incremented by 1.
	virtual void deleteNode(const Type &item) = 0;

	// Function to return an iterator at the beginning of the list.
	// Postcondition: Returns an iterator such that current is set to first.
	LinkedListIterator<Type> begin();

	// Function to return an iterator at the end of the list.
	// Postcondition: Returns an iterator such that current is set to last.
	LinkedListIterator<Type> end();

	// Default constructor
	// Postcondition: first = nullptr, last = nullptr, m_count = 0
	LinkedList();

	// Copy constructor
	LinkedList(const LinkedList<Type> &linkedList);

	// Destructor
	// Deletes all nodes from list
	// Postcondition: The list object is destroyed.
	~LinkedList();

protected:
	int m_count;
	Node<Type> *m_first;
	Node<Type> *m_last;

private:
	// Function to make a copy otherList
	// Postcondition: A copy of otherList is created and assigned to this list
	void copyList(const LinkedList<Type> &otherList);
};

template <class Type>
LinkedList<Type>::LinkedList() : m_first{nullptr}, m_last{nullptr}, m_count{0} {}

template <class Type>
bool LinkedList<Type>::isEmpty() const
{
    return (m_first == nullptr);
}

template <class Type>
void LinkedList<Type>::destroyList()
{

    Node<Type> *temp;

    while (m_first != nullptr)
    {
        temp = m_first;
        m_first = m_first->link;
        delete temp;
    }
    m_last = nullptr;
    m_count = 0;
}

template <class Type>
void LinkedList<Type>::initList()
{
    destroyList();
}

template <class Type>
void LinkedList<Type>::print() const
{
    Node<Type> *current;

    current = m_first;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->link;
    }
}

template <class Type>
int LinkedList<Type>::length() const
{
    return m_count;
}

template <class Type>
Type LinkedList<Type>::front() const
{
    assert(m_first != nullptr);
    return m_first->data;
}
template <class Type>
Type LinkedList<Type>::back() const
{
    assert(m_last != nullptr);
    return m_last->data;
}

template <class Type>
LinkedListIterator<Type> LinkedList<Type>::begin()
{
    LinkedListIterator<Type> temp(m_first);
    return temp;
}

template <class Type>
LinkedListIterator<Type> LinkedList<Type>::end()
{
    LinkedListIterator<Type> temp(nullptr);
    return temp;
}

template <class Type>
void LinkedList<Type>::copyList(const LinkedList<Type> &otherList)
{
    Node<Type> *newNode;
    Node<Type> *current;

    if (m_first != nullptr)
        destroyList();
    if (otherList.m_first == nullptr) {
        m_first = nullptr;
        m_last = nullptr;
        m_count = 0;
    } else {
        current = otherList.m_first;
        m_count = otherList.m_count;

        m_first = new Node<Type>;

        m_first->data = current->data;
        m_first->link = nullptr;

        m_last = m_first;

        current = current->link;

        while (current != nullptr) {
            newNode = new Node<Type>;
            newNode->data = current->data;
            newNode->link = nullptr;

            m_last->link = newNode;
            m_last = newNode;

			current = current->link;
        }
    }
}

template <class Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& otherList) :m_first{nullptr} {
    copyList(otherList);
}

template <class Type>
const LinkedList<Type>& LinkedList<Type>::operator=(const LinkedList<Type>& otherList) {
    if (this != &otherList) {
        copyList(otherList);
    }
    return *this;
}

template <class Type>
LinkedList<Type>::~LinkedList() {
    destroyList();
}


#endif // LINKED_LIST_H