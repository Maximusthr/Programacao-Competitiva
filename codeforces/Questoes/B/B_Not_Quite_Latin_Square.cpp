#include <bits/stdc++.h>

using namespace std;

int main(){

    int t; cin >> t;

    while(t--){
        map<char, int> letras;
        for (int i = 0; i < 9; i++){
            char aux;
            cin >> aux;
            if (aux == '?') continue;
            letras[aux]++;
        }

        char menor;
        int num = 4;
        for (auto [x, y] : letras){
            if (num > y) {
                num = y;
                menor = x;
            }
        }

        cout << menor << "\n";
    }
}
