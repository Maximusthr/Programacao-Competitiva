#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> sz;
    vector<int> p;

    DSU (int n) : sz(n, 1), p(n) {
        iota(p.begin(), p.end(), 0);
    };

    int get(int a){
        if (a != p[a]){
            p[a] = get(p[a]);
        }
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);

        if (a == b) return;

        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<vector<int>> g(m);
    vector<int> count(n);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        for (int j = 0; j < x; j++){
            int y; cin >> y;
            y--;
            g[y].push_back(i);
            count[i]++;
        }
    }

    DSU vec(n);

    for (int i = 0; i < m; i++){
        for (int j = 1; j < g[i].size(); j++){
            vec.merge(g[i][j], g[i][j-1]);
        }
    }

    set<int> grupos;
    int sum = 0;
    for (int i = 0; i < n; i++){
        if (count[i] == 0) {
            sum++;
            continue;
        }
        grupos.insert(vec.get(i));
    }

    if (grupos.size() > 0) sum += grupos.size() - 1;

    cout << sum << "\n";
}