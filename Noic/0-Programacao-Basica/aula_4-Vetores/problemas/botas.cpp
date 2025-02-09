#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4+1;

typedef struct {
    int tamanho;
    char posicao;
} botas;

botas lista[MAX];

int main(){
    int pares; cin >> pares;

    int aux = pares;
    int i = 0;
    while (aux--){
        cin >> lista[i].tamanho;
        cin >> lista[i].posicao;
        i++;
    }    

    int ans = 0, j = 0;

    for (i = 0; i < pares; i++){
        if (lista[i].tamanho == 0)
            continue;
        for (j = i+1; j < pares; j++){
            if (lista[i].tamanho == lista[j].tamanho && lista[i].posicao != lista[j].posicao){
                ans++;
                lista[j].tamanho = 0;
                break;
            }
        }
    }

    cout << ans << "\n";
}
