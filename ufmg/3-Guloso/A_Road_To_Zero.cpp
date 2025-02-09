#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;

    for (int i = 0; i < qtd; i++){
        long long x, y; cin >> x >> y;
        long long a, b; cin >> a >> b;

        long long menor = min(x, y);
        long long dinheiro = 0;
        long long alternado = 0;

        alternado = (x+y) * a;

        if (y > x) dinheiro += a * (y-x);
        else if (x > y) dinheiro += a * (x-y);
        dinheiro += b * menor;

        cout << min(alternado, dinheiro) << "\n";
    }
}
