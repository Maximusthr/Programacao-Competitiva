#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll n, k; cin >> n >> k;
    
    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    auto ok = [&](ll mid) -> bool {
        ll aux = k;

        for (int i = 1; i <= n; i++){
            if (arr[i] >= mid) continue;
            aux -= (mid - arr[i] + i - 1)/i;
            if (aux < 0) return false;
        }

        return (aux >= 0);
    };

    ll l = 0, r = 3e18;
    while(l < r){
        ll mid = l + (r-l+1)/2;

        if (ok(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}