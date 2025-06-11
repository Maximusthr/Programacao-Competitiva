#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;

    for (int i = 0; i < qtd; i++){
        int x, n, m; cin >> x >> n >> m;

        while (m * 10 < x && n > 0){
            x = x/2;
            x += 10;
            n--;
        }

        if (m*10 >= x) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}
