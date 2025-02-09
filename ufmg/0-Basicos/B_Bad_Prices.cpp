#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        int qtd; cin >> qtd;
        vector<int> v(qtd);

        for (auto &i : v) cin >> i;

        int soma = 0;
        int menor = v[(int)v.size()-1];
        for (int i = (int)v.size()-2; i >= 0; i--){
            if (v[i] > menor) soma++;
            else menor = v[i];
        }
        cout << soma << "\n";
    }
}
