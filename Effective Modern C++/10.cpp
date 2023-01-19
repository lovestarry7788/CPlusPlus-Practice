//
// Created by 刘智杰 on 2023/1/19.
//
// 使用 enum class 而非 enum
// enum 可能污染外部作用域，而 enum class 不会

#include <iostream>
#include <tuple>
#include <array>

using namespace std;

enum class UserInfoFields {uiName, uiEmail, uiReputation};

template<typename E>
constexpr auto toUType(E enumerator) noexcept
{
    return static_cast<underlying_type_t<E>>(enumerator);
}

int main() {
    /*
    enum Color {black, white, red};
    auto white = false;
    */
    enum class Color {black, white, red};
    Color c = Color::red;
    if (static_cast<double>(c) < 14.5) {

    }

    /*
    enum class 可前置声明，enum 不可以
    */

    using UserInfo = tuple<string,string,size_t>;
    UserInfo uInfo;
    // UserInfoFields uInfo;
    // auto val = get<UserInfoFields::uiEmail>(uInfo);
    // auto val = get<static_cast<size_t>(UserInfoFields::uiEmail)>(uInfo);
    auto val = get<toUType(UserInfoFields::uiEmail)>(uInfo);
    return 0;
}