#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz, custo;

    DSU (int n) : p(n), sz(n, 1), custo(n) {
        iota(p.begin(), p.end(), 0);
    };

    void build(vector<int> c){
        for (int i = 0; i < (int)c.size(); i++){
            custo[i] = c[i];
        }
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

        custo[b] = min(custo[b], custo[a]);
        sz[b] += sz[a];
        p[a] = b;
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, k, m; cin >> n >> k >> m;

    map<string, int> words;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        words[s] = i;
    }
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    DSU dsu(n);
    dsu.build(v);

    for (int i = 0; i < k; i++){
        int x; cin >> x;
        vector<int> junto;
        for (int j = 0; j < x; j++){
            int y; cin >> y;
            y--;
            junto.push_back(y);
        }
        for (int j = 1; j < (int)junto.size(); j++){
            dsu.merge(junto[j], junto[j-1]);
        }
    }

    vector<string> resp(m);
    for (auto &i : resp) cin >> i;

    ll ans = 0;
    for (int i = 0; i < m; i++){
        ans += dsu.custo[dsu.get(words[resp[i]])];
    }

    cout << ans << "\n";
}