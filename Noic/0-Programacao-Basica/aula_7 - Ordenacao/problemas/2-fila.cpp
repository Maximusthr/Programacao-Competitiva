#include <bits/stdc++.h>

using namespace std;

bool ordenacao(int x, int y){
    return x > y;
}

int main(){
    int qtd; cin >> qtd;

    while(qtd--){
        int x; cin >> x;
        vector<int> notas;
        for (int i = 0; i < x; i++){
            int aux; cin >> aux;
            notas.push_back(aux);
        }

        vector<int> copia = notas;
        
        sort(notas.begin(), notas.end(), ordenacao);

        int soma = 0;
        for (int i = 0; i < x; i++){
            if (copia[i] == notas[i]) soma++;
        }

        cout << soma << "\n";
    }
}
