#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int matriz[3][3];
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> matriz[i][j];
        }
    }

    int linha = 0;
    int coluna = 0;
    int diagonal_p = 0;
    int diagonal_s = 0;
    int temp = 0;
    bool correto = true;

    // verificação da linha e coluna
    for (int i = 0; i < 1; i++){
        for (int j = 0; j < 3; j++){
            linha += matriz[i][j];
            coluna += matriz[j][i];
            diagonal_p += matriz[j][j];
            diagonal_s += matriz[2-j][j];
        }
        if (i == 0) temp = linha;
        if (linha != temp || coluna != temp || diagonal_p != temp || diagonal_s != temp) {
            correto = false;
            break;
        }
    }
    // cout << ((correto)?"SIM":"NAO") << "\n";
    correto ? (cout << "SIM" << "\n") : (cout << "NAO" << "\n");
}
