#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;
const int MAX = 1e6+5;

vector<ll> fat(MAX);

ll bin_pow(ll a, ll b){
    ll x = 1;
    while(b > 0){
        if (b & 1) x = x * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return x;
}

ll comb(ll n, ll x){
    return (fat[n] * bin_pow(fat[n-x], MOD - 2) % MOD) * bin_pow(fat[x], MOD - 2) % MOD;
}

void solve(){
    ll n, a, b, d;
    while(cin >> n >> a >> b >> d){
        cout << (comb(n, a) * (bin_pow(comb(b, d), a) % MOD) % MOD) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    fat[0] = 1;
    fat[1] = 1;
    for (int i = 2; i < MAX; i++){
        fat[i] = (fat[i-1] * i) % MOD;
    }

    solve();
}