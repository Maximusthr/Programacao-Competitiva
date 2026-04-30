#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    ll ans = arr.back() - arr[0];

    vector<int> diff;
    for (int i = 0; i < n-1; i++){
        diff.push_back(arr[i+1]-arr[i]);
    }
    sort(diff.begin(), diff.end(), greater<int> ());

    for (int i = 0; i < k-1; i++){
        ans -= diff[i];
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}