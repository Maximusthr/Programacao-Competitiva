#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    while(qtd--){
        int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
        int soma = 0;


        if (a1 > b1 && a2 >= b2) soma += 2;
        else if (a1 >= b1 && a2 > b2) soma += 2;
        if (a1 > b2 && a2 >= b1) soma += 2;
        else if (a1 >= b2 && a2 > b1) soma += 2;

        cout << soma << "\n";
    }

}
