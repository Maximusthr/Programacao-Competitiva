#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;

    char mat[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            mat[i][j] = '*';
        }
    }

    int aux = 0;
    for (int i = n/2; i >= 0; i--){
        for (int j = aux; j < n-aux; j++){
            mat[i][j] = 'D';
        }
        aux++;
    }

    aux = 0;
    for (int i = n/2; i < n; i++){
        for (int j = aux; j < n-aux; j++){
            mat[i][j] = 'D';
        }
        aux++;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << mat[i][j];
        }
        cout << "\n";
    }
}
