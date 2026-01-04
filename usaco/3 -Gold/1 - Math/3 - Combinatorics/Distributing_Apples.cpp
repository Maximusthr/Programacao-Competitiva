#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;
const int MAX = 1e7 + 5;

vector<ll> fat;

ll binPow(ll a, ll b){
    ll x = 1;
    while (b > 0){
        if (b & 1) x = x * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return x;
}

ll Comb(ll a, ll b){
    return (fat[a] * binPow(fat[a - b], MOD-2) % MOD) * binPow(fat[b], MOD-2) % MOD;
}

void solve(){
    fat.resize(MAX);
    fat[0] = 1;
    for (int i = 1; i < MAX; i++){
        fat[i] = fat[i-1] * i % MOD;
    }

    ll n, k; cin >> n >> k;
    swap(n, k);

    cout << Comb(n + k - 1, k-1) % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}