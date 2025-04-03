// Program name: main.cpp
// Author: Grant Simpson
// Date last updated: 3/31/25
// Description: Create a program that utilizes stacks to convert a binary number to decimal.
#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
bool isValidBinary(string binary);
int main()
{

    stack<int> binStack{};
    bool isDone{false};
    string binaryNum{};
    int decimal{0};
    int exponent{0};

    while (!isDone)
    {
        cout << "Enter binary number (enter -1 to quit): ";
        cin >> binaryNum;
        if (binaryNum == "-1") {
            isDone = true;
        }
        else if (!isValidBinary(binaryNum))
        {
            cout << "Invalid binary number. Enter 1s and 0s only." << endl;
        }
        else
        {
            for (const auto digit : binaryNum)
                binStack.push(digit);

            char symbol{};
            while (!binStack.empty()) {
                symbol = binStack.top();
                binStack.pop();
                // This is where the actual coversion happens
                if (symbol == '1')
                    decimal += pow(2, exponent);
                ++exponent;
            } // end while
            cout << binaryNum << " = " << decimal << endl;
            // reset decimal and exponent for next conversion
            decimal = 0;
            exponent = 0;
        } // end else
    } // end while

    return 0;
}

bool isValidBinary(string binary)
{
    for (const auto digit : binary)
        if (digit != '1' && digit != '0')
            return false;
    return true;
}