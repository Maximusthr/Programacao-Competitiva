#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int lista[n];
    for (int i = 0; i < n; i++){
        cin >> lista[i];
    }

    // imprimir de maneira inversa.

    for (int i = n - 1; i >= 0; i--){
        cout << lista[i] << " ";
    }

    cout << "\n";
}

// reformulando o código declarando o vetor fora da main

// int n;
// cin >> n;
// int lista[n];

// int main(){
//     for (int i = 0; i < n; i++){
//         cin >> lista[i];
//     }
//     for (Int i = n - 1; i >= 0; i--){
//         cout << lista[i] << " ";
//     }
//     cout << "\n";
// }