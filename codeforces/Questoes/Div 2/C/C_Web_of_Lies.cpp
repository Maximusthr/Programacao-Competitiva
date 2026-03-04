#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    int nob = n;
    set<int> removed;
    vector<set<int>> g(n);
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        if (x > y) swap(x, y);

        g[x].insert(y);
        if (g[x].size() > 0 && !removed.count(x)) {
            nob--;
            removed.insert(x);
        }
    }

    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if (x == 1){
            int u, v; cin >> u >> v;
            u--, v--;
            if (u > v) swap(u, v);
            g[u].insert(v);
            if (g[u].size() > 0 && !removed.count(u)) {
                nob--;
                removed.insert(u);
            }
        }
        else if (x == 2){
            int u, v; cin >> u >> v;
            u--, v--;
            if (u > v) swap(u, v);
            g[u].erase(v);
            if (g[u].size() == 0 && removed.count(u)) {
                nob++;
                removed.erase(u);
            }
        }
        else {
            cout << nob << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}