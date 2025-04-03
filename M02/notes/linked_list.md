# Linked List


![A linked list](\linked_list.png)



## What is a Linked List?

A linked list is a list of nodes in which the order is determined by the address stored in each node. 
For a single linked list, a node is comprised of two components: **data** and **next** (also called info and link).
data stores whatever data (int, char, double, bool etc.) is required and next is a ponter which points to the next node.

```cpp
template <class Type>
struct Node {
	Type data;
	Node<Type>* next;
};
```

## Traversing a Linked List

head cannot be used to traverse a list, instead create a new pointer called current that is set to head. 

```cpp
current = head;
while (current != nullptr) {
	// Process current
	current = current->next
}
```