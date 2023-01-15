//
// Created by 刘智杰 on 2023/1/15.
//

#include <iostream>

using namespace std;

template<typename> T
void f(T& param);

int main()
{

    int x = 27;
    const int cx = x;
    const int &rx = x;

    f(x);
    f(cx);
    f(rx);

    return 0;
}