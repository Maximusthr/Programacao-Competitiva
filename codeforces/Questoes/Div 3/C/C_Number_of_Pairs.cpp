#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, l, r; cin >> n >> l >> r;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    
    ll ans = 0;
    for (int i = 0; i < n; i++){
        auto lll = lower_bound(arr.begin(), arr.end(), l - arr[i]) - arr.begin();
        auto rr = upper_bound(arr.begin(), arr.end(), r - arr[i]) - arr.begin();

        ans += rr - lll;

        if (2 * arr[i] >= l && 2 * arr[i] <= r) ans--;
    }

    cout << ans/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}