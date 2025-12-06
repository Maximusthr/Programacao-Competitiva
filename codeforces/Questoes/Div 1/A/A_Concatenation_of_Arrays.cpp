#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin(), arr.end(), [&](pair<int, int> &x, pair<int, int> &y){
        return (x.first + x.second) < (y.first + y.second);
    });

    for (auto &i : arr) cout << i.first << " " << i.second << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}