#include <iostream>

using namespace std;

const int MAX = 11;
int lista[MAX];

int main(){

    int i;

    for (i = 0; i < MAX-1; i++){
        int x; cin >> x;
        lista[i] = x;
    }

    //pares
    for (i = 0; i < MAX-1; i++){
        if (lista[i] % 2 == 0) cout << lista[i] << " ";
    }
    cout << "\n";
    //impares 
    for (i = 0; i < MAX-1; i++){
        if (lista[i] % 2 != 0) cout << lista[i] << " ";
    }
}
