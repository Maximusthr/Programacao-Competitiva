#include <iostream>

using namespace std;

int main(){
    int m, x, y, z = 0;
    cin >> m >> x >> y;

    z = m - (x+y);

    // Variável x sempre será maior
    if (y > x){ 
        int temp = y;
        y = x;
        x = temp;
    }

    if (z <= x){
        z = x;
        cout << z << '\n';
    } else {
        cout << z << '\n';
    }
}