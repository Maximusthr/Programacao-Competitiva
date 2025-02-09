#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;
    cin.ignore();
    vector<char> resumo;
    for (int i = 0; i < qtd; i++){
        int soma = 0;
        string aux; getline(cin, aux);
        soma += (int)aux.size();
        for (int j = 0; j < soma; j++){
            if (aux[j] == '{' || aux[j] == '}') resumo.push_back(aux[j]);
        }
    }

    stack<char> pilha;

    for (int i = 0; i < (int)resumo.size(); i++){
        if (resumo[i] == '}' && pilha.empty() == true){
            pilha.push('1');
            break;
        }
        if (resumo[i] == '}') {
            pilha.pop();
        }
        else pilha.push(resumo[i]);
    }

    bool verificar = pilha.empty();
    cout << (verificar ? "S" : "N") << "\n";
}
