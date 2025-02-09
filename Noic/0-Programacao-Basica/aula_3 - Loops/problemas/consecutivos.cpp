#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int lista[n], i, count = 0;

    for (i = 0; i < n; i++){
        cin >> lista[i];
    }

    int aux = 0;

    for (i = 0; i < n; i++){
        if (lista[i] != lista[i+1]) aux++;
    }

    int count_aux[aux], j = 0;

    for (i = 0; i < n; i++){
        if (lista[i] == lista[i+1]){
            count++;
        } else {
            count_aux[j++] = count+1; // +1, pois repete o primeiro número inicial.
            count = 0;
        }
    }

    int maior = 0;
    for (i = 0; i < aux; i++){
        if (count_aux[i] > maior) maior = count_aux[i];
    }

    cout << maior << '\n';
}
