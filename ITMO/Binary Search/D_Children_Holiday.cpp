#include <bits/stdc++.h>

using namespace std;

typedef struct{
    int t;
    int z;
    int y;
}  minutos;

const int MAX = 1e3+1;
int m, n;
vector<minutos> b;
vector<int> qtd(MAX);
vector<int> total(MAX);

// tempo excedente dos baloes

bool ok(int mid){
    int aux = 0;
    int baloes = mid;
    int quantidade = m;

    for (int i = 0; i < b.size(); i++){
        if (mid > b[i].y && mid/b[i].t > b[i].z) baloes -= b[i].y; // se o tempo for maior que o descanso
        baloes /= b[i].t;
        aux += baloes;
        if (aux >= quantidade) aux = quantidade;
        qtd[i] = aux;

        quantidade -= aux;
        if (quantidade <= 0) return true;
        aux = 0;
        baloes = mid;
    }

    return quantidade <= 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    cin >> m >> n;

    for (int i = 0; i < n; i++){
        int t, z, y; cin >> t >> z >> y;
        b.push_back({t, z, y});
    }

    int l = 0, r = 1e9+1;
    while(l < r){
        int mid = l + (r-l)/2;

        if (ok(mid)){
            r = mid;
            for (int i = 0; i < n; i++){
                total[i] = qtd[i];
            }
        }
        else l = mid+1;
    }

    cout << r << "\n";
    for (int i = 0; i < n; i++){
        cout << total[i] << " ";
    }
    cout << "\n";
}
