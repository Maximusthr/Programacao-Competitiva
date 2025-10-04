#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> mat(n, vector<int> (n));

    int v = n*n - 1;

    int aux = n-1, i = 0, j = 0, i_ant = 0, j_ant = 0;
    while (v > 0){
        i = i_ant, j = j_ant;

        // f_c
        for (; j < aux; j++){
            mat[i][j] = v--;
        }
        
        
        // l_r
        for (; i < aux; i++){
            mat[i][j] = v--;
        }
        
        // l_c
        for (; j > n-aux-1; j--){
            mat[i][j] = v--;
        }

        // f_r
        for (; i > n-aux-1; i--){
            mat[i][j] = v--;
        }

        aux--;
        i_ant++, j_ant++;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << mat[i][j] << " \n"[j == n-1];
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