#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> v64;
typedef vector<int> v32;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 0x3fffffff
#define LLINF 0x3fffffffffffffff
#define PI 3.14159265358979323846
#define endl '\n'
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fcin                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
template<class T> using ordered_set = 
tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int n,x;
vector<v32> g;
v32 dist;
int ans = 0;

void dist_to(int x) {
    queue<pii> q;
    vector<bool> vis(n);
    q.push({x,0});
    vis[x] = true;
    while (!q.empty()) {
        int p = q.front().F;
        int d = q.front().S;
        q.pop();
        dist[p] = d;
        for (int u : g[p]) {
            if (vis[u]) continue;
            vis[u] = true;
            q.push({u,d+1});
        }
    }
}

void dfs(int u, int p = -1) {
    if (dist[u] == 1) {
        cout << ans+1 << endl;
        exit(0);
    }

    sort(all(g[u]), [](const int a, const int b) {
        return dist[a] > dist[b];
    });
    
    for (int v : g[u]) {
        if (v == p) continue;
        ans++;
        dfs(v,u);
        ans++;
    }
}

void solve() {
    cin>>n>>x;
    x--;
    g.resize(n);
    dist.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dist_to(x);
    dfs(0);
}

int main() {
    fcin;
    solve();
}