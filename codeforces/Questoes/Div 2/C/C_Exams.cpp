#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> arr(n);
    for (auto &i : arr) cin >> i.first >> i.second;

    sort(arr.begin(), arr.end(), [&](pair<int, int> x, pair<int, int> y){
        if (x.first != y.first) return x.first < y.first;
        return x.second < y.second;
    });

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (arr[i].second >= ans) ans = arr[i].second;
        else ans = arr[i].first;
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}