#include <iostream>

using namespace std;

int main(){
    // x > 0 && y > 0 = 1º
    // x < 0 && y > 0 = 2º
    // x < 0 && y < 0 = 3º
    // x > 0 && y < 0 = 4º
    // x == 0 || y == 0 -> eixos
    int x, y;
    cin >> x >> y;

    if (x > 0 && y > 0){
        cout << "Q1" << "\n";
    } else if (x < 0 && y > 0){
        cout << "Q2" << "\n";
    } else if (x < 0 && y < 0){
        cout << "Q3" << "\n";
    } else if (x > 0 && y < 0){
        cout << "Q4" << "\n";
    } else {
        cout << "eixos" << "\n";
    }
}