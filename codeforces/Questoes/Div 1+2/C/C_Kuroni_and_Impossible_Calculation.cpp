#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    if (n > m){
        cout << 0 << "\n";
        return;
    }

    ll ans = 1;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            ans %= m;
            ll v = abs(arr[i] - arr[j]) % m;
            ans = (ans * v) % m;
        }
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}