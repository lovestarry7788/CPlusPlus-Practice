//
// Created by 刘智杰 on 2023/1/18.
//
// 条款5：优先选用 auto，而非显式类型声明。

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {

    auto derefLess = [](const auto& p1, const auto& p2){return *p1 < *p2;};

    vector<int> v;
    // unsigned sz = v.size();
    // 在 64 位的 windows 下，unsigned 是 32 个字节，vector<int>::size_type 是 64 个字节。

    auto sz = v.size();

    unordered_map<string,int> m;
    /*
    for (const pair<string,int>& p : m) { // 编译器会重新创建一个匿名对象，然后用p来引用它。

    }
    */
    for (const auto& p: m) {

    }


    return 0;
}