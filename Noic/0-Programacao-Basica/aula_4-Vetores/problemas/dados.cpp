#include <iostream>

using namespace std;

const int MAX = 13;
int lista[MAX];

int main(){
    int n; cin >> n;
    int i;

    for (i = 0; i < n; i++){
        int x; cin >> x;
        lista[x] += 1;
    }
    
    int maior = 1;

    for (i = 0; i < MAX; i++){
        if (lista[i] > maior){
            maior = lista[i];
        }
    }

    for (i = 0; i < MAX; i++){
        if (lista[i] == maior){
            cout << i << " ";
        }
    }
    cout << "\n";
}
