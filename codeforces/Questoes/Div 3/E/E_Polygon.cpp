#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<string> mat(n);
    for (auto &i : mat) cin >> i;

    bool ok = true;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (mat[i][j] == '1'){
                bool row = false, column = false;
                if (i+1 == n || j+1 == n) continue;

                for (int k = j+1; k < n; k++){
                    if (mat[i][k] == '1'){
                        row = true;
                        break;
                    }
                    else break;
                }
                for (int k = i+1; k < n; k++){
                    if (mat[k][j] == '1'){
                        column = true;
                        break;
                    } 
                    else break;
                }

                if (!row && !column) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) break;
    }

    if (ok) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}