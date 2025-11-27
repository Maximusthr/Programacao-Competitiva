#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz;

    DSU (int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

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

struct Edge {
    int x, y, w;

    bool operator<(Edge &E) const {
        return w < E.w;
    }
};

void solve(){
    int n, m; cin >> n >> m;

    vector<Edge> arr;
    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;

        arr.push_back({x, y, w});
    }

    sort(arr.begin(), arr.end());

    int ans = 0;
    
    DSU dsu(n);

    for (int i = 0; i < m; i++){
        if (dsu.get(arr[i].x) != dsu.get(arr[i].y)){
            dsu.merge(arr[i].x, arr[i].y);
            ans = max(ans, arr[i].w);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}