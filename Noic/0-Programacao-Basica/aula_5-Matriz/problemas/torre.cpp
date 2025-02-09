#include <bits/stdc++.h>

using namespace std;

int main(){

    int n; cin >> n;
    int matriz[n][n];
    int linha[n] = {};
    int coluna[n] = {};

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matriz[i][j];
        }
    }

    int maior = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            linha[i] += matriz[i][j];
            coluna[i] += matriz[j][i];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x = linha[i] + coluna[j] - (matriz[i][j]*2);
            if (x > maior) maior = x;
        }
    }
    
    cout << maior << "\n";
}
