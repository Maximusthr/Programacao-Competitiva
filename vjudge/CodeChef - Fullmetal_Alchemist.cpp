#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p;
    vector<int> sz;

    DSU (int n) : sz(n, 1), p(n){
        iota(p.begin(), p.end(), 0);
    };

    int get(int a){
        if (a != p[a]) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);
        if (a == b) return;
        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        sz[b] += sz[a];
        p[a] = b;
    }
};

struct Edge{
    int u, v, w;

    bool operator<(Edge const P) const {
        return w < P.w;
    };
};

void solve(){
    int n, m; cin >> n >> m;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    DSU dsu(n);
    vector<Edge> edg;

    for (int i = 0; i < n; i++){
        for (int k = i + 1; k < n; k++){
            int w = 0;
            for (int j = 0; j < m; j++){
                w = max(w, abs(arr[i][j] - arr[k][j])); 
            }
            edg.push_back({i, k, w});
        }
    }

    sort(edg.begin(), edg.end());

    int maior = 0;
    for (int i = 0; i < edg.size(); i++){
        auto [u, v, w] = edg[i];

        u = dsu.get(u);
        v = dsu.get(v);
        if (u == v) continue;

        dsu.merge(u, v);
        maior = max(maior, w);
    }

    cout << maior << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}