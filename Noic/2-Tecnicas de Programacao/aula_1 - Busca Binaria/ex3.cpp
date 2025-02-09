// Busca binária na resposta
// Resolver tipos de problema de minimização e maximização.
// Problema Pão a Metro, da segunda fase da OBI 2008, Programação Nível 1.

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int N, M;
int m[maxn]; // comprimento dos paes

// retorna verdadeiro se f(x) >= NB
// f(x) = m1/x + m2/x + ... + mM/x
bool ok(int x){
    int soma = 0;
    for (int i = 1; i <= M; i++) soma += (m[i]/x);
    
    return (soma >= N);
}

// achar a maior fatia
int busca(){
    int ini = 1, fim = 10000;
    int ans;

    while (ini <= fim){
        int mid = (ini+fim)/2;

        if (ok(mid)) { // se f(mid) >= N
            ans = mid; // possível resposta
            ini = mid+1;
        }
        else fim = mid-1; // valor alto de mais f(x) < N
    }

    return ans;
}

int main(){
    cin >> N >> M;

    for (int i = 1; i <= M; i++) cin >> m[i];

    cout << busca() << "\n";
}
