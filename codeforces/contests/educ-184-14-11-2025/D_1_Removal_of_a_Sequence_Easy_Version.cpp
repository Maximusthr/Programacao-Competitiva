// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int x; cin >> x;
    ll y, k; cin >> y >> k;

    ll N = 1e12;

    for (int i = 0; i < x; i++){
        N -= N/y;
    }

    if (N < k){
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < x; i++){
        ll l = 0, r = 1e12;
        while(l < r){
            ll mid = l + (r-l)/2;
    
            if (mid - mid/y >= k) r = mid;
            else l = mid + 1;
        }
        k = l;
    }

    cout << k << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}