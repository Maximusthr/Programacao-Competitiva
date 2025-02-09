#include <iostream>
#include <stack>

using namespace std;

// int main(){

//     stack<int> pilha;

//     pilha.push(1);
//     pilha.push(2);
//     pilha.push(10);

//     cout << pilha.top() << "\n";

//     pilha.pop();

//     cout << pilha.top() << "\n";

// }

int main(){
    stack<int> pilha;

    pilha.push(1);
    pilha.push(2);
    pilha.push(3);

    int tamanho = (int)pilha.size();

    for (int i = 0; i < tamanho; i++){
        cout << pilha.top() << " ";
        pilha.pop();
    }  
}