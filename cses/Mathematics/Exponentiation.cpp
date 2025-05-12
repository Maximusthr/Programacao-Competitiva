#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

ll exp(ll a, ll b){
    ll x = 1;

    while(b > 0){
        if (b % 2 == 1) x = (x % MOD) * (a % MOD);
        b /= 2;
        a = (a % MOD) * (a % MOD);
    }

    return x % MOD;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        ll a, b, c; cin >> a >> b >> c;

        cout << exp(a % MOD, exp(b % MOD, c % MOD)) << "\n";
    }
}
