#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int x, y; cin >> x >> y;
    int copy = y, amount = 0;
    string pass;
    char aux = 'a', temp = 'a';
    for (int i = 0; i < x; i++){
        if (y > 0) {
            pass += aux;
            y--;
            aux++;
            if (aux > 'z') aux = 'a';
        }
        else {
            pass += temp;
            temp++;
            amount++;
            if (temp > 'z' || amount == copy) {
                temp = 'a';
                amount = 0;
            }
        }
    }

    cout << pass << "\n";
}
