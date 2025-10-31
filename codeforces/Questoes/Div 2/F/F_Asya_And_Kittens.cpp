#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz;

    vector<vector<int>> v;

    DSU(int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
        v.resize(n);
        for (int i = 0; i < n; i++){
            v[i].push_back(i);
        }
    };

    int get(int a){
        while (a != p[a]){
            a = p[a];
        }
        return a;
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);

        if (a == b) return;

        if (sz[a] > sz[b]) swap(a, b);

        p[a] = b;
        sz[b] += sz[a];

        for (int i = 0; i < sz[a]; i++){
            v[b].push_back(v[a][i]);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    
    DSU dsu(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        dsu.merge(x, y);
    }

    int x = dsu.get(0);
    for (int i = 0; i < dsu.sz[x]; i++){
        cout << dsu.v[x][i] + 1 << " \n"[i==dsu.sz[x]];
    }
}