#include <bits/stdc++.h>
//ERRADO
using namespace std;

int main(){
    int qtd; cin >> qtd;

    vector<pair<int, int>> consultas;
    for (int i = 0; i < qtd; i++){
        int x, y; cin >> x >> y;
        consultas.push_back({x, y});
    }

    sort(consultas.begin(), consultas.end(), [&](pair<int, int> &x, pair<int,int> &y){
        return x.second < y.second;
    });

    int soma = 0;
    for (int i = 0, aux = 0; i < qtd; i++){
        if ((i+1 < qtd) && (consultas[aux].second <= consultas[i+1].first)){
            soma++;
            aux = i+1;
        }
    }

    cout << soma << "\n";
}
