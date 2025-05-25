#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd;
    cin >> qtd;

    for (int i = 0; i < qtd; i++){
        vector<int> vetor;

        for (int j = 0; j < 4; j++){
            int aux; cin >> aux;
            vetor.push_back(aux);
        }


        int operacao = vetor[0]+vetor[1];

        vector<int> novo_vetor;
        for (int j = 0, aux = 0; j <= (int)vetor.size(); j++){
            if (j == 2) {
                novo_vetor.push_back(operacao);
            }
            else {
                novo_vetor.push_back(vetor[aux]);
                aux++;
            }
        }

        int pos = 0;
        for (int j = 0; j < (int)novo_vetor.size(); j++){
            if (novo_vetor[j+2] != novo_vetor[j] + novo_vetor[j+1]){
                pos = j;
                cout << pos << "\n";
                break;
            }
        }
    }
}
