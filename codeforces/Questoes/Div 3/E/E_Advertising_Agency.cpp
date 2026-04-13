#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9 + 7;

const int MAX = 1005;   
vector<ll> fat(MAX);

ll binpow(ll a, ll b){
    ll x = 1;
    while(b > 0){
        if (b & 1) x = x * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return x % MOD;
}

ll Comb(ll n, ll x){
    return (fat[n] * binpow(fat[n-x], MOD-2) % MOD) * binpow(fat[x], MOD-2) % MOD;
}

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    map<int, int> mapa;
    for (auto &i : arr) {
        cin >> i;
        mapa[i]++;
    }

    sort(arr.begin(), arr.end(), greater<int>());
    map<int, int> freq;
    for (int i = 0; i < k; i++){
        freq[arr[i]]++;
    }

    ll ans = 0;
    for (auto [x, y] : freq){
        if (mapa[x] == y) continue;
        ans = (ans + Comb(mapa[x], y)) % MOD;
    }

    if (ans == 0) ans++;
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    fat[0] = 1;
    for (int i = 1; i < MAX; i++){
        fat[i] = (i * fat[i-1]) % MOD;
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}