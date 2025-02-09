#include <bits/stdc++.h>

using namespace std;

#define MAX 100010

int vetor[MAX], aux[MAX];

long long int merge_sort(int ini, int fim){
    if (ini == fim) return 0;

    long long int inversao = merge_sort(ini, (ini+fim)/2) + merge_sort((ini+fim)/2+1, fim);

    int tam = 0, j = (ini+fim)/2+1;

    // metade esquerda

    for (int i = ini; i <= (ini+fim)/2; i++){

        while (j <= fim && vetor[j] < vetor[i]){
            aux[tam] = vetor[j];
            tam++;
            j++;
            inversao += (ini+fim)/2-i+1;
        }

        aux[tam] = vetor[i];
        tam++;
    }

    while (j <= fim){
        aux[tam] = vetor[j];
        tam++;
        j++;
    }

    for (int i = ini; i <= fim; i++) vetor[i] = aux[i-ini];

    return inversao;
}

int main(){
    int qtd; cin >> qtd;

    for (int i = 1; i <= qtd; i++){
        cin >> vetor[i];
    }

    long long int pares = merge_sort(1, qtd);

    cout << pares << "\n";
}
