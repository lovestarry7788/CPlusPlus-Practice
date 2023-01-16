//
// Created by 刘智杰 on 2023/1/15.
//

#include <iostream>

using namespace std;

int main()
{
    auto x = 27; //
    const auto cx = x;
    const auto& rx = x;

    auto&& uref1 = x; // int& 左值变成左值引用
    auto&& uref2 = cx; // const int& 左值变成左值引用
    auto&& uref3 = 27; // int&& 右值变成右值引用

    cout << typeid(uref1).name() << " " << typeid(uref2).name() << " " << typeid(uref3).name() << endl;

    const char name[] = "R. N. Briggs";
    auto arr1 = name; // arr1's type is const char *, 退化成指针。
    auto& arr2 = name; // arr2's type is const char (&)[13], 变成数组的引用。

    // auto func1 = someFunc; // func1's type is void (*)(int, double)
    // auto func2 = someFunc; // func2's type is void (&)(int, double)

    // auto 与模版不同的是
    auto x1 = 27;
    auto x2(27);

    auto x3 = {27}; // type is std:initializer_list<int> value is {27}
    auto x4{27}; // ditto

    return 0;
}

/*
auto 的类型推导和模版的类型推导一样，常见的也有 指针/引用、通用指针、值。
*/
