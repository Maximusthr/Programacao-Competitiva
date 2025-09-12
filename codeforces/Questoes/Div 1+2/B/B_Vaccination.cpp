#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, k, d, w; cin >> n >> k >> d >> w;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    auto ok = [&](ll mid) -> bool {
        ll pack = mid;

        bool acabou = false;
        for (int i = 0; i < n; ){
            int todo = k;
            ll aux = arr[i] + d + w;

            while(i < n && todo > 0 && aux >= arr[i]){
                todo--;
                i++;
            }
            pack--;
        }
        
        return (pack >= 0);
    };

    ll l = (n+k-1)/k, r = 2e6+5;
    while (l < r){
        ll mid = l + (r-l)/2;

        if (ok(mid)){
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