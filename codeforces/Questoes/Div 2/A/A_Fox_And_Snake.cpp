#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n, m; cin >> n >> m;

    string mat[n][m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            mat[i][j] = '#';
        }
    }

    bool foi = false;
    for (int i = 1; i < n; i += 2){
        for (int j = 0; j < m; j++){
            if (!foi) {
                if (j == m-1) break;
                else mat[i][j] = '.';
            }
            else {
                if (j == 0) continue;
                else mat[i][j] = '.';
            }
        }
        foi = !foi;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << mat[i][j];
        }
        cout << "\n";
    }
}
