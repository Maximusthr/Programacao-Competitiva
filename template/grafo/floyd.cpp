#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n;
    vector<vector<int>> g(n, vector<int> (n, INF));
    for (int i = 0; i < n; i++){
        g[i][i] = 0;
    }

    // ciclo negativo no grafo:

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int t = 0; t < n; t++){
                if (g[i][t] < INF && g[t][j] < INF && g[t][t] < 0){
                    g[i][j] = -INF;
                }    
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}