//Zero para cancelar utilizando vector

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;

    vector<int> lista;

    while(n--){
        int x; cin >> x;
        if (x == 0) lista.pop_back();
        else lista.push_back(x);
    }

    int soma = 0;

    for (int i = 0; i < (int)lista.size(); i++){
        soma += lista[i];
    }

    cout << soma << "\n";
}