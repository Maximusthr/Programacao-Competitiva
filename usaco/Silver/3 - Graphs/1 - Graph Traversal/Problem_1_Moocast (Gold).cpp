#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n;
const int MAX = 1005;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

struct coord {
    int x, y;
};
vector<coord> cows(n);

void dfs(int u, int m){
    if (!vis[u]) vis[u] = true;

    for (auto v : g[u]){
        int dist = (cows[v].x - cows[u].x) * (cows[v].x - cows[u].x) + (cows[v].y - cows[u].y) * (cows[v].y - cows[u].y);
        if (!vis[v] && dist <= m){
            dfs(v, m);
        }
    }
}

void solve(){
    cin >> n;
    cows.resize(n);

    for (int i = 0; i < n; i++){
        cin >> cows[i].x >> cows[i].y;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            g[i].push_back(j);
        }
    }

    int l = 0, r = 1e9;
    while (l < r){
        int mid = l + (r-l)/2;

        dfs(0, mid);

        bool ok = true;
        for (int i = 0; i < n; i++){
            if (!vis[i]) {
                ok = false;
                break;
            }
        }
        vis.assign(MAX, false);

        if (ok) r = mid;
        else l = mid + 1;
    }

    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    solve();
}