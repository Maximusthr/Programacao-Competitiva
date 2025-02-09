#include <bits/stdc++.h>

using namespace std;

int contador;

int fib(int x){
    contador++;
    if (x <= 1) return x;
    return fib(x-1) + fib(x-2);
}

int main(){
    int qtd; cin >> qtd;
    while(qtd--){
        contador = 0;
        int x; cin >> x;
        int res = fib(x);
        cout << "fib(" << x << ") = " << contador-1 << " calls = " << res << "\n";
    }
}
