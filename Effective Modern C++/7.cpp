//
// Created by 刘智杰 on 2023/1/18.
//
// 条款7：对象初始化 {} vs ()

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Widget {
public:
    Widget(int i, bool b);
    Widget(int i, double d);
    Widget(initializer_list<long double> il);
};

int main() {
    Widget w1(10, true);
    Widget w2{10,true};
    Widget w3(10, 5.0);
    Widget w4{10, 5.0};

    return 0;
}