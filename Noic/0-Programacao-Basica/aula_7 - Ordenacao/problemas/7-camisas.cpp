#include <bits/stdc++.h>

using namespace std;

typedef struct{
    string nome;
    string cor;
    string tamanho;
} camisas;

int main(){
    int qtd;

    int aux = 1;

    while(cin >> qtd && qtd){
        if (aux > 1) cout << "\n";

        string nome, cor, tamanho;        
        vector<camisas> camisetas;

        for (int i = 0; i < qtd; i++){
            cin.ignore();
            getline(cin, nome);
            cin >> cor >> tamanho;

            camisetas.push_back({nome, cor, tamanho});
        }

        sort(camisetas.begin(), camisetas.end(), [&](camisas &x, camisas &y){
            if (x.cor != y.cor) return x.cor < y.cor;
            if (x.tamanho != y.tamanho) return x.tamanho > y.tamanho;
            return x.nome < y.nome;
        });

        for (int i = 0; i < qtd; i++){
            cout << camisetas[i].cor << " " << camisetas[i].tamanho << " " << camisetas[i].nome << "\n";
        }

        aux++;
    }
}
