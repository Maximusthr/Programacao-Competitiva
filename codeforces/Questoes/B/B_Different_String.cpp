#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    while(qtd--){
        string x; cin >> x;
        bool dif = false;
        char letra = x[0];

        int pos = 0;
        for (int i = 0; i < (int)x.size(); i++){
            if (letra != x[i]){
                dif = true;
                pos = i;
                break;
            }
        }

        if (dif) {
            cout << "YES" << "\n";
            char temp = x[pos];
            x[pos] = letra;
            x[0] = temp;
            cout << x << "\n";
        }
        else cout << "NO" << "\n";
    }
}