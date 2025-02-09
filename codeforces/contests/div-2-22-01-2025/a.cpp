#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd;
    cin >> qtd;

    for (int i = 0; i < qtd; i++){
        int x, y; cin >> x >> y;

        if (x == 1 && y == 1){
            cout << 1 << "\n";
        } else cout << y-x << "\n";
    }
}
