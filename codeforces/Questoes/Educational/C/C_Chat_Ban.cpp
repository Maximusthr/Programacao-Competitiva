#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll k, x; cin >> k >> x;

    ll l = 0, r = 2 * k - 1;
    while(l < r){
        ll mid = l + (r-l+1)/2;

        ll sum = 0;

        if (mid <= k){
            sum = mid * (mid + 1)/2;
        }
        else if (mid > k){
            sum = k * (k + 1)/2;
            ll sobra = (2 * k - 1) - mid;
            sobra = sobra * (sobra + 1)/2;

            sum += (k * (k - 1)/2) - sobra;
        }

        if (sum <= x) l = mid;
        else r = mid - 1;
    }    
    if (l <= k){
        ll v = l * (l + 1)/2;
        if (v < x && l != (2 * k - 1)) l++;
    }
    else {
        ll v = k * (k + 1)/2;
        ll sobra = (2 * k - 1) - l;
        sobra = sobra * (sobra + 1)/2;
        v += (k * (k - 1)/2) - sobra;

        if (v < x && l != (2 * k - 1)) l++;
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