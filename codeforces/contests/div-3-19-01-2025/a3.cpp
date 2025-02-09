#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;

    for (int i = 0; i < qtd; i++){
        vector<int> vetor;

        for (int j = 0; j < 4; j++){
            int aux; cin >> aux;
            vetor.push_back(aux);
        }

        map<int, int> total;

        // primeiro caso a3 = a1 + a2;

        int resultado = vetor[0]+vetor[1];
        total[resultado]++;

        //segundo caso a3 = a4-a2;

        resultado = vetor[2]-vetor[1];
        total[resultado]++;
        
        // terceiro caso a a3 = a5-a4

        resultado = vetor[3]-vetor[2];
        total[resultado]++;


        int maior = 0;
        for (auto[x, y] : total){
            if (maior < y) maior = y;
        }

        cout << maior << "\n";

    }
}
