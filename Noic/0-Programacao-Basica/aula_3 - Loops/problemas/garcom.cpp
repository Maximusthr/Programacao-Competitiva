#include <iostream>

using namespace std;

int main(){
    int n, x = 0, y = 0, soma = 0;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> x >> y;
        if (x > y){
            soma += y;
        }
    }

    cout << soma << "\n";
}