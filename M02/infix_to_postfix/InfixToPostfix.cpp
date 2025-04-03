// Program name: InfixToPostfix.cpp
// Author: Grant Simpson
// Date last updated: 04/01/2025
// Purpose: Class member definitions for Infix to Postfix converter.
#include "InfixToPostfix.h"
#include <string>
#include <stack>
#include <iostream>


InfixToPostfix::InfixToPostfix(const std::string& infx) :m_infx{infx}, m_pfx{""} {}

void InfixToPostfix::getInfix(const std::string &infx) {
    m_infx = infx;
}

void InfixToPostfix::showInfix() const {
    std::cout << "Infix expression: " << m_infx << std::endl;
}

void InfixToPostfix::showPostfix() const {
    std::cout << "Postfix expression: " << m_pfx << std::endl;
}

void InfixToPostfix::convertToPostfix() {
    std::stack<char> stack;
    m_pfx = "";

    // Convert infix expression symbol by symbol
    for (const auto sym : m_infx) {
        // If sym is operand, append sym from infx
        if (isValidOperand(sym)) {
            m_pfx += sym;
        }
        // If sym is '(', push into stack
        else if (sym == '(')
            stack.push(sym);
        // If sym is ')', pop and append all symbols from stack until most recent
        // left parenthesis.
        else if (sym == ')') {
            while (!stack.empty() && stack.top() != '(') {
                m_pfx += stack.top();
                stack.pop();
            } 
            // Pop and discard left parenthesis
            stack.pop();
        } else {
            // Pop and discard all symbols above most recent left parenthesis and
            // have precedence greater than or equal to sym
            while (!stack.empty() && computePrecedence(stack.top(), sym)) {
                m_pfx += stack.top();
                stack.pop();
            }
            // Push sym onto the stack
            stack.push(sym);
        } // end else
    } // end for
    // Pop and append to pfx everything from the stack
    while (!stack.empty()) {
        m_pfx += stack.top();
        stack.pop();
    }
} // end convertToPostfix

bool InfixToPostfix::computePrecedence(char op1, char op2) {
    return (precedence(op1) >= precedence(op2));
}

int InfixToPostfix::precedence(char opr) {
    switch (opr)
    {
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1;
    }
}

bool InfixToPostfix::isValidOperand(char op) {
    return ((op >= '0' && op <= '9') || (op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z'));
}
