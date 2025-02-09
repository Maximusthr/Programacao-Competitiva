#include <iostream>
using namespace std;

const int MAX = 100000;
int n;
int lista[MAX];

int main(){
    cin >> n;

    int i;
    int soma = 0;
    int aux;
    int j = 0;

    for (i = 0; i < n; i++){
        cin >> aux;
        if (aux != 0){
            lista[j] = aux;
            j++;
            soma += aux;
        } else {
            if (j > 0){
                soma -= lista[j-1];
                j--;
            }
        }
    }

    cout << soma << "\n";
}
