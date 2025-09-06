#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, w; cin >> n >> w;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    auto ok = [&](ll mid) -> bool{
        ll v = 0;
        for (int i = 0; i < n; i++){
            if (mid >= arr[i]) v += mid-arr[i];
            if (v > w){
                return false;
            }
        }

        return v <= w;
    };

    ll l = 1, r = 1e15+5;
    while(l < r){
        ll mid = l + (r-l+1)/2;

        if(ok(mid)){
            l = mid;
        }
        else r = mid-1;
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