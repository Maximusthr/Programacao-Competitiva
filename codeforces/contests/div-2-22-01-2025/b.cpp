#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int qtd; cin >> qtd;

    for (int i = 0; i < qtd; i++){
        int n, l, r; cin >> n >> l >> r;
        vector<long long> vetor;
        for (int j = 0; j < n; j++){
            long long aux; cin >> aux;
            vetor.push_back(aux);
        }
        
        int best = 0;
        for (int j = l-1; j < r; j++){
            best += vetor[j];
        }

        int aux = 0, pos = 0, sum = 0, inicio = 0;
        int verificado = 0;
        bool tudo_verificado = false;
        int final = 0, anterior = 0;

        while(true){
            sum += vetor[aux];
            aux++;
            pos++;

            if (pos == r-l+1 || (aux == (int)vetor.size())){
                if (sum < best) best = sum;
                if (aux == (int)vetor.size()) {
                    final++;
                    inicio = 0;
                    aux = inicio;
                    pos++;
                    if (pos == r-l+1) break;
                }
                if ()
                pos = 0;
                sum = 0;
                verificado++;
                inicio++;
                aux = inicio;
            }
        }

        cout << best << "\n";
        
    }
}
