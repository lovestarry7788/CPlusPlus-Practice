//
// Created by 刘智杰 on 2023/1/15.
//

#include <iostream>

using namespace std;

void someFunc(int, double) {

}


template<typename T>
void f(T& param) {

}

template<typename T>
void g(const T& param) {

}

template<typename T>
void h(T* param) {

}

template<typename T>
void f1(T&& param) { // universal reference

}

template<typename T>
void f2(T param) {

}

int main()
{

    int x = 27;
    const int cx = x;
    const int &rx = x;

    //Case 1:
    f(x); // T is int, param's type is int&
    f(cx); // T is const int, param's type is const int&
    f(rx); // T is const int, param's type is const int&


    g(x); // T is int, param's type is const int&
    g(cx); // T is const int, param's type is const int&
    g(rx); // T is const int, param's type is const int&

    const int *px = &x;
    h(&x); // T is int, param's type is int*
    h(px); // T is const int, param's type is const int*

    // Case2:
    f1(x); // x is lvalue, T is int&, param's type is int&
    f1(cx); // cx is lvalue, T is const int&, param's type is const int&
    f1(rx); // rx is lvalue, T is const int&, param's type is const int&
    f1(27); // 27 is rvalue, T is int, param's type is therefore int&&

    // Case3:
    f2(x); // T's and param's types are both int
    f2(cx); // T's and param's types are both int
    f2(rx); // T's and param's types are both int

    // Function Arguments:
    f2(someFunc); // void (*)(int, double)
    f(someFunc); // void (&)(int, double)

    return 0;
}