#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+5;
const int MOD = 1e9 + 7;

ll modPow(ll a, ll b){
    a %= MOD;

    ll x = 1;
    while(b > 0){
        if (b % 2) x = a * x % MOD;
        b >>= 1;
        a = a * a % MOD;
    }

    return x;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    vector<ll> fact(MAX);
    fact[0] = 1;
    for (int i = 1; i < MAX; i++){
        fact[i] = fact[i-1] * i % MOD;
    }

    vector<ll> inv(MAX);
    inv[MAX-1] = modPow(fact[MAX-1], MOD - 2);

    for (int i = MAX-1; i >= 1; i--){
        inv[i-1] = inv[i] * i % MOD;
    }


    auto compute = [&](ll n, ll k) -> ll {
        return (fact[n] * inv[k] % MOD * inv[n-k] % MOD);
    };

    int q; cin >> q;

    while(q--){
        int a, b; cin >> a >> b;

        cout << compute(a, b) << "\n";
    }
}