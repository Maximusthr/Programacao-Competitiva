#include <iostream>

using namespace std;

int main(){
    int lista[100], i, maior = 0;

    for (i = 0; i < 100; i++){
        cin >> lista[i];
        if (lista[i] == 0) break;
        
        if (lista[i] > maior) maior = lista[i];
    }
    cout << maior << "\n";
}