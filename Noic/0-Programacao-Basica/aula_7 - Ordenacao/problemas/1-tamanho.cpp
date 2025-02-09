#include <bits/stdc++.h>

using namespace std;

bool ordenacao(pair<string, int> x, pair<string, int> y){
    if (x.first.size() != y.first.size()) return x.first.size() > y.first.size();
    return x.second < y.second;
}

int main(){
    int qtd; cin >> qtd;
    cin.ignore();

    while(qtd--){
        string aux; getline(cin, aux);

        string x;
        vector<string> vetor;
        for (int i = 0; i < (int)aux.size(); i++){
            if (aux[i] != ' ') {
                x += aux[i];
                if (i == (int)aux.size()-1) {
                    vetor.push_back(x);
                    break;
                }
            }
            else if (aux[i] == ' ') {
                vetor.push_back(x);
                x = {};
            }
        }

        vector<pair<string, int>> valores;

        for (int i = 0; i < (int)vetor.size(); i++){
            valores.push_back({vetor[i], i});
        }
        
        sort(valores.begin(), valores.end(), ordenacao);

        for (int i = 0; i < (int)valores.size(); i++){
            if (i != (int)valores.size()-1) cout << valores[i].first << " ";
            else cout << valores[i].first << "\n";
        }        
    }
}
