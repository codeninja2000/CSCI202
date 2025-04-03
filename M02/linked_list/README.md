# Linked List

## Description

Complete the following exercises in C++ Programming by Malik:

1. Exercises 1-10 on page 1166
2. Exercises 20-25 on page 1172

## Exercises

### Part 1 (p. 1166, 1-10)



1. Mark the following statements as true or false.

    a. true (if it is a singlely linked list)

    b. false

    c. false

    d. false

    e. false (current = current->link)

    f.true

    g. true

    h. false

    i. false

    j. true

    k. true

    l. false

    m. false

    n. true

2. A single linked list node has an *info* and *link* component. info holds whatever data needs to be stored and link stores the address of the next node. If the node
	is the last node, link is NULL (`nullptr` in the context of C++).

3. `nullptr`

4. The value of the link component of the first node.

5. A pointer to the third node is needed because the link component changes from pointing to
   the fourth node's address to either pointing to the fifth node's address or is set to `nullptr`.

6.
	a. 12
	b. 92 65
	c. 80
	d. 46
	e. does not exist so undefined behavior
	f. 5

7.
	a. true
	b. true
	c. false
	d. true
	e. true
	f. false

8.
	a. The last node is removed from the list by pointing second to last node to nullptr,
	   freeing the last node in memory, and setting last to point to what was previously the second
	   to last node and is now the last node.
	b. No effect, temp->link and last point to the same node.
	c. The info componenet of the node to by first is increased from 47 to 58.
	d. current->link is removed from the list and freed in memory and current->link is modified to point to the node
	   immediately to the right of the deleted node.
	e. The info component of the node pointed to by current->link is decreased from 80 to 60.
	f. p->link is set to point to the node pointed to by temp. The node previously pointed to by p->link becomes inaccessible.

9.
	a. `p->link->info = 24;`
	b. `q = current->link;`
	c. `first = first->link;`
	d. `trail = p->link;`
	e. `p = nullptr;`
	f. `temp->link->info = 54;`
	g. ```cpp
		while (first->info != 5)
			first = first->link;
		```
10.
	a. valid but also useless since p already points to the pointee of list->link.
	b. valid but again useless since first == list already.
	c. valid assignment but also not valid in the sense that the second to last node had not been freed and is now inaccessible.
	d. invalid because the link component of a node is suppose to point towards the next node, not toward the next node's info component.
	e. invalid, p is a pointer. last is a dereferenced pointer. Dereferencing a (valid) pointer access the value pointed to by that pointer. Since
	   pointers only store addresses, it would be invalid to store a dereferenced pointer because a dereferenced pointer is a value (assuming pointer
	   is valid) and not an address.
	f. invalid. Similar to the previous answer (e), first is a pointer to a node and 90 is a data value. Since a pointer can only store addresses, it
	   would be invalid to store the value 90 into the pointer first.
	g. valid.
	h. invalid because it is not valid to store a pointer into a non-pointer variable.
	i. valid.
	j. invalid because last->link->link does not exist and accessing a non existent value is undefined behavior.
	k. invalid because trail is unitialized so trail->link->link->info is undefined behavior.

### Part 2 (p. 1172, 20-25)


20. let OLL = orderedLinkedList and ULL = unorderedLinkedList.
	OLL::insertFirst does not actually insert an item at the beginning of the list. OLL::insertFirst calls
	OLL::insert which inserts the value in its proper place. That is, it insert the node into the list
	according to the sort criteria. Meanwhile ULL:insertFirst actually inserts the new node at the begininng
	of the list.

21. 90 36 10 30 27

22. ```
       list = 16 120 64 40 12 45 35 83 23 11 98
	   Item not in list.
       Item not in list.
       copyList = 16 120 64 40 12 45 35 83 23 11 98
	```