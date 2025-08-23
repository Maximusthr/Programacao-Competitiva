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
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define INF 0x3fffffff
#define LLINF 0x3fffffffffffffff
#define PI 3.14159265358979323846
#define endl '\n'
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fast_cin()               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
template<class T> using ordered_set = 
tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int n,m;
vector<vector<pi>> g;
v64 dist;
vector<bool> vis;

int l, r;

ll djk(int x) {
    fill(dist.begin(), dist.end(), LLINF);
    fill(vis.begin(), vis.end(), false);

    dist[0] = 0;
    priority_queue<pl, vector<pl>, greater<pl>> q;
    q.emplace(0, 0);

    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();

        if (vis[u]) continue;
        vis[u] = true;
        if (u == n - 1) break;

        for (auto [v, W] : g[u]) {
            if (W > x) continue;
            if (vis[v]) continue;
            if (w + W < dist[v]) {
                dist[v] = w + W;
                q.emplace(dist[v], v);
            }
        }
    }

    return dist[n - 1];
}

int main() {
    fast_cin()
    cin >> n >> m;

    g.resize(n);
    dist.resize(n);
    vis.resize(n);

    int u,v,w;
    for (int i = 0; i < m; i++) {
        cin>>u>>v>>w;
        u--, v--;
        g[u].emplace_back(v,w);
    }

    
    int l = 1, r = 100100;
    int m;
    ll dis = djk(r);
    while (l < r) {
        m = l+(r-l)/2;
        if (djk(m) == dis) r = m;
        else l = m+1;
    }
    cout << dis << ' ' << l << endl;

    return 0;
}