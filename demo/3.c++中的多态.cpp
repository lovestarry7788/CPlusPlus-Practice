#include <cstdio>
#include <iostream>
#include <vector> 

using namespace std;

struct A {
    virtual void foo() = 0;
};
struct B : A {
    virtual void foo() { cout << "this is B\n"; }
};
struct C : A {
    virtual void foo() { cout << "this is C\n"; }
};
struct D : A {
    virtual void foo() { cout << "this is D\n"; }
};

int main() {      
    vector<A*>v = { new B{},new C{},new D{} };
    for (const auto& it : v) {
        it->foo();
    }
    return 0;
}