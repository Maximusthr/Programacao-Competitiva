#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    while(qtd--){
        int x; cin >> x;
        int aux = 0;
        int aux2 = x;
        if (x >= 10){
            aux = x/10;
            aux2 = x%10;

        }

        cout << aux + aux2 << "\n";
    }
}
