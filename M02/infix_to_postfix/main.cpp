// Program name: main.cpp
// Author: Grant Simpson
// Date last updated: 3/31/25
// Description: Create a program that utilizes stacks to convert an infix expression to postifix.
#include "InfixToPostfix.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    string infx;
    InfixToPostfix expr{};
    cout << "Enter infix expression (enter -1 to quit): ";
    getline(cin, infx);
    cout << endl;
    while (true)
    {
        if (infx == "-1")
            return 0;

        expr.getInfix(infx);
        expr.convertToPostfix();
        expr.showInfix();    
        expr.showPostfix();
        cout << endl;

        cout << "Enter infix expression (enter -1 to quit): ";
        getline(cin, infx);
        cout << endl;
    }

    return 0;
}