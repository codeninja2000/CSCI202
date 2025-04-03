// Program name: main.cpp
// Author: Grant Simpson
// Date last updated: 03/29/2025
// Purpose: Purpose of program.
#include "unordered_linked_list.h"
#include "linked_list_iterator.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    UnorderedLinkedList<int> ulist;
    UnorderedLinkedList<int> clist;
    cout << "Enter num (-999 to quit): ";
    int num;
    cin >> num;
    while (num != -999)
    {
        if (num % 4 == 0 || num % 3 == 0)
            ulist.insertFirst(num);
        else
            ulist.insertLast(num);

        cin >> num;
    }
    cout << "list= ";
    ulist.print();
    cout << endl;

    clist = ulist;
    clist.deleteNode(33);
    clist.deleteNode(58);

    cout << "copy list= ";
    clist.print();
    cout << endl;

    // ulist.insertFirst(36);
    // ulist.insertLast(10);
    // ulist.insertFirst(65);
    // ulist.insertLast(30);
    // ulist.insertFirst(44);
    // ulist.deleteNode(10);
    // ulist.insertLast(27);
    // ulist.insertFirst(15);
    // ulist.insertFirst(90);
    // ulist.deleteNode(44);
    // ulist.deleteNode(87);

    // LinkedListIterator<int> it;

    // for (it = ulist.begin(); it != ulist.end(); ++it)
    //     cout << *it << " ";
    // cout << endl;
    return 0;
}