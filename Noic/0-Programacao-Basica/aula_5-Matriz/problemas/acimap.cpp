#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 12; // Exatamente igual, pois não se trata de lista. Apenas um demonstrativo para o tamanho da matriz.

int main(){
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    cout << fixed << setprecision(1);

    double m[MAX][MAX];
    char carac; cin >> carac;

    double soma = 0, count = 0;

    for (int i = 0; i < MAX; i++){
        for (int j = 0; j < MAX; j++){
            cin >> m[i][j];
        }
    }

    //tratamento da questão
    for (int i = 0; i < MAX-1; i++){
        for (int j = i; j < MAX-1; j++){ // Vai até o numero 11, como previsto para o tamanho da matriz, para naõ afetar o if.
            soma += m[i][j+1];
            count++;
        }
    }

    if (carac == 'S') cout << soma << "\n";
    else cout << (double)(soma/count) << "\n";
}
