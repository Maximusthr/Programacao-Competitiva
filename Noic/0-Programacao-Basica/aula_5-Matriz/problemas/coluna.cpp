#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double matriz[12][12];

    int coluna; cin >> coluna;
    char operacao; cin >> operacao;

    for (int i = 0; i < 12; i++){
        for (int j = 0; j < 12; j++){
            cin >> matriz[i][j];
        }
    }

    double soma = 0;
    for (int i = 0; i < 12; i++){
        soma += matriz[i][coluna];
    }

    cout << fixed << setprecision(1); // setar a precisão no C++
    operacao == 'S' ? (cout << soma << "\n") : (cout << (soma/12) << "\n");

    //operacao == 'S' ? printf("%.1lf", soma) : printf("%.1lf", (soma/12)); // Ou utlizando o padrão do C.
}