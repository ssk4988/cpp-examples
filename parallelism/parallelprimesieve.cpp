#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)

using ll = long long;

int n;
vector<bool> prime;
vector<mutex> mutexes;
atomic<int> numprimes{0};
const int LOWER_BOUND = 7000;

void sieveloop(int p)
{
    for (int i = p * p; i < sz(prime); i += p)
    {
        mutexes[i].lock();
        prime[i] = false;
        mutexes[i].unlock();
    }
}

int main()
{
    cin >> n;
    prime.assign(n + 1, 1);
    mutexes = vector<mutex>(n + 1);
    auto num_threads = thread::hardware_concurrency();
    cout << "Number of possible threads: " << num_threads << endl;
    prime[0] = prime[1] = false;
    rep(i, 2, min(LOWER_BOUND, sz(prime)))
    {
        bool isprime = false;
        mutexes[i].lock();
        isprime = prime[i];
        mutexes[i].unlock();
        if (isprime)
        {
            numprimes++;
            if (ll(i)*i >= sz(prime))
                continue;
            sieveloop(i);
        }
    }
    cout << "did lower bound" << endl;
    vector<thread> threads;
    rep(i, LOWER_BOUND, sz(prime))
    {
        bool isprime = false;
        mutexes[i].lock();
        isprime = prime[i];
        mutexes[i].unlock();
        if (isprime)
        {
            numprimes++;
            if (ll(i)*i >= sz(prime))
                continue;
            threads.emplace_back(sieveloop, i);
            if (sz(threads) >= num_threads)
            {
                for (auto &t : threads)
                {
                    t.join();
                }
                threads.clear();
            }
        }
    }
    for (auto &t : threads)
    {
        t.join();
    }
    threads.clear();
    cout << numprimes << "\n";

    return 0;
}
