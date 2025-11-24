#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz, maior;

    DSU(int n) : p(n+1), sz(n, 1), maior(n+1){
        iota(p.begin(), p.end(), 0);
        iota(maior.begin(), maior.end(), 0);
    }

    int get(int a){
        if (p[a] != a){
            p[a] = get(p[a]);
        }
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);

        if (a == b){
            return;
        }

        if (sz[a] > sz[b]) swap(a, b);

        p[a] = b;
        sz[b] += sz[a];
        maior[b] = max(maior[b], maior[a]);
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    DSU dsu(n);

    while(m--){
        char c; cin >> c;
        int x; cin >> x;
        x--;

        if (c == '?'){
            int v = dsu.get(x);

            if (dsu.maior[v] == n) {
                cout << -1 << "\n";
                continue;
            }
            else {
                cout << dsu.maior[v] + 1 << "\n";
            }
        }
        else {
            dsu.merge(x, dsu.get(dsu.maior[x+1]));
        }
    }
}