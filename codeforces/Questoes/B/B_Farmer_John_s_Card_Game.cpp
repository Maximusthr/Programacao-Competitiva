#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;

        vector<vector<int>> mat(n, vector<int> (m));
        vector<pair<int, int>> pares;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
                pares.push_back({mat[i][j], i});
            }
        }

        sort(pares.begin(), pares.end(), [&](pair<int, int> &x, pair<int, int> &y){
            return x.first < y.first;
        });

        vector<int> aux;
        for (int i = 0; i < n; i++) aux.push_back(pares[i].second);

        bool ok = true;
        for (int i = 0, j = 0; i < n*m; i++, j++){
            if (j == n) j = 0;
            if (pares[i].second != aux[j]) {
                ok = false;
                break;
            }
        }

        if (ok){
            for (int i = 0; i < n; i++){
                cout << aux[i] + 1 << " ";
            }
            cout << "\n";
        }
        else cout << -1 << "\n";
    }
}
