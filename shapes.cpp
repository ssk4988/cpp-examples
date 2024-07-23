#include <vector>
#include <iostream>


class Shape {
public:
    int x;
    // double area();
};

class Circle : public Shape {
public:
    void print() {
        std::cout << x << "\n";
    }
};


int main() {
    Circle c;
    c.print();
    std::cout << c.x << "\n";
}
