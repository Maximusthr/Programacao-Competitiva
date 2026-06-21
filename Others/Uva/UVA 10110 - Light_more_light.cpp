#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    long long qtd;
    while(cin >> qtd && qtd){
        int aux = sqrt(qtd);
        if (aux == sqrt(qtd)) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}
