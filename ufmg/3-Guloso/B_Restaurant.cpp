#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;

    vector<pair<int, int>> pares;
    for (int i = 0; i < qtd; i++){
        int ini, fim; cin >> ini >> fim;
        pares.push_back({ini, fim});
    }

    sort(pares.begin(), pares.end(), [&](pair<int, int> &x, pair<int, int> &y){
        return x.second < y.second;
    });

    int clientes = 0;
    int atual = 0;
    for (int i = 0; i < (int)pares.size(); i++){
        if (pares[i].first > atual){
            atual = pares[i].second;
            clientes++;
        }
    }

    cout << clientes << "\n";
    
}
