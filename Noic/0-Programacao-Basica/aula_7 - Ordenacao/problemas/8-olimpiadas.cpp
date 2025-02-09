#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int ouro = 0;
    int prata = 0;
    int bronze = 0;
} medalhas;


int main(){
    int qtd, modal; cin >> qtd >> modal;

    map<int, medalhas> aux;

    for (int i = 0; i < modal; i++){
        int x, y, z; cin >> x >> y >> z;

        aux[x].ouro++;
        aux[y].prata++;
        aux[z].bronze++;
    }

    vector<pair<int, pair<int, pair<int, int>>>> quadro;
    for (auto it = aux.begin(); it != aux.end(); it++){
        auto key = it->first;
        quadro.push_back({key, {aux[key].ouro, {aux[key].prata, aux[key].bronze}}});
    }

    sort(quadro.begin(), quadro.end(), [&](pair<int, pair<int, pair<int, int>>> &x, pair<int, pair<int, pair<int, int>>> &y){
        if (x.second.first != y.second.first) return x.second.first > y.second.first;
        if (x.second.second.first != y.second.second.first) return x.second.second.first > y.second.second.first;
        if (x.second.second.second != y.second.second.second) return x.second.second.second > y.second.second.second;
        return x.first < y.first;
    });

    int soma = 0;
    for (int i = 1; i <= qtd; i++){
        for (int j = 0; j < qtd; j++){
            if (i == quadro[j].first){
                soma = 0;
                break;
            }
            soma++;
        }
        if (soma == qtd) quadro.push_back({i, {0, {0, 0}}});
        soma = 0;
    }

    for (int i = 0; i < (int)quadro.size(); i++){
        if (i == (int)quadro.size()-1) cout << quadro[i].first << "\n";
        else cout << quadro[i].first << " ";
    }
}
