// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> arr(n);
    for (auto &i : arr) cin >> i.first >> i.second;

    double ans = 0;
    for (int i = n-1; i >= 0; i--){
        ans = max(ans, arr[i].first + ans * (1 - arr[i].second/100.0));
    }

    cout << fixed << setprecision(10) << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}