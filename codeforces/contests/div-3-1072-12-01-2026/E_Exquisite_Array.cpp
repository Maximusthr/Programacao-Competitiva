#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU {
    vector<int> p, sz;

    DSU (int n) : p(n), sz(n, 1) {
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
        sz[b] += sz[a];
        p[a] = p[b];
    }
};

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<vector<int>> k(n);
    DSU dsu(n);

    for (int i = 1; i < n; i++){
        k[abs(arr[i] - arr[i-1])].push_back(i);
        k[abs(arr[i] - arr[i-1])].push_back(i-1);
    }

    vector<ll> ans(n);
    ll sum = 0;
    for (int i = n-1; i >= 1; i--){
        for (int j = 0; j < k[i].size(); j += 2){
            int x = dsu.get(k[i][j]);
            int y = dsu.get(k[i][j+1]);

            sum -= (1ll * dsu.sz[x] * (dsu.sz[x] - 1)/2);
            sum -= (1ll * dsu.sz[y] * (dsu.sz[y] - 1)/2);
            dsu.merge(x, y);
            sum += 1ll * dsu.sz[dsu.get(x)] * (dsu.sz[dsu.get(x)] - 1)/2;
        }
        ans[i] = sum;
    }

    for (int i = 1; i < n; i++){
        cout << ans[i] << " \n"[i+1 == n];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}