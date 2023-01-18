//
// Created by 刘智杰 on 2023/1/18.
//
// 条款6：当 auto 推导类型不符合要求时，使用带显示类型的初始化。

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> c;
    double d = 1.0;
    // int index = d * c.size();
    auto index = static_cast<int> (d * c.size()); // 编译型强转，隐式转换

    return 0;
}