#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int qtd; cin >> qtd;

        long long soma = 0;
        for (int i = 0; i < qtd; i++){
            long long aux; cin >> aux;
            soma += aux;
        }
        if ((long long)sqrt(soma) * (long long)sqrt(soma) == soma) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
