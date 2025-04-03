#ifndef UNORDERED_LINKED_LIST
#define UNORDERED_LINKED_LIST
#include "linked_list.h"
#include "node.h"
#include <iostream>
template <class Type>
class UnorderedLinkedList : public LinkedList<Type>
{
public:
    bool search(const Type &item) const;
    void insertFirst(const Type &item);
    void insertLast(const Type &item);
    void deleteNode(const Type &item);
};

template <class Type>
bool UnorderedLinkedList<Type>::search(const Type &item) const
{
    Node<Type> *current;
    bool found{false};

    current = UnorderedLinkedList::m_first;

    while (current != nullptr && !found)
    {
        if (current->data == item)
        {
            found = true;
        }
        else
            current = current->link;
    }
    return found;
}

/**
 * 1. Create a new node
 * 2. Store the new item in new node
 * 3. Insert the node before first
 * 4. Increment count by 1
 */
template <class Type>
void UnorderedLinkedList<Type>::insertFirst(const Type &item)
{
    Node<Type> *newNode{new Node<Type>};
    newNode->data = item;
    newNode->link = UnorderedLinkedList::m_first;
    UnorderedLinkedList::m_first = newNode;
    UnorderedLinkedList::m_count++;

    if (UnorderedLinkedList::m_last == nullptr)
        UnorderedLinkedList::m_last = newNode;
}

template <class Type>
void UnorderedLinkedList<Type>::insertLast(const Type &item)
{
    Node<Type> *newNode{new Node<Type>};
    newNode->data = item;
    newNode->link = nullptr;

    if (UnorderedLinkedList::m_first == nullptr)
    {
        UnorderedLinkedList::m_first = newNode;
        UnorderedLinkedList::m_last = newNode;
        UnorderedLinkedList::m_count++;
    }
    else
    {
        UnorderedLinkedList::m_last->link = newNode;
        UnorderedLinkedList::m_last = newNode;
        UnorderedLinkedList::m_count++;
    }
}

template <class Type>
void UnorderedLinkedList<Type>::deleteNode(const Type &item)
{
    Node<Type> *current;
    Node<Type> *previous;
    bool found;

    if (UnorderedLinkedList::m_first == nullptr)
        std::cout << "List empty, nothing to delete." << std::endl;
    else
    {
        if (UnorderedLinkedList::m_first->data == item)
        {
            current = UnorderedLinkedList::m_first;
            UnorderedLinkedList::m_first = UnorderedLinkedList::m_first->link;
            UnorderedLinkedList::m_count--;

            if (UnorderedLinkedList::m_first == nullptr)
                UnorderedLinkedList::m_last = nullptr;

            delete current;
        }
        else
        {
            found = false;
            previous = UnorderedLinkedList::m_first;

            current = UnorderedLinkedList::m_first->link;

            while (current != nullptr && !found)
            {
                if (current->data != item)
                {
                    previous = current;
                    current = current->link;
                }
                else
                    found = true;
            }
            if (found)
            {
                previous->link = current->link;
                UnorderedLinkedList::m_count--;

                if (UnorderedLinkedList::m_last == current)
                    UnorderedLinkedList::m_last = previous;
                delete current;
            }
            else
                std::cout << "Item not in list." << std::endl;
        }
    }
}

#endif // UNORDERED_LINKED_LIST_H
