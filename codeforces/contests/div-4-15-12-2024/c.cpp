#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;

    while(qtd--){
        int m, a, b, c; cin >> m >> a >> b >> c;
        int linha = m;

        int soma = 0;

        // linha 1
        if (a >= m){
            soma += m;
            linha -= m;
        } else {
            soma += a;
            linha -= a;
        }

        if (c >= linha){
            soma += linha;
            c -= linha;
            linha = 0;
        } else {
            soma += c;
            c -= c;
        }

        // linha 2
        linha = m;
        if (b >= m){
            soma += linha;
            linha -= m;
        } else {
            soma += b;
            linha -= b;
        }

        if (c >= linha){
            soma += linha;
            c -= linha;
            linha = 0;
        } else {
            soma += c;
        }

        cout << soma << "\n";
    }
}
