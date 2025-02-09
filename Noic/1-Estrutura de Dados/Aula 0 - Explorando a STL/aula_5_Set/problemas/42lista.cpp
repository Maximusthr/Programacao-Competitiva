#include <bits/stdc++.h>

using namespace std;

int main(){
    set<string> alunos;

    int qtd, pos; cin >> qtd >> pos;

    while(qtd--){
        string aux; cin >> aux;
        alunos.insert(aux);
    }

    auto it = alunos.begin();

    for (int i = 0; i < pos-1; i++)
        it++;
    cout << *it << '\n';
}
