#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll a, b, k; cin >> a >> b >> k;

    if ((k >= a && k >= b) || (a == b)){
        cout << 1 << "\n";
        return;
    }

    ll val = __gcd(a, b);
    if (a/val <= k && b/val <= k){
        cout << 1 << "\n";
        return;
    }

    cout << 2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}