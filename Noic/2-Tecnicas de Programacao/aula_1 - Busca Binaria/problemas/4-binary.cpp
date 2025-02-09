#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> vetor;
int x, y;
ll aux;

// bool buscaelem(ll elem){
//     int ini = 0, fim = x;
//     int meio;
    
//     while(ini <= fim){
//         meio = (ini + fim)/2;
//         if (vetor[meio] == elem) return true;
//         else if (vetor[meio] > elem) fim = meio-1;
//         else if(vetor[meio] < elem) ini = meio+1; 
//     }

//     return false;
// }

ll buscab(ll elem){
    int ini = 0, fim = x;
    int meio;
    int ans = -1;

    while(ini <= fim){
        meio = ini+((fim-ini)/2);
        if (vetor[meio] >= elem) {
            ans = meio;
            fim = meio-1;
        }
        else if (vetor[meio] < elem) {
            ini = meio+1;
        }
    }
    
    if (vetor[meio] != elem) {
        if (vetor[meio+1] == elem) ans = meio+1;
        else ans = -1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> x >> y;

    for (int i = 0; i < x; i++){
        ll elem; cin >> elem;
        vetor.push_back(elem);
    }

    for (int i = 0; i < y; i++) {
        cin >> aux;
        //bool ok = binary_search(vetor.begin(), vetor.end(), aux);
        //bool ok = buscaelem(aux);
        //if (ok) {
            // auto it = lower_bound(vetor.begin(), vetor.end(), aux);
            // cout << it - vetor.begin() << "\n";
        cout << buscab(aux) << "\n";
        //}
        //else cout << -1 << "\n";
    }
}
