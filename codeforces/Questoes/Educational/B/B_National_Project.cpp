#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, g, b; cin >> n >> g >> b;

    ll alfa = (n+1)/2;
    ll a = (alfa+g-1)/g;

    ll beta = (a * g);
    ll exc = beta - alfa;

    cout << max(n, b * (a - 1) + beta - exc) << "\n"; 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}