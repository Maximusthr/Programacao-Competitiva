#include <iostream>

using namespace std;


const int N = 55; // para não der problemas com o tamanho máximo na declaração da lista
int n, i;
int lista[N];

int main(){
    cin >> n;

    for (i = 0; i < n; i++){
        cin >> lista[i];
    }

    int count = 0;
    for (i = 0; i < n; i++){
        if (lista[i] == 1) count++;
        if (i > 0 && lista[i-1] == 1) count++;
        if (i < n-1 && lista[i+1] == 1) count++;

        cout << count << "\n";
        count = 0;
    }
}