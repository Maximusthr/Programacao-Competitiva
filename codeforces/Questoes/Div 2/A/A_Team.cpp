#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    int soma = 0;

    while(t--){
        int a, b, c; cin >> a >> b >> c;

        int aux = a + b + c;

        if (aux >= 2) soma++;
    }
    cout << soma << "\n";
}
