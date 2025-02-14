#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string x; cin >> x;

    int soma = 1;
    int maior = 1;
    for (int i = 1; i < (int)x.size(); i++){
        if (x[i] == x[i-1]) soma++;
        if (x[i] != x[i-1] || i == (int)x.size()-1){
            if (soma > maior) maior = soma;
            soma = 1;
        }
    }
    cout << maior << "\n";
}
