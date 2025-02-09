#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int soma = 0;

    vector<int> tempo;

    int i;
    for (i = 0; i < n; i++){
        int x; cin >> x;
        tempo.push_back(x);
    }

    for (i = 0; i < n; i++){
        if (i+1 >= n) break;
        else if (tempo[i+1] - tempo[i] >= 10) soma += 10;
        else soma += tempo[i+1] - tempo[i];
    }
    soma += 10; // acrescenta-se 10 segundos para o tempo final.

    cout << soma << "\n";
}
