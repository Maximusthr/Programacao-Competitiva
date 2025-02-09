#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

const int MAX = 12;

int main(){
    cout << fixed << setprecision(1);

    double matriz[MAX][MAX];
    char carac; cin >> carac;

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            cin >> matriz[i][j];
        }
    }

    double soma = 0, count = 0;

    int aux = 1;
    for (int i = MAX-1; i > 0; i--){
        for (int j = aux; j < MAX; j++){
            soma += matriz[i][j];
            count++;
        }
        aux++;
    }

    double media = (soma/count);

    if (carac == 'S') cout << soma << "\n";
    else cout << media << "\n";
}
