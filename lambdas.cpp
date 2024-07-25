#include <iostream>
#include <vector>
#include <algorithm>

auto g(auto f) {
    return f();
}

int main() {
    int x = 3;
    auto f = [x]() mutable {
        return ++x; };
    x = 2;
    std::cout << g(f) << "\n";
    // x = 4;

    std::vector<int> v{1, 2, 3, 4, 5, 4, 3, 2, 1};
    auto it = std::find(v.begin(), v.end(), 3);
    std::cout << (it - v.begin()) << "\n";
    it = std::find_if(v.begin(), v.end(), [](int y) { return y * 2 == 8; });
    std::cout << (it - v.begin()) << "\n";
}
