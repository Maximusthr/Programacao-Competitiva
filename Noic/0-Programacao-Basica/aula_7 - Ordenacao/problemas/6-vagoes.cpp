#include <bits/stdc++.h>

using namespace std;

int x; vector<int> vagoes;
int soma = 0;

void bubblesort(){

    int ordenado = 0;
    while (ordenado == 0){

        ordenado = 1;

        for (int i = 0; i < x-1; i++){
            if (vagoes[i] > vagoes[i+1]) {

                int temp = vagoes[i];
                vagoes[i] = vagoes[i+1];
                vagoes[i+1] = temp;

                soma++;

                ordenado = 0;
            }
        }
    }
}

int main(){
    int qtd; cin >> qtd;

    while(qtd--){
        cin >> x;

        for (int i = 0; i < x; i++){
            int aux; cin >> aux;
            vagoes.push_back(aux);
        }

        bubblesort();
        
        cout << "Optimal train swapping takes " << soma << " swaps.\n";

        soma = 0;
        vagoes.clear();
    }
}
