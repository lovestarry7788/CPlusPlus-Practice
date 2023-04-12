#include <iostream>
#include <string>
#include <any>

int main() {
    std::any a = 1;
    std::cout << std::any_cast<int>(a) << '\n';

    a = std::string("hello, world!");
    std::cout << std::any_cast<std::string>(a) << '\n';

    try {
        std::cout << std::any_cast<int>(a) << '\n';
    }
    catch (const std::bad_any_cast& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
