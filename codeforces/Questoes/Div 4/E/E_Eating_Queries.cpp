#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<int> ());

    vector<int> prefix(n+2);
    for (int i = 0; i < n; i++){
        prefix[i+1] = prefix[i] + arr[i];
    }
    prefix[n+1] = INF;

    while(q--){
        int x; cin >> x;

        int v = lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin();

        if (v != n+1) cout << v << "\n";
        else cout << -1 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}