#include <iostream>

int main() {
    // Reference : lvalue reference & rvalue reference.

    // 1. lvalue reference : only lvalue.
    // (type name)& (identifier) = (lvalue expression);
    {
        int a = 3;
        int& b = a;    // a is lvalue
        // int& c = 3;    // Error : 3 is rvalue.
        const int& d = 3;    // const lvalue reference : lvalue & rvalue ok

        std::cout << "lvalue reference : " << a << ", " << b << ", " << d << std::endl;
    }

    // 2. rvalue reference : rvalue ok
    // (type name)&& (identifier) = (rvalue expression);
    {
        int&& val = 3;    // 3 is xvalue (eXpiring value : lvalue(glvalue) )
        int* pVal = &val;

        std::cout << "rvalue reference : " << *pVal << std::endl;
    }

    return 0;
}
