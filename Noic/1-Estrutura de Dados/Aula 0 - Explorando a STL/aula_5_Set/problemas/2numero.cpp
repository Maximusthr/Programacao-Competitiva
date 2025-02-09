#include <bits/stdc++.h>

using namespace std;

int main(){
    //cin.tie(nullptr); ios::sync_with_stdio(0)
    cin.tie(nullptr)->sync_with_stdio(0);
    int qtd; cin >> qtd;

    set<int> num;

    for (int i = 0; i < qtd; i++){
        int aux; cin >> aux;
        num.insert(aux);
    }

    int aux;
    while (cin >> aux){
        if (num.find(aux) != num.end()) cout << "sim" << "\n";
        else cout << "nao" << "\n";
    }
}
