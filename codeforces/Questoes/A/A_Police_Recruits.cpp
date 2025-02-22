#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    vector<int> vet(qtd);
    for (auto &i : vet) cin >> i;

    int police = 0;
    int sum = 0;
    for (int i = 0; i < qtd; i++){
        if (vet[i] != -1) police += vet[i];
        else {
            if (police > 0) police--;
            else sum++; 
        }
    }

    cout << sum << "\n";
}
