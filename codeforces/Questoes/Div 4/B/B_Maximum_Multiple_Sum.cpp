#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    while(qtd--){
        int x; cin >> x;

        if (x == 1) cout << 1 << "\n";
        if (x == 3) cout << x << "\n";
        else cout << 2 << "\n";
    }
}