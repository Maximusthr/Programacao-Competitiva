#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd;

    while(cin >> qtd && qtd){
        vector<int> numeros(qtd);
        for (auto &x : numeros){
            cin >> x;
        }

        vector<pair<int, int>> positivo;
        vector<pair<int, int>> negativo;

        for (int i = 0; i < (int)numeros.size(); i++){
            if (numeros[i] < 0) negativo.push_back({numeros[i], i});
            else positivo.push_back({numeros[i], i});
        }

        long long caminho = 0;
        int aux = 0, pos = 0;
        while(1){
            if (pos == (int)positivo.size() || aux == (int)negativo.size()) break;
            if (negativo[aux].first < 0){
                if (positivo[pos].first > 0){
                    if (positivo[pos].first >= abs(negativo[aux].first)){
                        caminho += abs(negativo[aux].first) * abs(positivo[pos].second - negativo[aux].second);
                        positivo[pos].first -= abs(negativo[aux].first);
                        negativo[aux].first = 0;
                    }
                    else { 
                        caminho += abs(positivo[pos].first) * abs(positivo[pos].second - negativo[aux].second);
                        negativo[aux].first += positivo[pos].first;
                        positivo[pos].first = 0;
                    }
                } else {
                    pos++;
                    
                }
            } else {
                aux++;
            }
        }

        cout << caminho << "\n";
    }
}
