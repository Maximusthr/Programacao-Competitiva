#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

ll exp (ll a, ll b){
    ll x = 1;

    b %= MOD;

    while(b > 0){
        if (b%2) x = (x % MOD) * (a % MOD) % MOD;
        a = (a % MOD) * (a % MOD) % MOD;
        b >>= 1;
    }

    return x;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    cout << exp((exp(2, m) - 1), n) << "\n";
}