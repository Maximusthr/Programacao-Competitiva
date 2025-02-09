#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;
    
    for (int i = 0; i < qtd; i++){
        stack<char> pilha;
        string aux; cin >> aux;
        for (int j = 0; j < (int)aux.size(); j++){
            if ((aux[j] == ')' || aux[j] == ']' || aux[j] == '}') && pilha.empty() == true) {
                pilha.push('1');
                break;
            } 
            if (aux[j] == ')'){
                if (pilha.top() == '(') pilha.pop();
                else break;
            } else if (aux[j] == ']'){
                if (pilha.top() == '[') pilha.pop();
                else break;
            } else if (aux[j] == '}') {
                if (pilha.top() == '{') pilha.pop();
                else break;
            }
            else {
               pilha.push(aux[j]);
            }
        }

        bool vazio = pilha.empty();
        cout << (vazio ? "S" : "N") << "\n";
    }
}
