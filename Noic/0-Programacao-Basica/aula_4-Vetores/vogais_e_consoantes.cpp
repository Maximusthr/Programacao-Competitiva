#include <iostream>

using namespace std;

int main(){
    string palavra;
    cin >> palavra;

    int i;
    int tamanho = palavra.size();
    string vogais, consoantes; // ou vogais = "";
    
    for (i = 0; i < tamanho; i++){
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u') vogais += palavra[i];
        else consoantes += palavra[i];
    }

    cout << "Vogais: " << vogais << "\n";
    cout << "Consoantes: " << consoantes << "\n";
}