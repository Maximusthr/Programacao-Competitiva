#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve
const int MOD = 1e9+7;

ll binpow(ll a, ll b){
    ll x = 1;
    while(b > 0){
        if (b & 1) x = x * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return x;
}

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        arr[i] = x;
        freq[x]++;
    }

    ll p = 1;
    for (auto [x, y] : freq){
        p = p * binpow(2, y-1) % MOD;
    }

    ll k = 0;
    if (freq.count(-1)){
        for (auto [x, y] : freq){
            if (x > 0 && freq.count(x-1)){
                k++;
            }
        }
    }

    cout << p * (k+1)  % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        solve();
    }
}