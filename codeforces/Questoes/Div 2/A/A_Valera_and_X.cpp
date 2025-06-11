#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int x; cin >> x;

    char matriz[x][x];
    map<char, int> qtd;
    for (int i = 0; i < x; i++){
        for (int j = 0; j < x; j++){
            cin >> matriz[i][j];
            qtd[matriz[i][j]]++;
        }
    }

    //verifying diagonals

    bool ok = true;
    char aux;
    for (int i = 0, j = 0; i < x-1; i++, j++){
        if (matriz[i][j] != matriz[i+1][j+1]) ok = false;
        aux = matriz[i][j];
    }
    for (int i = 0, j = x-1; i < x; i++, j--){
        if (matriz[i][j] != matriz[i+1][j-1]) ok = false;
    }
    
    if (qtd[aux] != x*2 - 1) ok = false;
    if (!ok || (int)qtd.size() > 2 || (int)qtd.size() == 1) cout << "NO" << "\n";
    else {
        cout << "YES" << "\n";
    }
}
