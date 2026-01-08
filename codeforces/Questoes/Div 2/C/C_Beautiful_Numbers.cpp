#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

vector<ll> fact;

ll binPow(ll a, ll b){
    ll x = 1;
    while(b > 0){
        if (b & 1) x = x * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return x;
}

ll Comb(ll n, ll i){
    return fact[n] * binPow(fact[n-i], MOD - 2) % MOD * binPow(fact[i], MOD - 2) % MOD;
}

int a, b, n;

bool digits(ll sum){
    while (sum > 0){
        int x = sum % 10;
        if (x != a && x != b){
            return false;
        }
        sum /= 10;
    }
    return true;
}

void solve(){
    cin >> a >> b >> n;

    ll ans = 0;
    for (int i = 0; i <= n; i++){
        ll sum = a * i + b * (n-i);
        
        if (digits(sum)) ans = (ans + Comb(n, i)) % MOD;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    fact.resize(MAX);
    fact[0] = 1;
    for (int i = 1; i < MAX; i++){
        fact[i] = fact[i-1] * i % MOD;
    }

    solve();
}