#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    auto ok = [&](ll mid){
        ll sum = arr[0]  + mid;
        for (int i = 1; i < n; i++){
            ll v = arr[i] * 100;

            if (1ll*sum*k < v) return false;
            
            sum += arr[i];
        }
        return true;
    };

    ll l = 0, r = 2e15;
    while (l < r){
        ll mid = l + (r-l)/2;

        if(ok(mid)){
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