#include <bits/stdc++.h>

using namespace std;

typedef struct{
    string nome;
    int peso;
    int idade;
    double altura;
} valores;

int main(){
    int qtd; cin >> qtd;

    for (int i = 1; i <= qtd; i++){
        cout << "CENARIO {" << i << "}\n";

        int x, y; cin >> x >> y;

        vector<valores> renas;

        for (int j = 0; j < x; j++){
            string nome; int peso, idade; double altura;
            cin >> nome >> peso >> idade >> altura;

            renas.push_back({nome, peso, idade, altura});
        }
        
        sort(renas.begin(), renas.end(), [&](valores &x, valores &y){
            if (x.peso != y.peso) return x.peso > y.peso;
            if (x.idade != y.idade) return x.idade < y.idade;
            if ((x.altura - y.altura) >= 1e-9) return x.altura < y.altura;
            return x.nome < y.nome;
        });

        for (int k = 0; k < y; k++){
            cout << k+1 << " - " << renas[k].nome << "\n";
        }       
    }
}
