#include <iostream>

class A {
public:
    int x = 2;
};

class B {
public:
    int x = 1;
};

class C : public A, public B {

};

int main() {
    C c;
    std::cout << c.A::x << "\n";
}
