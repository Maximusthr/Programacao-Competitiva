#include <bits/stdc++.h>

using namespace std;

int main(){
    int m, qtd; cin >> m >> qtd;

    vector<pair<int, int>> pontos;

    for (int i = 0; i < qtd; i++){
        int aux1, aux2; cin >> aux1 >> aux2;
        pontos.push_back({aux1, aux2});
    }

    sort(pontos.begin(), pontos.end());

    int maior = -1;
    for (int i = 0; i < qtd; i++){
        for (int j = 0; j < qtd; j++){
            if (pontos[j].first <= pontos[i].second && pontos[j].second >= pontos[i].second) {
                pontos[i].second = pontos[j].second;
            }
            else if (pontos[i].second == pontos[j].first) {
                pontos[i].second = pontos[j].second;
                maior = pontos[i].second;
                cout << pontos[i].first << " " << pontos[i].second << "\n";
            } 
        }
        if (pontos[i].first > maior){
            cout << pontos[i].first << " " << pontos[i].second << "\n";
            maior = pontos[i].second;
        }
    }
}
