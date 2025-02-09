#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;

    for (int i = 0; i < qtd; i++){
        int n, m; cin >> n >> m;

        int matriz[n][m];
        vector<pair<int, int>> pares;

        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++){
                cin >> matriz[j][k];
                pares.push_back({j, matriz[j][k]});
            }
        }

        sort(pares.begin(), pares.end(), [&](pair<int, int> &x, pair<int, int> &y){
            return x.second < y.second;
        });

        vector<int> sequencia;
        bool ok = true;

        for (int j = 0; j < (int)pares.size(); j++){
            sequencia.push_back(pares[j].first);
            if (j > 0 && pares[j].first == pares[j-1].first) {
                ok = false;
                break;
            }
        }

        vector<int> auxiliar;

        if (ok){
            for (int j = 0; j < (int)sequencia.size(); j++){
                bool existe = false;
                auxiliar.push_back(sequencia[j]);
                int var = 0;
                int cont = 0;
                while (var < auxiliar.size()){
                    if (sequencia[j] == auxiliar[var]) cont++;
                    if (cont > 1) {
                        existe = true;
                        break;
                    }
                    var++;
                }
                
                if (existe) continue;

                if (j == 0) cout << sequencia[j]+1;
                else {
                    cout << " " << sequencia[j]+1;
                }
            }
        } else cout << "-1";

        cout << "\n";
    }    
}
