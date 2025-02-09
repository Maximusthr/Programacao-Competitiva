#include <iostream>

using namespace std;

int main(){
    double x, y, media;

    cin >> x >> y;

    media = (x + y)/2;

    if (media >= 7){
        cout << "Aprovado" << endl;
    } else if (media >= 4){
        cout << "Recuperacao" << endl;
    } else {
        cout << "Reprovado" << endl;
    }
}