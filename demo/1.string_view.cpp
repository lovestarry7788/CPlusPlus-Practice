#include <iostream>
#include <string_view>

void print(std::string_view str) {
    std::cout << "Length: " << str.length() << '\n';
    std::cout << "Data: " << str.data() << '\n';
}

int main() {
    std::string str = "hello, world!";
    std::string_view view(str);
    print(view);
    return 0;
}
