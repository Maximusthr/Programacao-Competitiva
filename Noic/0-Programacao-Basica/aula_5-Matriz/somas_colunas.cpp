#include <iostream>

using namespace std;

const int MAX = 3;
int matriz[MAX][MAX];

int main(){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> matriz[i][j];
        }
    }
    
    for (int i = 0; i < 3; i++){
        int soma = 0;
        for (int j = 0; j < 3; j++){
            soma += matriz[j][i];
        }
        cout << "Coluna " << i << ": " << soma << "\n";
    }
}