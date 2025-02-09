#include <iostream>

using namespace std;

int main(){
    //media ponderada
    double x, y, media;
    cin >> x >> y;
    
    media = ((x*2) + (y*3)) / (2+3); // media ponderada (pesos 2 e 3)

    if (media >= 7){
        cout << "Aprovado" << "\n";
    } else if (media >= 3){
        cout << "Final" << "\n";
    } else {
        cout << "Reprovado" << "\n";
    }
}