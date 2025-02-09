#include <bits/stdc++.h>

using namespace std;

int main(){
    set<string> alunos;

    int qtd, pos; cin >> qtd >> pos;

    while(qtd--){
        string aux; cin >> aux;
        alunos.insert(aux);
    }

    set<string>::iterator it;

    vector<string> x; 

    for (it = alunos.begin(); it != alunos.end(); it++){
        //cout << *it << "\n";
        x.push_back(*it);
    }

    cout << x[pos-1] << "\n";
}
