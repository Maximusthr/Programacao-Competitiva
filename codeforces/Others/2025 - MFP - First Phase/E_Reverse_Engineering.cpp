#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> mat(n, vector<int> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
            if (mat[i][j] % 2 == 1 && (i + j) % 2 == 0){
                mat[i][j]++;
            }
            else if (mat[i][j] % 2 == 0 && (i + j) % 2){
                mat[i][j]++;
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << mat[i][j] << " \n"[j == m-1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}