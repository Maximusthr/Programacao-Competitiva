#include <iostream>

using namespace std;


int main(){
    int x;
    cin >> x;
    int aux = x;

    if (x == 0){
        cout << "1 \n";
    } else if (x == 1){
        cout << "1 \n";
    } else {
        int soma = 1;
        for (int i = 0; i < aux; i++){
            if (x == 0){
                break;
            }
            soma = soma*x;
            x--;
        }
        cout << soma << "\n";
    }
}
   