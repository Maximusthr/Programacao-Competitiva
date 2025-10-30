#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 105;

struct DSU {
    vector<int> p;
    vector<int> sz;

    DSU (int n) : p(n), sz(n, 1){
        iota(p.begin(), p.end(), 0);
    };

    int get (int a){
        if (a != p[a]) {
            p[a] = get(p[a]);
        }
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);

        if (sz[a] > sz[b]) {
            swap(a, b);
        }

        p[a] = b;
        sz[b] += sz[a];
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    DSU dsu(MAX);

    vector<pair<int, int>> par(n);
    for (int i = 0; i < n; i++){
        cin >> par[i].first >> par[i].second;
        par[i].first--;
        par[i].second--;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (par[i].first == par[j].first || par[i].second == par[j].second){
                dsu.merge(i, j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (dsu.p[i] == i) ans++;
    }

    cout << ans - 1 << "\n";
}