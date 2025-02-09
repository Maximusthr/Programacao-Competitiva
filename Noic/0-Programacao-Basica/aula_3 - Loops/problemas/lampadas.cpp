#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int x = 0, y = 0;

    for (int i = 0; i < n; i++){
        int interruptor;
        cin >> interruptor;

        if (interruptor == 1){
            x == 0 ? x = 1 : x = 0;
        } else {
            x == 0 ? x = 1 : x = 0;
            y == 0 ? y = 1 : y = 0;
            // if (x == 0) x = 1;
            // else x = 0;
            // if (y == 0) y = 1;
            // else y = 0;
        }
    }
    cout << x << "\n" << y << "\n";
}
