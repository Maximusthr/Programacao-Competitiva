#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<vector<char>> mat(n, vector<char> (n));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            char c = max({mat[j][n-i-1], mat[i][j], mat[n-j-1][i], mat[n-i-1][n-j-1]});

            ans += (c - mat[j][n-i-1]) + (c - mat[i][j]) + (c - mat[n-j-1][i]) + (c - mat[n-i-1][n-j-1]);

            mat[i][j] = c;
            mat[n-i-1][n-j-1] = c;
            mat[j][n-i-1] = c;  
            mat[n-j-1][i] = c;
        }
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