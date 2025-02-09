// utilizar dois pointers para os índices de par e impar para incrementar o tamanho de cada um deles para a impressão na saída.


#include <iostream>

using namespace std;

const int MAX = 11;

int pares[MAX];
int impares[MAX];

int main(){
    int i = 0;

    for (i = 0; i < 10; i++){
        int x; cin >> x;
        if (x % 2 == 0 ) pares[i] = x;
        else impares[i] = x;
    }
    
    for (i = 0; i < 10; i++){
        if (pares[i] % 2 == 0) cout << pares[i] << " ";
    }
    cout << "\n";
    for (i = 0; i < 10; i++){
        if (impares[i] % 2 == 1) cout << impares[i] << " ";
    }
}
