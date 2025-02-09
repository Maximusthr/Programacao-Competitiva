#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, l; cin >> n >> l;

    queue<int> minutos;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> vendedores;

    for (int i = 0; i < l; i++){
        int aux; cin >> aux;
        minutos.push(aux);
    }

    vector<int> soma(n);
    for (int i = 0; i < n; i++) {
        vendedores.push({0, i});
    }
    
    for (int i = 0; i < l; i++){
        int x = vendedores.top().first;
        int y = vendedores.top().second;
        vendedores.pop();
        soma[y]++;
        x += minutos.front();
        minutos.pop();

        vendedores.push({x, y});
    }  

    for (int i = 0; i < soma.size(); i++){
        cout << i+1 << " " << soma[i] << "\n";
    }
}
