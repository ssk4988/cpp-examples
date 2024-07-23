#include <iostream>

class Z {
public:
    int x = 3;
};

class A : public Z {
public:
    int x = 2;
};

class B {
public:
    int x = 1;
};

class C : public A, public B {
public:
    int x = 0;
};

int main() {
    C c;
    std::cout << c.x << "\n";
    std::cout << c.A::x << "\n";
    std::cout << c.B::x << "\n";
    std::cout << c.Z::x << "\n";
    std::cout << c.A::Z::x << "\n"; 
}
