#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtd; cin >> qtd;
    while(qtd--){
        int a, b; cin >> a >> b;

        cout << min(a, b) << " " << max(a, b) << "\n";
    }
}