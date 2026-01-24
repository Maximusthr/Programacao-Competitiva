#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, h, l; cin >> n >> h >> l;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());
    vector<int> r, c;
    vector<pair<bool, bool>> tem;
    for (int i = 0; i < n; i++){
        bool ok1 = false, ok2 = false;
        if (arr[i] <= h){
            r.push_back(arr[i]);
            ok1 = true;
        }
        if (arr[i] <= l){
            c.push_back(arr[i]);
            ok2 = true;
        }

        tem.push_back({ok1, ok2});
    }

    int row = 0, col = 0;
    for (int i = 0; i < tem.size(); i++){
        if (!tem[i].first && tem[i].second) col++;
        else if (tem[i].first && !tem[i].second) row++;
    }

    for (int i = 0; i < tem.size(); i++){
        if (tem[i].first && tem[i].second){
            if (row < col) row++;
            else col++;
        }
    }
    cout << min(col, row) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}