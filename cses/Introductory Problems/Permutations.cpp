#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    vector<int> vet1;
    vector<int> vet2;

    if (qtd == 1) cout << 1 << "\n";
    else if (qtd <= 3) 
        cout << "NO SOLUTION\n";
    else {
        for (int i = 1; i <= qtd; i++){
            if (i % 2 == 0) vet1.push_back(i);
            else vet2.push_back(i);
        }

        for (int i : vet1) cout << i << " ";
        for (int i = 0; i < (int)vet2.size(); i++){
            if (i == (int)vet2.size()-1) cout << vet2[i] << "\n";
            else cout << vet2[i] << " ";
        }
    }
}
