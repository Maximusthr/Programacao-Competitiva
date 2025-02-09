//Exercício que não consegui fazer no simulado da OBI 2024

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1001;
int lista[MAX][MAX];

int main(){
    int s, t; cin >> s >> t;
    
    while(t--){
        int x, y; cin >> x >> y;
        lista[x][y] = 1;
        lista[y][x] = 1;
    }

    int p; cin >> p;
    int ans = 0, aux = 0;
    while(p--){
        int n; cin >> n;
        vector<int> sugestao;
        for (int i = 0; i < n; i++){
            int c; cin >> c;
            sugestao.push_back(c);
        }
        for (int i = 0; i < n; i++){
            if (i+1 == n) break; // i+1 > n não tem nada para ler.
            else if (lista[sugestao[i]][sugestao[i+1]] && lista[sugestao[i+1]][sugestao[i]]) aux++;
        }
        if (aux == n-1) ans++;
        aux = 0;
    }

    cout << ans << "\n";
}

