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

        vector<vector<int>> mat(n, vector<int> (m));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> mat[i][j];
            }
        }

        vector<pair<ll, int>> sum;
        
        for (int i = 0; i < n; i++){
            ll all = accumulate(mat[i].begin(), mat[i].end(), 0LL);
            sum.push_back({all, i});
        }

        sort(sum.begin(), sum.end(), [&](pair<ll, int> &x, pair<ll, int> &y){
            if (x.first != y.first) return x.first > y.first;
            return x.second < y.second;
        });

        vector<int> arr;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                arr.push_back(mat[sum[i].second][j]);
            }
        }

        ll ans = 0;
        for (int i = 0, j = n*m; i < n*m; i++, j--){
            ans += 1LL*arr[i]*j;
        }

        cout << ans << "\n";
    }
}