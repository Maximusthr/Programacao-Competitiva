#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, m, k; cin >> n >> m >> k;
    
    ll l = 1, r = m;
    while (l < r){
        ll mid = l + (r-l+1)/2;

        ll left = 0, right = 0;

        if (mid <= k){
            left += mid * (mid + 1)/2 + (k - mid);
        }
        else {
            left += k * (mid + mid - k + 1)/2;
        }

        if (mid <= (n-k)){
            right += mid * (mid + 1)/2 + (n - k - mid + 1);
        }
        else {
            right += (n - k + 1) * (mid + mid - n + k)/2;
        }

        if (right + left - mid <= m){
            l = mid;
        }
        else r = mid - 1;
    }

    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
        solve();
    // }
}