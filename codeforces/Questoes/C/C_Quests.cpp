#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    for (int i = 1; i < n; i++){
        a[i] = a[i] + a[i-1];
    }

    ll ans = 0;
    int val = 0;
    for (int i = 0; i < n; i++){
        if (k - i - 1 < 0) break;
        val = max(val, b[i]);
        ll temp = a[i] + val * (k - i - 1);
        ans = max(ans, temp);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}
