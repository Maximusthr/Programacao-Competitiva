#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 998244353;
const int MAX = 2e5+5;

vector<ll> fat(MAX);

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int maior = *max_element(arr.begin(), arr.end());
    int freq = 0, seg_best = 0;

    for (int i = 0; i < n; i++){
        if (arr[i] == maior) freq++;
        if (abs(arr[i] - maior) == 1) seg_best++;
    }

    if (freq == 1 && seg_best == 0){
        cout << 0 << "\n";
        return;
    }

    if (freq >= 2){
        cout << fat[n] << "\n";
        return;
    }

    ll ans = 1;
    for (int i = 1; i <= n; i++){
        if (i == seg_best+1) continue;
        ans = (ans * i) % MOD;
    }

    cout << (((fat[n] - ans) % MOD) + MOD) % MOD << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    fat[0] = fat[1] = 1;
    for (int i = 2; i < MAX; i++){
        fat[i] = (i * fat[i-1]) % MOD;
    }

    int t; cin >> t;
    while(t--){
        solve();
    }
}