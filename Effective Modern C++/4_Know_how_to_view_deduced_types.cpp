//
// Created by 刘智杰 on 2023/1/16.
//
/*
条款4：如何查看类型推导中得到的结果。
*/

#include <iostream>
#include <vector>
#include <boost/type_index.hpp>
#include <typeinfo>

using namespace std;

template<typename T>
class TD; // TD == "Type Display"
/*
由于 TD 类会报错，可以看到对应的类。
error: implicit instantiation of undefined template 'TD<int>'
error: implicit instantiation of undefined template 'TD<const int *>'
*/

/*
template<typename T>
void f(const T& param) {
    cout << "T = " << typeid(T).name() << endl;
    cout << "param = " << typeid(param).name() << endl;
}
*/
template<typename T>
void f(const T& param) {
    using boost::typeindex::type_id_with_cvr;
    cout << "T = " << type_id_with_cvr<T>().pretty_name() << endl;
    cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}

template<typename T>
void f2(T&& param) {
    using boost::typeindex::type_id_with_cvr;
    cout << "T = " << type_id_with_cvr<T>().pretty_name() << endl;
    cout << "param = " << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}

class Widget {

};

vector<Widget> createVec() {
    return {Widget{}};
}

int main()
{
    const int theAnswer = 42;
    auto x = theAnswer;
    auto y = &theAnswer;

    // TD<decltype(x)> xType;
    // TD<decltype(y)> yType;

    // 运行时输出参数类型
    // cout << typeid(x).name() << endl;
    // cout << typeid(y).name() << endl;


    const auto vw = createVec();
    if (!vw.empty()) {
        f(&vw[0]);
    }

    /*
    T = const Widget*
    param = const Widget&

    T = PK6Widget
    param = PK6Widget
    */
    cout << endl;
    cout << "rvalue:" << endl;
    f2(Widget{});
    cout << endl;
    cout << "lvalue:" << endl;
    Widget w;
    f2(w);

    return 0;
}

/*

 */