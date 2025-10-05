#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    if (n*n - k == 1){
        cout << "NO" << "\n";
        return;
    }

    vector<vector<char>> mat(n, vector<char> (n));
    int qtd = 0;
    bool alter = false;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (qtd < k){
                mat[i][j] = 'U';
                qtd++;
            }
            else {
                if (i != n-1){
                    mat[i][j] = 'D';
                }
                else {
                    if (i == n-1 && j == n-1){
                        mat[i][j] = 'L'; 
                        break;
                    }
                    if (alter) mat[i][j] = 'L';
                    else mat[i][j] = 'R';
                    alter ^= 1;
                }
            }
        }
    }

    cout << "YES" << "\n";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << mat[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}