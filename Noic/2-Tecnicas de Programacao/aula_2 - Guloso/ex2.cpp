// Algoritmo Kadane -> aula UFMG Guloso

#include <bits/stdc++.h>

using namespace std;


int main(){
    // Mantém uma variável de soma_ant que verificar se o valor máximo é maior ou menor.
    // Se o próximo é positivo, o ideal é que se some v[i] + soma_ant
    // se for menor que 0, a soma máxima será apenas o v[i]
    // como pode ser negativo, a variável precisa ser inicializada como -INF

    int qtd; cin >> qtd;

    int vetor[qtd];
    for (int i = 0; i < qtd; i++){
        cin >> vetor[i];
    }

    int ans = -101;
    int soma_ant = -101;
    for (int i = 0; i < qtd; i++){
        if (soma_ant < 0) soma_ant = vetor[i];
        else if (soma_ant >= 0) soma_ant += vetor[i];
        if (soma_ant > ans) ans = soma_ant;
    }

    cout << ans << "\n";
}
