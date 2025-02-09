#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;
    cin.ignore();

    for (int i = 0; i < qtd; i++){
        vector<int> vetor;
        for (int j = 0; j < 4; j++){
            int aux; cin >> aux;
            vetor.push_back(aux);
        }
        
        int operacao = vetor[2]-vetor[1];
        
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

        vector<pair<int, int>> maior;
        for (int j = 0; j <= (int)novo_vetor.size()-2; j++){
            if (novo_vetor[j+2] == novo_vetor[j]+novo_vetor[j+1]){
                maior.push_back({j, novo_vetor[j+2]});
            }
        }    

        operacao = vetor[0]+vetor[1];
        novo_vetor.clear();
        for (int j = 0, aux = 0; j <= (int)vetor.size(); j++){
            if (j == 2) {
                novo_vetor.push_back(operacao);
            }
            else {
                novo_vetor.push_back(vetor[aux]);
                aux++;
            }
        }
        for (int j = 0; j <= (int)novo_vetor.size()-2; j++){
            if (novo_vetor[j+2] == novo_vetor[j]+novo_vetor[j+1]){
                maior.push_back({j, novo_vetor[j+2]});
            }
        }

        sort(maior.begin(), maior.end(), [&](pair<int, int> x, pair<int, int> y){
            if (x.second != y.second){
                return x.second > y.second;
            } else {
                return x.first < y.first;
            }
        });

        cout << maior[0].first+1 << "\n";
    }
}