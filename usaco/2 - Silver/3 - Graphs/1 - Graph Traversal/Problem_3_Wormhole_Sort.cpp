#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


vector<vector<pair<int, int>>> g;
vector<bool> vis;

vector<int> arr;
vector<pair<int, int>> idx;
int n, m;

void dfs(int u, int valor){
    if (!vis[u]) vis[u] = true;

    for (auto [v, w] : g[u]){
        if (!vis[v] && w >= valor){
            dfs(v, valor);
        }
    }
}

bool ok(int mid){

    dfs(idx[0].second, mid);

    for (int i = 0; i < idx.size(); i++){
        if (!vis[idx[i].first-1]) return false;
    }

    return true;
}

void solve(){
    cin >> n >> m;

    arr.resize(n);
    for (auto &i : arr) cin >> i;

    g.resize(n);
    vis.resize(n);
    for (int i = 0; i < m; i++){
        int x, y, valor; cin >> x >> y >> valor;
        x--, y--;

        g[x].push_back({y, valor});
        g[y].push_back({x, valor});
    }

    if (is_sorted(arr.begin(), arr.end())){
        cout << -1 << "\n";
        return;
    }

    for (int i = 0; i < n; i++){
        if (arr[i]-1 != i) idx.push_back({arr[i], i});
    }

    int l = 1, r = 1e9+5;
    while(l < r){
        int mid = l + (r-l+1)/2;

        if(ok(mid)){
            l = mid;
        }
        else r = mid - 1;

        vis.assign(n, false);
    }

    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    solve();
}