#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;
    
    int mat[n][3];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            cin >> mat[i][j];
        }
    }
    
    int x = 0;

    bool ok = true;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < n; j++){
            x += mat[j][i];
        }
        if (x != 0) {
            ok = false;
            break;
        }
    }
    
    if (!ok) cout << "NO" << "\n";
    else cout << "YES" << "\n";
}
