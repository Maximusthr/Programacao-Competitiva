#include <bits/stdc++.h>

using namespace std;

int qtd;
int aux;

vector<int> numeros;

int solve(int n, int k){
    numeros.push_back(n);
    if (n > k){
        int aux = n - n/2;
        n /= 2;
        numeros.push_back(aux);
    }
    for (int i = 0; i < numeros.size(); i++){
        if (numeros[i] <= k) qtd++;
        if (i == numeros.size()-1) return qtd;
    }
    return solve(n, k);
}

int main(){
    int n, k;
    while(cin >> n >> k && n && k){
        qtd = 0;
        int res = solve(n, k);
        cout << qtd << '\n';
    }
}
