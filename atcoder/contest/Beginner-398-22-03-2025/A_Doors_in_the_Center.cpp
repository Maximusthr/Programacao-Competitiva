#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int x; cin >> x;

    string y;

    if (x % 2 == 0) {
        for (int i = 0; i < x/2-1; i++){
            y += '-';
        }

        y += '=';
        y += '=';

        for (int i = x/2+1; i < x; i++){
            y += '-';
        }
    }
    else {
        for (int i = 0; i < x/2; i++){
            y += '-';
        }

        y += '=';

        for (int i = x/2 + 1; i < x; i++){
            y += '-';
        }
    }

    cout << y << "\n";
}
