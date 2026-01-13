#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve

void solve(){
    ll s, k, m; cin >> s >> k >> m;

    ll giro = m - (m/k * k);

    if (k >= s){
        // sempre s 
        cout << max(0ll, s - giro) << "\n";
    }
    else {
        ll v = (m / k) % 2;
        
        if (v) cout << max(0ll, k - giro) << "\n";
        else cout << max(0ll, s - giro) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}