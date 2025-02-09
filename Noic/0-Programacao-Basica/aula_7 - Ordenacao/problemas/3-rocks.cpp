#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd;
    int a = 1;

    while(cin >> qtd && qtd){
        if (a != 1) cout << "\n";
        int formula = (qtd*(qtd-1))/2;
        
        int pontos_m = 0, pontos_s = 0;

        map<int, int> times;
        map<int, int> pontos_marcados;
        map<int, int> pontos_sofridos;
        
        for (int i = 0; i < formula; i++){
            int x, y, z, w; cin >> x >> y >> z >> w;
            
            if (y > w){ // time x vence
                times[x] += 2;
                times[z]++;

                pontos_m = y;
                pontos_s = w;

                pontos_marcados[x] += pontos_m;
                pontos_sofridos[x] += pontos_s;
                
                pontos_marcados[z] += pontos_s;
                pontos_sofridos[z] += pontos_m;

            } else {
                times[z] += 2;
                times[x]++;

                pontos_m = w;
                pontos_s = y;
                pontos_marcados[z] += pontos_m;
                pontos_sofridos[z] += pontos_s;

                pontos_marcados[x] += pontos_s;
                pontos_sofridos[x] += pontos_m;
            }          
        }

        vector<pair<int, pair<int, pair<int, int>>>> times_ordenado;

        for(auto it = times.begin(); it != times.end(); it++){
            int key = it->first;
            times_ordenado.push_back({key, {times[key], {pontos_marcados[key], pontos_sofridos[key]}}});
        }

        sort(times_ordenado.begin(), times_ordenado.end(), [&](pair<int, pair<int, pair<int, int>>> &x, pair<int, pair<int, pair<int, int>>> &y){
            if (x.second.first != y.second.first) return x.second.first > y.second.first;

            double average_x = (double)x.second.second.first/(double)x.second.second.second;
            double average_y = (double)y.second.second.first/(double)y.second.second.second;
            if (abs(average_x - average_y) > 1e-9) return average_x > average_y;

            if (x.second.second.first != y.second.second.first) return x.second.second.first > y.second.second.first;
            
            return x.first < y.first;
        });

        cout << "Instancia " << a << "\n";

        for (int i = 0; i < times_ordenado.size(); i++){
            if (i != times_ordenado.size()-1) cout << times_ordenado[i].first << " ";
            else cout << times_ordenado[i].first << "\n";
        }
        a++;
    }
}
