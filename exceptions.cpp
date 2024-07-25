#include <stdexcept>
#include <iostream>


void f(int a) {
    switch(a) {
        case 1:
            throw std::runtime_error("bruh 1");
        case 2:
            throw std::runtime_error("bruh 2");
    }
}

void g(int a) {
    return f(a);
}

int main() {
    try {
        g(1);
    } catch (std::runtime_error &e) {
        std::cout << e.what() << "\n";
    }
    try {
        f(2);
    } catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }
}
