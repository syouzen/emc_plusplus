#include <iostream>
#include <vector>

// C++ 11
template <typename Container, typename Index>
auto authAndAccess(Container& c, Index i)
    -> decltype(std::forward<Container>(c)[i]) {
    return std::forward<Container>(c)[i];
}

/* C++ 14 
template <typename Container, typename Index>
decltype(auto) authAndAccess(Container& c, Index i) {
    return std::forward<Container>(c[i]);
}
*/

int main() {
    // decltype (declared type) : Return Type
    {
        const int i = 0;
        // decltype(i) : const int
        // decltype(&i) : const int*

        const int& ri = i;
        // decltype(ri) : const int&

        int f(int a);
        // decltype(f) : int(int)
    }

    {
        /*
         * template <typename Container, typename Index>
         * auto authAndAccess(Container& c, Index i)
         *     ->decltype(c[i]) {
         *     return c[i];
         * }
         *
         * c[i] is changed by Container Type. So, return type is defined by ParamType.
         * But auto doesn't deduce return type. So, use trailing return type(->decltype(c[i])).
         * Only C++ 11, Not C++ 14.
         */

        std::vector<int> v;
        authAndAccess(v, 5) = 10;    // Error : v[5] Type is not int&. it is int.
    }

    // decltype(auto) : C++14
    {
        int i = 3;
        const int& ci = i;
        auto ai = ci;               // auto : const int
        decltype(auto) ai2 = ci;    // decltype(auto) : const int&

        /*
         * template <typename Container, typename Index>
         * decltype(auto) authAndAccess(Container& c, Index i) {
         *     return c[i];
         * }
         */

        std::vector<int> v;
        authAndAccess(v, 5) = 10;    // OK : v[5] Type is int&.
    }

    // std::forward : Case (ParamType is rvalue).
    {
        /*
         * std::vector<int> makeVector();
         * auto a = authAndAccess(makeVector(), 0);
         *
         * makeVector() is rvalue (temp Object). So, a is dangling pointer.
         * We can use std::forward. std::forward can handle both lvalue and rvalue.
         * 
         * template <typename Container, typename Index>
         * auto authAndAccess(Container& c, Index i)
         *      ->decltype(std::forward<Container>(c)[i]) {
         *      return std::forward<Container>(c)[i];
         * }
         *  
         */
    }

    // decltype Exception
    {
        /*
         * decltype(auto) f1() {
         *     int x = 0;
         *     return x;    //decltype(x) : int
         * }

         * decltype(auto) f2() {
         *     int x = 0;
         *     return (x);    // decltype((x)) is int&
         * }
         */
    }

    return 0;
}
