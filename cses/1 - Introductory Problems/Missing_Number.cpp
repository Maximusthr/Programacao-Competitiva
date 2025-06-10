#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    vector<int> num;

    for (int i = 0; i < qtd-1; i++){
        int aux; cin >> aux;
        num.push_back(aux);
    }

    sort(num.begin(), num.end());
    bool fim = false;
    for (int i = 1; i < qtd; i++){
        if (num[i-1] != i) {
            cout << i << "\n";
            fim = true;
            break;
        }
    }
    if (!fim) cout << qtd << "\n";
}
