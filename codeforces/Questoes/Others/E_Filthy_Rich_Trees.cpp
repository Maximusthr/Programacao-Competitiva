#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct BIT {
    int n;
    vector<double> bit;

    BIT (int _n) : n(_n), bit(n) {}

    void update(int i, double v){
        for (i++; i <= n; i += i & -i){
            bit[i] += v;
        }
    }

    double sum(int i){
        double ret = 0;
        for (i++; i; i -= i & -i){
            ret += bit[i];
        }
        return ret;
    }

    double query(int l, int r){
        return sum(r) - sum(l-1);
    }
};

void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<int> start(n), end(n);
    int time = 0;
    auto dfs = [&](auto &&self, int u, int p) -> void {
        start[u] = time++;
        for (auto v : g[u]){
            if (v == p) continue;
            self(self, v, u);
        }
        end[u] = time;
    };

    dfs(dfs, 0, -1);

    vector<double> valor(n, log(1));

    BIT bit(n);
    int q; cin >> q;
    while(q--){
        int t; cin >> t;
        int x, y; cin >> x >> y;
        x--;

        if (t == 1){
            double v = log(y);

            bit.update(start[x], v - valor[x]);
            valor[x] = v;
        }
        else {
            y--;
            double v = bit.query(start[x], end[x] - 1);
            double w = bit.query(start[y], end[y] - 1);

            double z = v - w;

            cout << fixed << setprecision(10);

            if (z > log(1e9)) cout << 1e9 << "\n";
            else cout << exp(z) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}