#include <bits/stdc++.h>

using namespace std;

bool tipo(vector<int> vetor){
    int tam = (int)vetor.size();

    bool negativo = false;
    bool positivo = false;

    for (int i = 0; i < tam; i++){
        if (vetor[i] > 0) positivo = true;
        else if (vetor[i] < 0) negativo = true;
    }

    if (negativo && positivo) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    while(qtd--){
        int x; cin >> x;

        vector<int> seq;

        for (int i = 0; i < x; i++){
            int aux; cin >> aux;
            seq.push_back(aux);
        }

        long long maior = -2147483647;
        if (!tipo(seq)){
            for (auto i : seq){
                if (i > maior) maior = i;
            }
        } else {          
            long long somatorio = 0;
            int maior_sub = seq[0];

            for (int i = 1; i < x; i++){
                if (seq[i] > 0 && seq[i-1] > 0) 
                    maior_sub = max(seq[i], maior_sub);

                else if (seq[i] < 0 && seq[i-1] < 0)
                    maior_sub = max(seq[i], maior_sub);
                
                else {
                    somatorio += maior_sub;
                    maior_sub = seq[i];
                }

                if (i == x-1)
                    somatorio += maior_sub;
            }
            maior = somatorio;
        }
        cout << maior << "\n";
    }
}
