#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz, black, white;

    DSU (int n) : p(n), sz(n, 1), black(n), white(n, 1){
        iota(p.begin(), p.end(), 0);
    };

    int get(int a){
        if (a != p[a]) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a), b = get(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        white[b] += white[a];
        black[b] += black[a];
        sz[b] += sz[a]; 
        p[a] = b;
    }

    void tipo(int a, int v){
        a = get(a);
        if (v == 1) {
            white[a]--;
            black[a]++;
        }
        else {
            white[a]++;
            black[a]--;
        }
    }
};

void solve(){
    int n, q; cin >> n >> q;

    DSU dsu(n);

    vector<int> tipo(n, 1);
    while(q--){
        int x; cin >> x;

        if (x == 1){
            int a, b; cin >> a >> b;
            a--, b--;
            dsu.merge(a, b);
        }
        else if (x == 2){
            int y; cin >> y;
            y--;

            if (tipo[y] == 1) {
                tipo[y] = 0;
                dsu.tipo(y, 1);
            }
            else {
                tipo[y] = 1;
                dsu.tipo(y, 0);
            }
        }
        else {
            int y; cin >> y;
            y--;

            if (dsu.black[dsu.get(y)] > 0 && dsu.white[dsu.get(y)] >= 0){
                cout << "Yes" << "\n";
            }
            else cout << "No" << "\n";
        }
    }   
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}