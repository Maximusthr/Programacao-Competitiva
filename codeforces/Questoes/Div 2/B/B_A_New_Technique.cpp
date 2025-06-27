#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int> (m+1));
    vector<int> id(n*m+1);

    for (int i = 0; i < n; i++){
        for (int j = 0; j <= m; j++){
            if (j == 0) {
                matrix[i][j] = i;
                continue;
            }
            cin >> matrix[i][j];
            id[matrix[i][j]] = matrix[i][0];
        }
    }

    vector<vector<int>> colunas(m, vector<int> (n));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> colunas[i][j];
        }
    }

    vector<int> seq;
    for (int i = 0; i < n; i++){
        seq.push_back(id[colunas[0][i]]);
    }

    for (int i = 0; i < n; i++){
        for (int j = 1; j <= m; j++){
            cout << matrix[seq[i]][j] << " ";
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