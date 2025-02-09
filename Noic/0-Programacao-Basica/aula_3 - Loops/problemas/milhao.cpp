#include <iostream>

using namespace std;

int main(){
    int n, x = 0;
    cin >> n;

    bool aux = true;
    int dia, soma = 0;

    for (int i = 0; i < n; i++){
        cin >> x;
        soma += x;
        if (aux){
            if (soma >= 1000000){
                dia = i;
                aux = false;
            }
        }
    }
    cout << dia + 1 << '\n';
}
