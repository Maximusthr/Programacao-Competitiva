#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    int mat[n][n];
    bool ok = false;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
            if (mat[i][j] == 1) {
                ok = true;
                cout << j+1 << " ";
            }
        }
        if (ok) cout << "\n";
        ok = false;
    }
}
