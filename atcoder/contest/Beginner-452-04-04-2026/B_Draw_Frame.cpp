#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<char>> mat(n, vector<char> (m, '.'));

    for (int i = 0; i < m; i++){
        mat[0][i] = '#';
        mat[n-1][i] = '#';
    }
    for (int j = 0; j < n; j++){
        mat[j][0] = '#';
        mat[j][m-1] = '#';
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << mat[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}