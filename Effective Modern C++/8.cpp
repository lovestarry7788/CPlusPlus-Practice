//
// Created by 刘智杰 on 2023/1/19.
//
// 条款8：优先使用 nullptr

#include <iostream>
#include <vector>
#include <unordered_map>
#include <mutex>

using namespace std;

class Widget{};

int f1(shared_ptr<Widget> spw) {}
double f2(unique_ptr<Widget> upw) {}
bool f3(Widget* pw){}

template<typename FuncType, typename MuxType, typename PtrType>
decltype(auto) lockAndCall(FuncType func, MuxType& Mutex, PtrType ptr)
{
    using MuxGuard = lock_guard<mutex>;
    MuxGuard g(Mutex);
    return func(ptr);
}

int main() {
    mutex f1m, f2m, f3m;

    // auto result1 = lockAndCall(f1, f1m, 0);
    // auto result2 = lockAndCall(f2, f2m, NULL);
    auto result3 = lockAndCall(f3, f3m, nullptr);


    return 0;
}