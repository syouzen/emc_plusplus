#include <iostream>

int main() {
    // deducing types
    // 1. template
    // 2. auto
    // 3. decltype

    {
        /* Deducing ParamType
         * void f (ParamType param);
         * f(expr);
         *
         * 1. ParamType : Pointer & Reference, but not Universal Reference (&&)
         * 2. ParamType : Universal Reference
         * 3. ParamType : Not Pointer & Reference
         */

        int x = 3;
        const int cx = x;
        const int& crx = x;
        int&& rrx = 3;
        const int&& crrx = 3;
        const int* cpx = &x;
        const int* const cpcx = &x;

        /* Case 1 : Pointer & Reference, but not Universal Reference (&&)
         * If expr is reference, ignore reference.
         * Deduces T type from ParamType(=expr).
         *
         * template<typename T>
         * void f(T& param);
         * 
         * value : T / ParamType
         * x : int / int&
         * cx : const int / const int&
         * crx : const int / const int&
         * rrx : int / int&
         * crrx : const int / const int&
         */

        /* Case 2 : Universal Reference
         * If expr is lvalue, T and ParamType are deduced lvalue reference.
         * If expr is rvalue, same Case 1. 
         *
         * template<typename T>
         * void f(T&& param);
         *
         * x : int& / int&
         * cx : const int& / const int&
         * crx : const int& / const int&
         * rrx : int& / int& (Universal Reference is lvalue)
         * crrx : const int& / const int&
         * 3 : int / int&&
         */

        /* Case 3 : Not Pointer & Referecne
         * If expr is reference, ignore reference and Type specifier (const, volatile ...).
         *          
         * template<typename T>
         * void f(T param);
         *
         * x : int / int
         * cx : int / int
         * rx : int / int
         * cpx : const int* / const int*
         * cpcx : const int* / const int* (Pointer Constness is ignored.)
         */
    }

    // Array vs Pointer
    {
        const char name[] = "Choi";
        const char* pName = name;

        /* Case 1 : Same
         *
         * template<typename T>
         * void f(T param);
         *
         * name : const char* / const char*
         */

        /* Case 2
         *
         * template<typename T>
         * void f(T& param);
         *
         * name : const char[5] / const char(&)[5] (Array Reference)
         */

        /* Case 3
         *
         * template<typename T>
         * void f(T&& param);
         *
         * name : const char(&)[5] / const char(&)[5]
         */
    }

    // auto
    {
        int x1 = 3;
        int x2(3);
        int x3 = {27};    // Uniform Initialize
        int x4{27};       // Uniform Initialize

        auto ax1 = 3;
        auto ax2(3);
        auto ax3 = {27};    // std::initializer_list<int>
        auto ax4{27};       // std::initializer_list<int>

        /* Auto : Uniform Initialize, deducing X
         * Template : Uniform Initialize, deducing O
         */
    }

    return 0;
}
