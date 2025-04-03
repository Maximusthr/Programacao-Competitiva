#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<vector<int>> mat(n, vector<int> (n));

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }

        int i = 0, j = 0;
        int aux_i = 0, aux_j = 0;
        int ans = 0;
        int aux = 0;

        while(aux_j < n){
            for (; j < n; i++, j++){
                aux = min(aux, mat[i][j]);
            }
            ans += aux * (-1);
            aux_j++;
            i = aux_i;
            j = aux_j;
            aux = 0;
        }

        aux_i = 1, aux_j = 0, aux = 0;
        i = 1, j = 0;

        while (aux_i < n){
            for (; i < n; i++, j++){
                aux = min(aux, mat[i][j]);
            }
            ans += aux * (-1);
            aux_i++;
            i = aux_i;
            j = aux_j;
            aux = 0;
        }

        cout << ans << "\n";
    }
}