#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<pair<int, int>> ans;
    int talvez = -1;
    for (int i = 0; i < n; i++){
        if (arr[i] != arr[0]){
            ans.push_back({1, i+1});
            talvez = i;
        }
    }

    for (int i = 1; i < n; i++){
        if (arr[i] == arr[0]){
            ans.push_back({talvez+1, i+1});
        }
    }

    if (talvez == -1){
        cout << "NO" << "\n";
    }
    else {
        cout << "YES" << "\n";
        for (int i = 0; i < n-1; i++){
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}