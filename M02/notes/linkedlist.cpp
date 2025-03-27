#include <iostream>
#include <string>
using namespace std;

/* Linked list: A collection of elements (or nodes) where the order is determined
   by the address (or link) that is stored in each node.

    --------     ---------------      ---------------
	| head | --> | data | link | -->  | data | link | --▼
    --------	 ---------------      ---------------
*/

// Create a generic node
template <typename Type>
	struct Node {
		Type data;
		node<Type> *link;
	};

// Create a linked list class
class LinkedList {
	protected:
		int m_count;
		Node<Type> *first;
		Node<Type> *last;
};

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

}
