#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, m; cin >> n >> m;

    if (m-n == 1){
        cout << "NO" << "\n";
        return;
    }

    for (ll i = n + n; i < m; i += n){
        if (i % n == 0 && m % i != 0){
            cout << "YES" << "\n";
            return;
        }
    }
    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}