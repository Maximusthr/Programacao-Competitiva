#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int qtd; cin >> qtd;
    for (int i = 0; i < qtd; i++){
        long long a, b; cin >> a >> b;
        int soma = 0;
        
        if (b == b - (a % b)) cout << 0 << "\n";
        else cout << b - (a % b) << "\n";
    }
}
