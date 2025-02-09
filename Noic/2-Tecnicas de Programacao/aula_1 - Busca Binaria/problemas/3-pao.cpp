#include <bits/stdc++.h>

using namespace std;

int fatias, qtd;
vector<int> pao;

bool ok(int x){
    int soma = 0;
    
    for (int i = 0; i < qtd; i++){
        soma += pao[i]/x;
    }

    return soma >= fatias;
}

int buscab(){
    int ini = 1, fim = 10000;
    int meio;
    int ans;
    while (ini <= fim){
        meio = (ini+fim)/2;

        if(ok(meio)){
            ini = meio+1;
            ans = meio;
        } else {
            fim = meio-1;
        }
    }

    return ans;
}

int main(){
    cin >> fatias;
    cin >> qtd;

    for (int i = 0; i < qtd; i++){
        int aux; cin >> aux;
        pao.push_back(aux);
    }

    cout << buscab() << "\n";
}
