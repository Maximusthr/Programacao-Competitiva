#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> boss, dist;

    DSU (int n) : boss(n), dist(n){
        iota(boss.begin(), boss.end(), 0);
    }

    int get(int a){
        if (a == boss[a]) return a;
        int b = boss[a];
        boss[a] = get(b);
        dist[a] += dist[b];
        return boss[a];
    }

    int find_boss(int a){
        get(a);
        return dist[a];
    }

    void merge(int a, int b){
        boss[a] = b;
        dist[a] = 1;
    }
};

void solve(){
    int n, q; cin >> n >> q;

    DSU dsu(n);
    while(q--){
        int x; cin >> x;
        if (x == 1){
            int a, b; cin >> a >> b;
            a--, b--;

            dsu.merge(a, b);
        }
        else {
            int a; cin >> a;
            a--;

            cout << dsu.find_boss(a) << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}