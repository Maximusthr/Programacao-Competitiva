#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    map<string, int> nomes;

    for (int i = 0; i < qtd; i++){
        string aux; cin >> aux;
        nomes[aux] = i;
    }
    
    vector<pair<string, int>> pares;
    for (auto [x, y] : nomes){
        pares.push_back({x, y});
    }

    sort(pares.begin(), pares.end(), [&](pair<string, int> &x, pair<string, int> &y){
        return x.second > y.second;
    });

    for (int i = 0; i < (int)pares.size(); i++){
        cout << pares[i].first << "\n";
    }
}
