#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz, x, y;

    DSU (int n) : p(n), sz(n, 1), x(n), y(n) {
        iota(p.begin(), p.end(), 0);
    };

    int get (int a){
        if (a != p[a]) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);
        if (a == b) return;

        if (sz[a] > sz[b]) swap(a, b);

        p[a] = b;
        sz[b] += sz[a];
        x[b] += x[a];
        y[b] += y[a];
    }
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, a, b; cin >> n >> a >> b;

    vector<int> arr(n);
    map<int, int> ID;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        ID[arr[i]] = i;
    }

    // 0 pertence a A
    // 1 pertence a B
    
    DSU dsu(n);

    for (int i = 0; i < n; i++){
        if (ID.count(a - arr[i])){
            dsu.merge(i, ID[a - arr[i]]);

            dsu.x[dsu.get(i)]++;
        }
        if (ID.count(b - arr[i])){
            dsu.merge(i, ID[b - arr[i]]);

            dsu.y[dsu.get(i)]++;
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++){
        if (dsu.sz[dsu.get(i)] == dsu.x[dsu.get(i)]) ans.push_back(0);
        else if (dsu.sz[dsu.get(i)] == dsu.y[dsu.get(i)]) ans.push_back(1);
        else {
            cout << "NO" << "\n";
            return 0;
        }
    }

    cout << "YES" << "\n";
    for (auto &i : ans) cout << i << " ";
    cout << "\n";
}