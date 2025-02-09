#include <iostream>

using namespace std;

const int MAX = 101;
int lista[MAX];

int main(){
    int n; cin >> n;
    int i, maior = 0, aux = 0;

    for (i = 0; i < n; i++){
        cin >> lista[i];
        if (lista[i] > maior){
            maior = lista[i];
            aux = i;
        }
    }

    int x = 0;
    int y = 0;

    for (i = 0; i < n; i++){
        if (lista[i] != maior && i < aux){
            x += lista[i];
        } else if (lista[i] != maior && i > aux){
            y += lista[i];
        }
    }

    cout << x << "\n" << y << "\n";
}
