#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, q; cin >> n >> m >> q;

    vector<vector<int>> mat(n, vector<int> (m, 1));

    while(q--){
        int x, y; cin >> x >> y;

        int sum = 0;
        if (x == 1){
            int cont = 0;
            int i = n-1;
            while (i >= 0 && mat[i][0] == 0) i--;

            for (; i >= 0 && cont < y; i--, cont++){
                for (int j = 0; j < m; j++){
                    if (mat[i][j] == 0) break;
                    sum++;
                    mat[i][j] = 0;
                }
            }
            cout << sum << "\n";
        }
        else {
            int cont = 0;
            int j = m-1;
            while(j >= 0 && mat[0][j] == 0) j--;

            for (; j >= 0 && cont < y; j--, cont++){
                for (int i = 0; i < n; i++){
                    if (mat[i][j] == 0) break;
                    sum++;
                    mat[i][j] = 0;
                }
            }
            cout << sum << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}