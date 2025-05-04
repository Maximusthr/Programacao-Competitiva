#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll k, n; 
vector<ll> arr;

bool ok (ll mid){
    ll slots = mid * k;
    for (int i = 0; i < n; i++){
        slots -= min(mid, arr[i]);
    }
    return slots <= 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> k >> n;
    arr.resize(n);
    for (auto &i : arr) cin >> i;

    ll l = 0, r = 5e10+10;
    ll ans = 0;
    while (l <= r){
        ll mid = l + (r-l)/2;
        if (ok(mid)){
            ans = mid;
            l = mid+1;
        }
        else r = mid-1;
    }

    cout << ans << "\n";
}
