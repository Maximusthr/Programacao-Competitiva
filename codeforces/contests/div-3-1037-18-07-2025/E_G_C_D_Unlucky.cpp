#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> a(n);
    vector<ll> b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    vector<ll> l(n);
    for (int i = 0; i < n; i++){
        l[i] = lcm(a[i], b[i]);
    }
    
    ll g = 0;
    for (int i = 0; i < n; i++){
        g = __gcd(l[i], g);
        if (g != a[i]){
            cout << "NO" << "\n";
            return;
        }
    }

    g = 0;
    for (int i = n-1; i >= 0; i--){
        g = __gcd(l[i], g);
        if (g != b[i]){
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}