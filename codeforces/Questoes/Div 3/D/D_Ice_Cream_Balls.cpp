#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n; cin >> n;

    ll l = 1, r = 2e9;
    while(l < r){
        ll mid = l + (r-l+1)/2;

        if (mid * (mid-1)/2 <= n) l = mid;
        else r = mid - 1;
    }

    cout << l + n - (l * (l-1)/2) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}