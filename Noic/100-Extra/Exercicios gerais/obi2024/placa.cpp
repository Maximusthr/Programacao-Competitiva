#include <bits/stdc++.h>

using namespace std;

int main(){
    string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numeros = "0123456789";
    string placa; cin >> placa;

    int tamanho = (int)placa.size();
    bool correto = false;
    int tipo = 0;

    // Para 8 caracteres -> brasileira.
    if (tamanho == 8){
        for (int i = 0; i < tamanho; i++){
            if (i < 3){
                for (int j = 0; j < (int)alfabeto.size(); j++){
                    if (placa[i] == alfabeto[j]) {
                        correto = true;
                        break;
                    } else {
                        correto = false;
                    }
                }
            } else if (i == 3){
                if (placa[i] == '-'){
                    correto = true;
                } else {
                    correto = false;
                    break;
                }
            } else {
                for (int j = 0; j < (int)numeros.size(); j++){
                    if (placa[i] == numeros[j]) {
                        correto = true;
                        break;
                    } else {
                        correto = false;
                    }
                }
            }
        }
    } else if (tamanho == 7){ // Para 7 caracteres -> Mercosul.
        for (int i = 0; i < tamanho; i++){
            if (i < 3 || i == 5){
                for (int j = 0; j < (int)alfabeto.size(); j++){
                    if (placa[i] == alfabeto[j]) {
                        correto = true;
                        break;
                    } else {
                        correto = false;
                    }
                }
            } else if (i == 4 || i > 5){
                for (int j = 0; j < (int)numeros.size(); j++){
                    if (placa[i] == numeros[j]) {
                        correto = true;
                        break;
                    } else {
                        correto = false;
                    }
                }
            }
        }
    }
    
    if (tamanho == 8 && correto == true) tipo = 1;
    else if (tamanho == 7 && correto == true) tipo = 2;
    else tipo = 0;

    cout << tipo << "\n";
   
}

