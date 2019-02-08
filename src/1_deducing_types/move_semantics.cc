#include <iostream>

int main() {
    // copy & move Case
    // 1. Object Initialize (Copy/Move Constructor)
    // 2. Operation = (Copy/Move Operator=)
    {
        /*
        class M {
          public:
            M();
            M(const M&);    // Copy Constructor
            M(M&& m);       // Move Constructor

            M& operator=(const M&);    // Copy Operator=
            M& operator=(M&&);         // Move Operator=
        };
        */
        class M {};

        M a;                   // Constructor
        M b(a);                // Copy Constructor
        M c(std::move(b));     // Move Constructor
        M d = std::move(a);    // Move Operator=
    }

    return 0;
}
