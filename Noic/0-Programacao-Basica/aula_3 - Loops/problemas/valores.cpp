#include <iostream>

using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    int maior = x;
    if (y > x){
        maior = y;
        y = x;
        x = maior;
    }

    for (int i = y; i <= maior; i++){
        if (y <= x){
            cout << y << " ";
        }
        y++;
    }
}