#ifndef ORDERED_LINKED_LIST
#define ORDERED_LINKED_LIST
#include "node.h"
template <class Type>
class OrderedLinkedList
{
public:
    bool search(const Type &item);
    void insert(const Type &item);
    void insertFirst(const Type &item);
    void insertLast(const Type &item);
    void deleteNode(const Type &item);
};

#endif // ORDERED_LINKED_LIST_H

template <class Type>
bool OrderedLinkedList<Type>::search(const Type &item)
{
    bool found{ false };
    Node<Type> *current;

    while (current != nullptr && !found)
        if (current->data >= item)
            found = true;
        else
            current = current->link;
    if (found)
        found = (current->data == item)
    return found;
}

template <class Type>
void OrderedLinkedList<Type>::insert(const Type &item)
{
}

template <class Type>
void OrderedLinkedList<Type>::insertFirst(const Type &item)
{
}

template <class Type>
void OrderedLinkedList<Type>::deleteNode(const Type &item)
{
}
