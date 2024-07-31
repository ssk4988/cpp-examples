#include <iostream>
#include <thread>
#include <vector>
#include <numeric>

using ll = long long;
ll counter = 0;
void add(ll x) {
    for(ll i = 0; i < x; i++) {
        counter++;
    }
}

int main() {
    int n; std::cin >> n;
    std::vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    ll sum = std::accumulate(a.begin(), a.end(), 0LL);
    std::vector<std::thread> threads;
    for(ll x : a) {
        threads.push_back(std::thread(add, x));
    }
    for(auto& t : threads) {
        std::cout << t.get_id() << std::endl;
        t.join();
    }
    std::cout << counter << std::endl;
}
