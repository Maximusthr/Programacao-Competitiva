#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, k, m; cin >> n >> k >> m;

    if (k > m){
        cout << "NO" << "\n";
        return;
    }

    vector<ll> ans(n);
    int div = m/k;

    int wind = 0;
    int falta = 0;
    bool flag = false;
    for (int i = 0; i < n; i++){
        wind++;

        if (flag){
            ans[i] = div;
            continue;
        }

        if (wind == k){
            ans[i] = m - falta;
            flag = true;
        }
        else {
            ans[i] = div;
            falta += div;
        }
    }

    cout << "YES" << "\n";
    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}