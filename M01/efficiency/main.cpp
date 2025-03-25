// Program name: main.cpp
// Author: Grant Simpson
// Date last updated: 03/24/2025
// Purpose: Example of pointer arithmetic.

#include <iostream>

using namespace std;

int main()
{

    int arr[] {2, 4, 6};
    int *ptr{arr};
    for (int i=0; i < 3; ++i) {
        cout << "Element at index " << i << " has a memory address of " << ptr 
             << " and a value of " << *ptr << endl;
    ++ptr;
    }

return 0;

}
