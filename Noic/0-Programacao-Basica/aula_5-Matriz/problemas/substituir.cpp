#include <bits/stdc++.h>
using namespace std;

int main(){
    int matriz[3][3];
    int maior = -2147483648;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cin >> matriz[i][j];
            if (matriz[i][j] > maior) maior = matriz[i][j];
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (maior == matriz[i][j]) matriz[i][j] = -1;
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
}
