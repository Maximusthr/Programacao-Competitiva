#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> vetor(n);
    for (auto &i : vetor) cin >> i;

    vector<int> aux = vetor;

    int soma = 0;

    if (vetor[0] == k) soma++;

    for (int i = 1; i < n; i++){
        if (aux[i] + aux[i-1] <= k) aux[i] = aux[i] + aux[i-1];
        if (aux[i] == k) soma++;
    }

    // 0s a esquerda

    while()

    cout << soma << "\n";
}
