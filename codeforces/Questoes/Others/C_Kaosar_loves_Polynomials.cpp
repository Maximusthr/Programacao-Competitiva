#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b){
    ll x = 1;
    a %= MOD;
    while(b > 0){
        if (b&1) x = a * x % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return x;
}

void solve(){
    int k, n; cin >> k >> n;
    vector<int> arr(n+1);
    for (auto &i : arr) {
        cin >> i;
    }

    ll sum = accumulate(arr.begin(), arr.end(), 0ll);

    sum %= MOD;
    sum = (sum + MOD) % MOD;

    ll v = binpow(sum, k);

    cout << v << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}