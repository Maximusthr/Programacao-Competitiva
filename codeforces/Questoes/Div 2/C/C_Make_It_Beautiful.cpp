#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    ll k; cin >> k;

    ll ans = 0;
    vector<pair<ll, int>> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = __builtin_popcountll(arr[i].first);
        ans += arr[i].second;
    }

    for (ll bits = 0; bits < 61; bits++){
        for (int i = 0; i < n; i++){
            if (!(arr[i].first & (1ll << bits))){
                ll talvez = (1ll << bits);
                arr[i].first |= (1ll << bits);
                if (talvez > k) break;
                else {
                    k -= talvez;
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}