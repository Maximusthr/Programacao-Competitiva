#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m; cin >> n >> m;

    char mat[n][m];

    bool ok = true;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
            if (mat[i][j] != 'B' && mat[i][j] != 'W' && mat[i][j] != 'G') ok = false;
        }
    }

    cout << (ok ? "#Black&White" : "#Color") << "\n";

}
