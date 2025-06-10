#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int x, y; cin >> x >> y;
 
    vector<long long> vetor;
    for (int i = 0; i < x; i++){
        int aux; cin >> aux;
        vetor.push_back(aux);
    }
 
    vector<long long> auxiliar = vetor;
 
    auxiliar[0] = vetor[0];
    for (int i = 1; i < x; i++){
        auxiliar[i] = auxiliar[i-1] + vetor[i];
    }
 
    for (int i = 0; i < y; i++){
        int a, b; cin >> a >> b;
        long long resultado = 0;
 
        if (a > 1) resultado = auxiliar[b-1] - auxiliar[a-2];
        else resultado = auxiliar[b-1];
 
        cout << resultado << "\n";
    }
}