#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    if (n <= 2){
        cout << -1 << "\n";
        return;
    }

    sort(arr.begin(), arr.end());

    ll sum = accumulate(arr.begin(), arr.end(), 0ll);

    if (arr[n/2] < sum/(n*2)){
        cout << 0 << "\n";
        return;
    }

    cout << max(0ll, 1ll*(n*2 * arr[n/2] - sum + 1)) << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}