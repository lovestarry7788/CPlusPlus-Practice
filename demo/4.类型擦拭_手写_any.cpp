#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct Any {
    Any() : ptr(nullptr) {}
    ~Any() {
        if(ptr) delete ptr;
    }
    template<typename T>
    Any(const T& t) : ptr(new Devide<T>(t)){}
    Any(const Any& rhs) { 
        cout << "正在使用拷贝构造" << endl;
        ptr = rhs.ptr -> clone();
    } // 拷贝构造
    Any(Any &&rhs) { // 移动构造
        cout << "正在使用移动构造" << endl;
        ptr = rhs.ptr;
        rhs.ptr = nullptr;
    }

    Any& operator= (const Any& rhs) { // 赋值构造
        cout << "正在使用赋值构造" << endl;
        if(ptr) delete ptr;
        ptr = rhs.ptr -> clone();
        return *this;
    }
    Any& operator= (Any&& rhs) {
        cout << "正在使用万能赋值构造" << endl;
        if(ptr) delete ptr;
        ptr = rhs.ptr;
        rhs.ptr = nullptr;
        return *this;
    }
    
    struct Base {
        virtual Base* clone() = 0;
        virtual ostream& print(ostream& out) = 0;
    };

    template<typename T>
    struct Devide : Base{
        T data;
        Devide(const T& t) : data(t){}
        virtual Base* clone() {return new Devide<T>(data);}
        virtual ostream& print(ostream& out) {
            out << data;
            return out;
        }
    };

    template<typename T>
    T& get_data() {
        return ((Devide<T>*)(ptr)) -> data;
    }

    Base* ptr;
};

ostream& operator << (ostream& out, const Any& rhs) {
    rhs.ptr -> print(out);
    return out;
}

int main() {
    Any a = 3;
    cout << a << endl;
    Any b = string{"111"};
    cout << b << endl;
    a = move(b);
    cout << a << endl;
    return 0;
}


/*
reference: https://zhuanlan.zhihu.com/p/597223487
*/