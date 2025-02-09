#include <bits/stdc++.h>

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

    int livre = 0;
    int soma = 0;
    for (int i = 0, aux = 0; i < qtd; i++){
        if (consultas[i].first >= livre){
            soma++;
            livre = consultas[i].second;
        }
    }

    cout << soma << "\n";
}
