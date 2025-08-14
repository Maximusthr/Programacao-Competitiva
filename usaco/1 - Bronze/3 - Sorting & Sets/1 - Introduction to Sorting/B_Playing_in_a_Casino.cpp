#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;

        vector<vector<int>> arr(n, vector<int> (m));

        for (auto &i : arr) for (auto &j : i) cin >> j;

        vector<vector<int>> new_arr(m, vector<int> (n));

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                new_arr[i][j] = arr[j][i];
            }
        }
        for (int i = 0; i < m; i++) sort(new_arr[i].begin(), new_arr[i].end(), greater<int>());
        
        ll ans = 0;
        for (int i = 0; i < m; i++){
            ll sum = n-1;
            for (int j = 0; j < n; j++){
                ans += new_arr[i][j] * (sum - j);
                sum--;
            }
        }
        cout << ans << "\n";
    }
}
