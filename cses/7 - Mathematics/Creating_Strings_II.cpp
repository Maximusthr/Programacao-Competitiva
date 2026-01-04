#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

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
    ll v = (fat[a] * binPow(fat[b], MOD-2) % MOD) * binPow(fat[a-b], MOD-2) % MOD;
    return v;
}

void solve(){
    string s; cin >> s;

    int n = s.size();

    vector<ll> v(26);
    for (int i = 0; i < n; i++){
        v[s[i] - 'a']++;
    }

    ll ans = 1;
    for (int i = 0; i < 26; i++){
        if (v[i] == 0) continue;
        ans = (ans * Comb(n, v[i])) % MOD;
        n -= v[i];
    }

    cout << ans % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    fat.resize(MAX);

    fat[0] = 1;
    for (ll i = 1; i < MAX; i++){
        fat[i] = (fat[i-1] * i) % MOD;
    }

    solve();
}