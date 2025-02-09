#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int lista[n];
    int lista_aux[n];

    for (int i = 0; i < n; i++){
        cin >> lista[i];
    }

    for (int i = 0; i < n; i++){
        int aux = 1e9;
        for (int j = i, k=0; j < n; j++){
            if (lista[j] != 0) {
                k++;
            } else {
                aux = k;
                break;
            }
        }

        int aux2 = 1e9;
        for (int j = i, k = 0; j >= 0; j--){
            if (lista[j] != 0){
                k++;
            } else {
                aux2 = k;
                break;
            }
        }
        
        lista_aux[i] = min(aux, aux2);
    }

    for (int i = 0; i < n; i++){
        cout << ((lista_aux[i] > 9) ? 9 : lista_aux[i]) << " ";
    }
    cout << "\n";
}
