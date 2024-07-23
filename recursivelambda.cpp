#include <bits/stdc++.h>
using namespace std;

int main() {

    auto rec1 = [&](auto self, int n) -> int {
        if (n == 0) return 0;
        return n + self(self, n-1);
    };
    // cout << << endl;
    // cout << rec1(5, 5) << endl;

    return 0;
}
