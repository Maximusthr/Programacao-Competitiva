#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;

    vector<int> vetor(qtd);
    for (auto &x : vetor){
        cin >> x;
    }

    vector<int> aux = vetor;
    bool neg = false;

    for (int i = qtd-1; i >= 0; i--){
        if (vetor[i] < 0 && !neg){
            neg = true;
            aux[i] = abs(vetor[i]);
        }
        else if (vetor[i] < 0 && neg){
            neg = false;
            aux[i] = vetor[i];
        }

        else if (neg) aux[i] = -1*vetor[i];
        else aux[i] = vetor[i];
    }

    for (int i = 0; i < qtd; i++){
        if (i == qtd-1) cout << aux[i] << "\n";
        else cout << aux[i] << " ";
    }
}
