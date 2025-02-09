#include <iostream>

using namespace std;

int main(){
    int n, i, x = 0, soma = 0; 
    cin >> n;

    for (i = 0; i < n; i++){
        cin >> x;
        soma += x; 
    }

    cout << soma << '\n';
}