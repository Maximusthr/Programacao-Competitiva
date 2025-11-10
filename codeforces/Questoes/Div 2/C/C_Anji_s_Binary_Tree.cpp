#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    struct edge {
        int l, r;
    };

    vector<edge> g(n);

    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        g[i].l = x;
        g[i].r = y;
    }

    int ans = INF;
    
    // so atualizo a resposta se chegar na folha
    auto dfs = [&](auto self, int u, int talvez) -> void {
        if (g[u].l == -1 && g[u].r == -1) ans = min(ans, talvez);

        // se a string for L, eu desço apenas pelos L
        // se R, apenas R
        // se U, é para subir
        // Mas precisamos aplicar o dfs conforme as aplicações
        // Coloquemos L e dfs para o valor a esquerda
        // Se por acaso ja visitamos o nó, precisamos mudar o seu valor de origem.
        
        // Se a string for L ou R, não precisamos mudar para U, basta decrementar talvez

        if (s[u] == 'L' && g[u].l != -1){
            self(self, g[u].l, talvez);
        }
        else if (s[u] == 'R' && g[u].r != -1){
            self(self, g[u].r, talvez);
        }

        if (s[u] == 'L' || s[u] == 'U' && g[u].r != -1){
            self(self, g[u].r, talvez + 1);
        }
        if (s[u] == 'R' || s[u] == 'U' && g[u].l != -1){
            self(self, g[u].l, talvez + 1);
        }

        talvez--;
    };

    dfs(dfs, 0, 0);

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}