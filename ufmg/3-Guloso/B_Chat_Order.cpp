#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    set<string> nomes;
    stack<string> pilha;

    for (int i = 0; i < qtd; i++){
        string aux; cin >> aux;
        nomes.insert(aux);
        pilha.push(aux);
    }

    vector<string> unico;
    auto it = nomes.begin();
    for (int i = 0; i < (int)nomes.size(); i++){
        unico.push_back(*it);
        it++;
    }

    bool ok = false;
    int pos = 0;
    while(!pilha.empty()){
        for (int i = 0; i < (int)unico.size(); i++){
            if (pilha.top() == unico[i]) {
                pos = i;
                cout << pilha.top() << "\n";
                pilha.pop();
                ok = true;
                break;
            }
        }
        if (!ok) pilha.pop();
        else unico.erase(unico.begin() + pos);
        ok = false;
    }
}
