#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    ll l = 0, r = 2e18;
    while (l < r){
        ll mid = l + (r-l)/2;

        if (k <= n * (mid*(m/(mid+1)) + (m % (mid+1)))){
            r = mid;
        }
        else l = mid + 1;
    }
    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}