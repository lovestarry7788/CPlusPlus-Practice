//
// Created by 刘智杰 on 2023/1/19.
//
// 条款9：用 using 替换 typedef

#include <iostream>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <list>

using namespace std;

class Widget{};

template<typename T>
using MyAllocList = list<T>;

int main() {



    MyAllocList<Widget> lw;

    return 0;
}