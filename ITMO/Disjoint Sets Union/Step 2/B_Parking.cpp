#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz, valor;

    DSU (int n) : p(n), sz(n, 1), valor(n){
        iota(p.begin(), p.end(), 0);
        iota(valor.begin(), valor.end(), 0);
    };

    int get(int a){
        if (a != p[a]) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);
        if (a == b) return;

        if (sz[a] > sz[b]) swap(a, b);

        sz[b] += sz[a];
        p[a] = p[b];
    }
};

void solve(){
    int n; cin >> n;
    
    DSU dsu(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        x--;

        int v = dsu.get(x);

        cout << dsu.valor[v] + 1 << " \n"[i == n-1];
    
        dsu.valor[v] = dsu.valor[dsu.get((dsu.valor[v] + 1) % n)];
        dsu.merge(v, dsu.valor[v]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}