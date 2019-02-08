#include <iostream>

int main() {
    // copy & move Case
    // 1. Object Initialize (Copy/Move Constructor)
    // 2. Operation = (Copy/Move Operator=)
    {
        class M {
          public:
            M() { std::cout << "Constructor !!" << std::endl; }
            M(const M&) { std::cout << "Copy Constructor !!" << std::endl; }
            M(M&& m) { std::cout << "Move Constructor !!" << std::endl; }

            M& operator=(const M&) { std::cout << "Copy Operator= !!" << std::endl; }
            M& operator=(M&&) { std::cout << "Move Operator= !!" << std::endl; }
        };

        M a;                   // Constructor
        M b(a);                // Copy Constructor
        M c(std::move(b));     // Move Constructor
        M d = a;               // Copy Operator=
        M e = std::move(a);    // Move Operator=
    }

    return 0;
}
