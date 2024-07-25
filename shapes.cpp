#include <vector>
#include <iostream>

class Shape
{
public:
    Shape() {
        std::cout << "Creating shape\n";
    }
    virtual double area()
    {
        return 0;
    }
    ~Shape() {
        std::cout << "shape deletion\n";
    }
};

class Circle : public Shape
{
    double radius;

public:
    Circle(double radius) : radius(radius) {
        std::cout << "creating circle of radius " << radius << "\n";
    }
    double area() override
    {
        return radius * radius * 3.14;
    }
};

class Square : public Shape
{
    double side;

public:
    Square(double side) : side(side) {
        std::cout << "creating square of side length " << side << "\n";
    }
    double area()
    {
        return side * side;
    }
};

int main()
{
    {
        Circle x = 5;
        std::cout << x.area() << "\n";
        std::cout << x.Shape::area() << "\n";
    }
    Circle c = 5;
    Square s = 10;
    std::vector<Shape *> v = {&c, &s};
    std::cout << "before array\n";
    std::vector<Shape> v1 = {c, s};
    Shape *a[] = {&c, &s};
    std::cout << "printing now\n";
    for (Shape* x : v)
    {
        std::cout << x->area() << "\n";
    }
    for (Shape* x : a)
    {
        Shape &y = *x;
        std::cout << x->area() << " " << y.area() << "\n";
    }
    for (auto &x : v1) {
        std::cout << x.area() << "\n";
    }
}
