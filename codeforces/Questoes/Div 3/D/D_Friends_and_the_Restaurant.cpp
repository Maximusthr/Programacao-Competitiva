#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> v(n);
    for (auto &[x, y] : v) cin >> x;
    for (auto &[x, y] : v) cin >> y;

    sort(v.begin(), v.end(), [&](pair<int, int> &x, pair<int, int> &y){
        return (x.second - x.first > y.second - y.first);
    });

    int ans = 0;
    int i = 0, j = n-1;
    while(i < j){
        if (v[i].first + v[j].first <= v[i].second + v[j].second){
            ans++;
            i++;
        }
        j--;
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