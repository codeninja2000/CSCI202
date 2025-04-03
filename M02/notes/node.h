#ifndef NODE
#define NODE
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
		Node<Type> *link;
	};
#endif // NODE_H