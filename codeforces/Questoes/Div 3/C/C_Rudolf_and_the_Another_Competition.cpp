#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, h; cin >> n >> m >> h;

    vector<vector<int>> arr(n, vector<int> (m));
    vector<vector<ll>> prefix(n, vector<ll> (m+1));
    for (int i = 0;  i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
        }

        sort(arr[i].begin(), arr[i].end());
        ll time = 0;

        for (int j = 1; j <= m; j++){
            time += arr[i][j-1];
            if (time > h) break;
            prefix[i][j] = time + prefix[i][j-1];
        }
    }
    
    vector<tuple<int, ll, int>> ans(n);
    for (int i = 0; i < n; i++){
        int c = 0;
        for (int j = 1; j <= m; j++){
            if (prefix[i][j] != 0) c++;
            else {
                ans[i] = {c, prefix[i][j-1], i};
                break;
            }
            if (j == m) ans[i] = {c, prefix[i][j], i};
        }
    }

    sort(ans.begin(), ans.end(), [&](tuple<int, ll, int> &x, tuple<int, ll, int> &y){
        if (get<0>(x) != get<0>(y)) return get<0>(x) > get<0>(y);
        if (get<1>(x) != get<1> (y)) return get<1>(x) < get<1>(y);
        return get<2>(x) < get<2>(y);
    });

    for (int i = 0; i < n; i++){
        if (get<2>(ans[i]) == 0){
            cout << i+1 << "\n";
            return;
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