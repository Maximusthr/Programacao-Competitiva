#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, c, d; cin >> n >> c >> d;

    int menor = INF;
    map<int, int> mapa;
    for (int i = 0; i < n * n; i++){
        int x; cin >> x;
        menor = min(menor, x);
        mapa[x]++;
    }

    vector<vector<int>> mat(n, vector<int> (n));
    mat[0][0] = menor;
    
    map<int, int> aux;
    aux[menor]++;
    for (int i = 1; i < n; i++){
        mat[0][i] = mat[0][i-1] + d;
        aux[mat[0][i]]++;
    }
    for (int i = 1; i < n; i++){
        for (int j = 0; j < n; j++){
            mat[i][j] += mat[i-1][j] + c;
            aux[mat[i][j]]++;
        }
    }

    for (auto [x, y] : aux){
        if (mapa[x] != y){
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}