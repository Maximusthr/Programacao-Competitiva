#include <iostream>

using namespace std;

int main(){
    int l, c;
    cin >> l >> c;

    if (l % 2 == 0){
        if (c % 2 == 0) cout << "1 \n";
        else cout << "0 \n";
    } else {
        if (c % 2 == 0) cout << "0 \n";
        else cout << "1 \n";
    }
}