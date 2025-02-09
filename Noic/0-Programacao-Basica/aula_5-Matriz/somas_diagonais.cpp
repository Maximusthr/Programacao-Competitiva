#include <iostream>
using namespace std;

int main(){
    int matriz[3][3];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> matriz[i][j];
        }
    }

    // Diagonal principal
    int soma_p = 0;
    for (int i = 0; i < 3; i++){
        soma_p += matriz[i][i];
    }
    // Diagonal secundaria
    int soma_s = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 2; j > -1; j--){
            soma_s += matriz[i][j];
            i++;
        }
    }

    cout << "Diagonal principal: " << soma_p << "\n";
    cout << "Diagonal secundaria: " << soma_s << "\n";
}