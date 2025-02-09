#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> vetor;
vector<int> premiacoes;

// meu metodo
int buscab(int x, int y){
    int ini = 0, fim = x;
    int meio;
    
    int ans = 0;
    while(ini <= fim){
        meio = (ini+fim)/2;
        if (meio >= x) break;
        if (y >= vetor[meio]) {
            ans = meio+1;
            ini = meio+1;
        } else {
            fim = meio-1;
        }
    }
    return premiacoes[ans];
}

//lower bound
// ll buscab(int x, int y){
//     int ini = 0, fim = x;
//     int meio;
    
//     int ans = -1;
//     while(ini <= fim){
//         meio = (ini+fim)/2;
//         if (vetor[meio] > y) {
//             ans = meio;
//             fim = meio-1;
//         } else {
//             ini = meio+1;
//         }
//     }
//     if (ans == -1) ans = x;
//     return premiacoes[ans];
// }

int main(){
    int x, y; cin >> x >> y;

    // intervalo de premiacoes
    for(int i = 0; i < x-1; i++){
        int aux; cin >> aux;
        vetor.push_back(aux);
    }

    // valores das premiacoes
    for (int i = 0; i < x; i++){
        int aux; cin >> aux;
        premiacoes.push_back(aux);
    }

    // valores das forcas dos ogros
    vector<int> forca;
    for (int i = 0; i < y; i++){
        int aux; cin >> aux;
        forca.push_back(aux);
    }
    
    for (int i = 0; i < y; i++){
        if (i == y - 1) cout << buscab(x-1, forca[i]) << "\n";
        else cout << buscab(x-1, forca[i]) << " ";
    }
}
