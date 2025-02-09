#include <bits/stdc++.h>

using namespace std;

const int MAX = 12;

int main(){
    cout << fixed << setprecision(1);

    char c; cin >> c;

    double matriz[MAX][MAX];

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            cin >> matriz[i][j];
        }
    }

    double soma = 0, count = 0;
    int aux = 10, aux_j = 6; // aux = 10 -> representa a coluna. aux_j -> representa a linha

    for (int i = 1; i < MAX; i++){ // i = 1, pois i = 0 não tem nada.
        for (int j = 11; j > 0; j--){
            if (i <= 5 && j > aux) { // condição para parar no i = 5 e o j chegar até a coluna indicada
                soma += matriz[i][j];
                count++;
            } else if (i >= 6 && j > aux_j){ // condição para parar no i = 6 e o j chegar até a coluna indicada
                soma += matriz[i][j];
                count++;
            }
        }
        // manipulação dos auxiliares
        if (i <= 5) aux--;
        else {
            aux_j++;
        }
    }
    
    cout << ((c == 'S') ? soma : soma/count) << "\n";

}
