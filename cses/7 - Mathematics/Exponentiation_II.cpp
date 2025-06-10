#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1e9+7;
const ll MOD2 = 1e9+6;

ll exp(ll a, ll b, ll mod){
    a %= mod;
    ll x = 1;

    while(b > 0){
        if (b % 2 == 1) x = x * a % mod;
        b /= 2;
        a = a * a % mod;
    }

    return x % mod;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        ll a, b, c; cin >> a >> b >> c;

        ll b_c = exp(b, c, MOD2);

        cout << exp(a, b_c, MOD) << "\n";
    }
}
