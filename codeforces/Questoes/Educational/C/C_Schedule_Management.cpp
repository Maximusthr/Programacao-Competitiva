#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;
    
    vector<ll> arr(m);
    vector<vector<ll>> val(n+1);
    for (int i = 0; i < m; i++){
        cin >> arr[i];
        val[arr[i]].push_back(i);
    }

    auto ok = [&](ll mid) -> bool {
        vector<ll> tempo(n+1);

        ll extra = 0;
        for (int i = 1; i <= n; i++){
            tempo[i] += min(mid, (ll)val[i].size());
            extra += max(0ll, (ll)val[i].size() - mid);
        }

        for (int i = 1; i <= n; i++){
            extra -= (mid - tempo[i])/2;
        }

        return (extra <= 0);
    };

    ll l = 0, r = 6e5;
    while(l < r){
        ll mid = l + (r-l)/2;

        if (ok(mid)) r = mid;
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