#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vi>;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define nL "\n"

int main()
{
    int n; cin >> n;
    vector<bool> prime(n + 1, 1);
    prime[0] = prime[1] = false;
    cout << "init" << endl;
    int numprimes = 0;
    rep(i, 2, sz(prime)){
        if(prime[i]){
            numprimes++;
            if(ll(i) * i >= sz(prime)) continue;
            for(int j = i * i; j < sz(prime); j += i){
                prime[j] = false;
            }
        }
    }
    cout << numprimes << "\n";
    
    return 0;
}
