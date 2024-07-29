#include <iostream>
#include <cassert>


const int ITER = 1000000;
const double diff_dx = 1e-6;
const double EPS = 1e-2;

double x2(double x) {
    return x * x;
}

template<typename F>
double integrate(F& f, double a, double b) {
    double sum = 0;
    double dx = (b - a) / ITER;
    for (int i = 0; i < ITER; i++) {
        sum += f(a + i * dx) * dx;
    }
    return sum;
}

template<typename F>
double differentiate(F &f, double x) {
    return (f(x + diff_dx) - f(x)) / diff_dx;
}

int main() {
    assert(std::abs(integrate(x2, 1, 10) - 333) < EPS);
    auto overx = [](double x) { return 1 / x; };
    assert(std::abs(integrate(overx, 1, 10) - 2.30259) < EPS);
    {
        double res = integrate(overx, -1, 1);
        // std::cout << res << "\n";
    }
    assert(std::abs(differentiate(x2, 5) - 10) < EPS);

    std::cout << "All tests passed" << std::endl;
}
