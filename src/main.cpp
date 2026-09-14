#include <iostream>
#include <tuple>

int main() {
    // Syntaxe C++17 (Structured bindings)
    auto [a, b] = std::make_pair(1, "C++17 fonctionnel !");
    std::cout << a << ": " << b << std::endl;
    return 0;
}