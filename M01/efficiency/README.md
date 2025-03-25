# M01.2 - Efficiency

## Description

Discuss the specifics of pointers and provide examples pointer arithmetic that include comments on the efficiency of the program in terms of Big-O notation. 

## Questions & Answers

### 1. What is a pointer and how it is initialized ?

A pointer is an object that holds a memory address. Pointers can be initialized in a few ways: 

- A pointer can be initialized to an existing variable using the address-of operator, `&`.

- A pointer can be initialized to `nullptr`

- A pointer can be initialized using dynamic memory allocation. In other words, using the `new` operator.

- A pointer can be initialized to the first element in an array by setting the pointer variable to the first element without the subscript operator like so:
    ```cpp
    int arr[] {2, 4, 6};
    int *ptr{ arr }
    ```

### 2. How is a pointer declared ?

A pointer can be declared by specifying the type and variable name with an `*` between them:
```cpp
char* pchar;    // Valid
char * pchar;   // Valid
char *pchar;    // Valid
```

### 3. How is variable accessed through its pointer?

A variable can be accessed through its pointer using the dereference operator `*`:
```cpp
int x{ 20 };
int *px{ &x };    // px points to address of x
*px -= 5;         // Using the derefence operator to subtract 5 from x
std::cout << x;   // prints "5"
```

### 4. What is the relationship between an array name and a pointer in C/C++?

The name of an array is the address of the first element in the array. See the 4th method of question 1's answer for an example.

### 5. What is pointer arithmetic ? How is it performed ?

Pointer arithmetic allows for arithmetic operators to be used to produce a new memory address. There are four arithmetic operators that may be used: `+`, `-`, `++`, `--`. In other words, only addition and subtraction can be used in pointer arithmetic. For example `ptr + 1` returns the next object in memory, and similarly `ptr - 1` returns the previous object in memory. 

### 6. Explain 5 with a programming example - include the efficiency of the program in Big O notation.

The full example can be found [here](main.cpp).

```cpp
1    int arr[] {2, 4, 6};
2    int *ptr{arr};
3    for (int i=0; i < 3; ++i) {
4        cout << "Element at index " << i << " has a memory address of " << ptr 
5             << " and a value of " << *ptr << endl;
6    ++ptr;
    }
```
An array `arr[]` of 3 integer elements and a pointer `ptr` to that array are declared. The array is then traversed using a for loop and pointer arithmetic. The increment operator is used on `ptr` to traverse the array. During each iteration the index `i`, memory address `ptr`, and value `*ptr` are output. 

#### Time Complexity in Big O
Initial function: f(n) = 0

Line 1 takes n operations to complete because the memory locations need to be written to n times.

f(n) = n

Line 2 takes 2 operations to complete (declaration and assignment).

f(n) = n + 2

The for loop consist of 4 instructions at the beginning `(int i=0; i < 3; ++i)`, 2n instructions for (`i < 3; ++i`) n being number of times the loop ran. For the body of the loop, the cout statement will run 6n times and line 6 will run 2n times. 6n because cout is called 6 times each iteration and 2n because `++ptr` is really `ptr = ptr + 1`.

f(n) = n + 2 + 2n + 6n + 2n

f(n) = 11n + 2

Asymptoticaly, f(n) = n, therefore time complexity is linear Θ(n). The upper bound is O(n<sup>2</sup>) and the tight bound is O(n)

To summarize:

f(n) = 11n + 2

time complexity = Θ(n)

upper bound = O(n<sup>2</sup>)

tight bound = O(n)


## Author
Grant Simpson