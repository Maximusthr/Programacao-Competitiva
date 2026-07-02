#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    int ans = INF;
    int l = 0, r = 1;
    sort(arr.begin(), arr.end());
    while (r < n){
        while(r < n && arr[r] - arr[r-1] <= k){
            r++;
        }
        ans = min(ans, n - r + l);
        while(r < n && arr[r] - arr[r-1] > k){
            l = r;
            r++;
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