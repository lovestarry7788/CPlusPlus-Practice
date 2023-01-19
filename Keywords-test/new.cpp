//
// Created by 刘智杰 on 2023/1/18.
//

#include <iostream>

using namespace std;

class A
{
public:
    A(){cout << "A constructor" << endl;}
    A(const A&) {cout << "A copy" << endl;}
    virtual ~A(){cout << "A destory" << endl;}

};

void f(A* a) {
    A* b = a;

}

int main() {
    A* a = new A();
    f(a);
    delete(a);
    return 0;
}
