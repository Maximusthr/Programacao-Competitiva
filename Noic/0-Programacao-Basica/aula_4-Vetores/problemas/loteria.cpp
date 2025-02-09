#include <iostream>

using namespace std;

const int MAX = 7;
int aposta[MAX];
int resultado[MAX];

int main(){
    int i;
    for (i = 0; i < 6; i++){
        cin >> aposta[i];
    }

    for (i = 0; i < 6; i++){
        cin >> resultado[i];
    }

    int soma = 0, j;

    for (i = 0; i < 6; i++){
        for (j = 0; j < 6; j++){
            if (aposta[i] == resultado[j]) {
                soma++;
                break;
            }
        }
    }

    if (soma == 3) cout << "terno" << "\n";
    else if (soma == 4) cout << "quadra" << "\n";
    else if (soma == 5) cout << "quina" << "\n";
    else if (soma == 6) cout << "sena" << "\n";
    else cout << "azar" << "\n";
}
