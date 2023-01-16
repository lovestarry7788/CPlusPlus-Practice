//
// Created by 刘智杰 on 2023/1/16.
//

#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;


template<typename Container, typename Index>
decltype(auto) authAndAccess(Container& c,Index i) {
    return c[i];
}
/*
auto 起站位符，c[i] 放到 auto。
Container& c 是一个左值引用，一个右值是没办法交给一个左值引用的。
*/

template<typename Container, typename Index>
decltype(auto) authAndAccess(Container&& c,Index i) {
    return forward<Container>(c)[i];
}
/*
auto 起站位符，c[i] 放到 auto。
Container&& c 是一个万能引用，一个万能引用既可以接受左值，也可以接受右值。
forward 完美转换。
c++14 支持 decltype(auto)
c++11 需要写到后面去 -> decltype(forward<Container>(c)[i])
*/



template<typename Container, typename Index>
auto authAndAccess(Container& c,Index i) {
    return c[i];
}
/*
编译错误，expression is not assignable， 返回一个右值。
*/

/*
template<typename Container, typename Index>
auto authAndAccess(Container& c,Index i) -> decltype(auto) {
    return c[i];
}
*/

int main()
{
    /*
    deque<int> d;
    authAndAccess(d, 5) = 10;
    */

    Widget w;
    const Widget& cw = w;
    auto myWidget1 = cw; // const & 修饰都会丢掉
    decltype(auto) myWidget2 = cw; // const Widget&

    int x = 10;
    decltype(x) y = x;
    decltype((x)) y = x; // 多一个小括号，变成 int&

    return 0;
}
