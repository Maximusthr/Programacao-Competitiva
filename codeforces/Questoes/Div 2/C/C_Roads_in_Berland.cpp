#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<ll>> mat(n, vector<ll>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    ll last = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            last += mat[i][j];
        }
    }

    last /= 2;

    int k; cin >> k;
    while(k--){
        int u, v, w; cin >> u >> v >> w;
        u--, v--;

        ll wl = mat[u][v];

        mat[u][v] = w;
        mat[v][u] = w;

        array<int, 2> no = {u, v};
        
        for (int kk = 0; kk < 2; kk++){
            int k = no[kk];
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        ll sum = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                sum += mat[i][j];
            }
        }

        sum /= 2;

        if (sum > last){
            mat[u][v] = wl;
            mat[v][u] = wl;
            for (int kk = 0; kk < 2; kk++){
                int k = no[kk];
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++){
                        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                    }
                }
            }
            sum = last;
        }

        cout << sum << " ";
        last = sum;
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}