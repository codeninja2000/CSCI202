// Program name: InfixToPostfix.h
// Author: Grant Simpson
// Date last updated: 04/01/2025
// Purpose: Class declaration for InfixToPostfix. This class converts infix
// expressions to postfix

#ifndef INFIXTOPOSTFIX
#define INFIXTOPOSTFIX
#include <string>
class InfixToPostfix {
    public:
    InfixToPostfix(const std::string& infx = "");
    ~InfixToPostfix() {}
    
    // Stores the infx expression
    void getInfix(const std::string& infx);
    void showInfix() const;
    void showPostfix() const;
    void convertToPostfix();
    bool computePrecedence(char op1, char op2);
    
    private:
        std::string m_infx;
        std::string m_pfx;
        int precedence(char op);
        bool isValidOperand(char opr);
};


#endif // INFIXTOPOSTFIX_H