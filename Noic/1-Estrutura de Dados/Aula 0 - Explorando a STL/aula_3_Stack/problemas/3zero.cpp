#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;

    stack<int> pilha;
    while(qtd--){
        int aux; cin >> aux;
        if (aux == 0) pilha.pop();
        else pilha.push(aux);
    }

    int soma = 0;
    while(!pilha.empty()){
        soma += pilha.top();
        pilha.pop();
    }

    cout << soma << "\n";
}
