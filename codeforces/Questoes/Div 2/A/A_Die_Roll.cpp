#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int x, y; cin >> x >> y;
    int dado = 6;
    int aux = dado - max(x, y) + 1;
    if (dado % aux == 0){
        dado /= aux;
        aux /= aux;
    }
    if (aux == 4){
        aux /= 2;
        dado /= 2;
    }
    cout << aux << "/" << dado << "\n";
}
