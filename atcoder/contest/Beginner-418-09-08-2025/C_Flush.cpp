#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;

    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<ll> prefix(n+1);
    for (int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1] + arr[i];
    }

    while(q--){
        int x; cin >> x;

        if (x == 1){
            cout << 1 << "\n";
            continue;
        }

        if (x > arr[n]){
            cout << -1 << "\n";
            continue;
        }

        ll num = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

        ll ans = (n-num+1)*(x-1) + prefix[num-1];
        cout << ans + 1 << "\n";
        // cout << prefix[num] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // int t; cin >> t;
    // while(t--){
    solve();
    // }
}