#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    vector<int> vet(qtd);
    for (auto &i : vet) cin >> i;
    
    int x = 0, y = 0;

    bool turn = false;
    while (vet.size() > 0){
        int maior = max(vet[0], vet[vet.size()-1]);
        int pos = (maior == vet[0] ? 0 : vet.size()-1);
        if (!turn) {
            x += maior;
            turn = true;
        }
        else {
            y += maior;
            turn = false;
        }

        vet.erase(vet.begin()+pos);
    }
    cout << x << " " << y << "\n";
}
