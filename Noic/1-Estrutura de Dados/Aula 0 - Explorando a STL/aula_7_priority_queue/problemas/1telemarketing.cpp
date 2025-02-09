#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l; cin >> n >> l;

    queue<int> minutos;
    priority_queue<int, vector<int>, greater<int>> vendedores;

    for (int i = 0; i < l; i++){
        int aux; cin >> aux;
        minutos.push(aux);
    }

    map<int, int> tempo;
    map<int, int> ligacoes;

    for (int i = 1; i <= n; i++) {
        vendedores.push(i);
    }
    
    for (int i = 0; i <= l; i++){
        if ((int)vendedores.size() > 0){
            tempo[vendedores.top()] += minutos.front();
            minutos.pop();
            ligacoes[vendedores.top()]++;
            vendedores.pop();
        }

        if (minutos.size() == 0) break;

        int menor = 1e6+1;
        if (i >= n){
            auto it = tempo.begin();
            for (int k = 0; k < n; k++){
                if ((*it).second < menor) menor = (*it).second;
                it++;
            }
            it = tempo.begin();
            for (int j = 0; j < n; j++){
                if (((*it).second == menor)){
                    vendedores.push((*it).first);
                    break;
                } else it++;
            }
        }
    }

    auto it = ligacoes.begin();
    for (int i = 0; i < n; i++){
        if ((n > l) && (i > n-l)){
            cout << i+1 << " 0" << "\n";
        }
        else {
            cout << (*it).first << " " << (*it).second << "\n";
            it++;
        }
    }    
}
