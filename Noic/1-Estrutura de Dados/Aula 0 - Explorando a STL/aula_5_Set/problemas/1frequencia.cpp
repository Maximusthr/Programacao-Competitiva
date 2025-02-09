#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;

    set<int> freq;

    while(qtd--){
        int aux; cin >> aux;
        freq.insert(aux);
    }
    cout << (int)freq.size() << "\n";
}
