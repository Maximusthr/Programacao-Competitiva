#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    while(qtd--){
        int x; cin >> x;

        int soma = 0;
        bool troca = false;
        bool aux = false;
        bool mudar = false;
        int linha_dois = 0;

        for (int i = 0; i < x*2; i++){
            for (int j = 0; j < x*2; j++){
                if (troca){
                    if (!mudar){
                        soma++;
                        cout << ".";
                        if (soma == 2) {
                            mudar = true;
                            soma = 0;
                        }
                    }
                    else if (mudar){
                        soma++;
                        cout << "#";
                        if (soma == 2){
                            mudar = false;
                            soma = 0;
                        }
                    }
                    aux = false;
                }
                else {
                    if (!mudar){
                        soma++;
                        cout << "#";
                        if (soma == 2) {
                            mudar = true;
                            soma = 0;
                        }
                    }
                    else if (mudar){
                        soma++;
                        cout << ".";
                        if (soma == 2){
                            mudar = false;
                            soma = 0;
                        }
                    }
                    aux = true;
                }
            }
            linha_dois++;
            cout << "\n";
            mudar = false;
            if (aux && linha_dois == 2) {
                troca = true;
                linha_dois = 0;
            }
            else if (linha_dois == 2) {
                troca = false;
                linha_dois = 0;
            }
        }
    }
}
