// Busca binária (pura)

#include <bits/stdc++.h>

using namespace std;

#define MAXN 100100

int n, m, vetor[MAXN];

int buscab(int x){
    int ini = 1, fim = n, meio;

    while(ini <= fim){
        meio = (ini+fim)/2;
        if (vetor[meio] == x) return meio;
        if (vetor[meio] < x) ini = meio+1;
        if (vetor[meio] > x) fim = meio-1;
    }

    return -1;
}

int main(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> vetor[i];

    for (int i = 1; i <= m; i++){
        int num; cin >> num;
        cout << buscab(num) << "\n";
    }
}
