#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> mat(2, vector<int> (n+1));
    for (int i = 0; i < 2; i++){
        for (int j = 1; j <= n; j++){
            cin >> mat[i][j];
        }
    }   

    vector<int> suffix(n+2);
    vector<int> prefix(n+2);

    mat[0][1] = mat[1][n] = 0;

    for (int i = n; i >= 1; i--){
        suffix[i] += suffix[i+1] + mat[0][i];
    }
    for (int i = 1; i <= n; i++){
        prefix[i] += prefix[i-1] + mat[1][i];
    }

    int ans = INF;
    for (int i = 1; i <= n; i++){
        ans = min(ans, max(suffix[i+1], prefix[i-1]));
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