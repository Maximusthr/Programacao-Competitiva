#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> mat(n, vector<int> (n));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
    
    if (n == 1){
        cout << "YES" << "\n";
        cout << n << "\n";
        return;
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        if (i+1 == n) ans[i] = mat[i][i-1];
        else ans[i] = mat[i][i+1];

        for (int j = 0; j < n; j++){
            if (i == j) continue;
            ans[i] &= mat[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            if (mat[i][j] != (ans[i] | ans[j])) {
                cout << "NO" << "\n";
                return;
            }
        }
    }

    cout << "YES" << "\n";
    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}