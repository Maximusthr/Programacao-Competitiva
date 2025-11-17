// TO DO LATEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEER


#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct pares {
    ll c;
    ll atual;

    bool operator<(const pares &P) const {
        if (c != P.c) return c < P.c;
        return atual < P.atual;
    };
};

struct DSU {
    vector<int> p, sz, custo;
    vector<pair<int, int>> vizinhos;

    DSU (int n) : p(n), sz(n, 1), custo(n), vizinhos(n) {
        iota(p.begin(), p.end(), 0);
    };

    void build(vector<pares> &c, vector<pair<int, int>> &vizi){
        for (int i = 0; i < c.size(); i++){
            custo[i] = c[i].c;
            vizinhos[i] = {vizi[i].first, vizi[i].second};
        }
    }

    int get(int a){
        if (a != p[a]){
            p[a] = get(p[a]);
        }
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);

        if (a == b) return;

        if (sz[a] > sz[b]){
            swap(a, b);
        }

        if (vizinhos[a].first == b){
            if (vizinhos[b].first == a) vizinhos[b].first = get(vizinhos[a].second);
            else vizinhos[b].second = get(vizinhos[a].second);
        }
        else {
            if (vizinhos[b].first == a) vizinhos[b].first = get(vizinhos[a].first);
            else vizinhos[b].second = get(vizinhos[a].first);
        }

        custo[b] = max(custo[a], custo[b]);
        p[a] = b;
        sz[b] += sz[a];
    }
};

void solve(){
    int n; cin >> n;
    vector<ll> arr(n);
    vector<pares> a;
    vector<pair<int, int>> vizi;

    for (int i = 0; i < n; i++){
        cin >> arr[i];

        if (i == 0) vizi.emplace_back(1, n-1);
        else if (i == n-1) vizi.emplace_back(0, n-2);
        else vizi.push_back({i-1, i+1});

        a.push_back({arr[i], i});
    }

    if (n == 2){
        cout << max(a[0].c, a[1].c) << "\n";
        return;
    }

    
    vector<bool> vis(n);
    
    DSU dsu(n);
    dsu.build(a, vizi);
    
    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i = 0; i < a.size(); i++){
        int local = dsu.get(a[i].atual);

        int atual = dsu.custo[local];

        int left = dsu.get(dsu.vizinhos[local].first);
        int right = dsu.get(dsu.vizinhos[local].second);

        if (vis[atual] && vis[left] && vis[right]) continue;

        // atual é maior que ambos
        if (atual > dsu.custo[left] || atual > dsu.custo[right]){
            if (local == right && local == left) {
                vis[local] = true;
                continue;
            }
            
            if (local == left){
                ans += atual;
                vis[local] = true;
                vis[right] = true;
                dsu.merge(local, right);
                continue;
            }
            else if (local == right){
                ans += atual;
                vis[local] = true;
                vis[left] = true;
                dsu.merge(local, left);
                continue;
            }

            ans += atual;
            vis[local] = true;

            dsu.merge(local, left);
            continue;
        }

        if (dsu.custo[left] > dsu.custo[right]){
            if (atual < dsu.custo[right]){
                ans += atual;
                vis[local] = true;
                vis[right] = true;
                dsu.merge(atual, right);
            }
            else {
                if (local == right){
                    ans += dsu.custo[left];
                    vis[left] = true;
                    dsu.merge(local, left);
                    continue;
                }
                ans += dsu.custo[right];
                vis[right] = true;
                dsu.merge(local, right);
            }
        }
        else {
            if (atual < dsu.custo[left]){
                ans += atual;
                vis[local] = true;
                dsu.merge(atual, left);
            }
            else {
                if (local == left){
                    ans += dsu.custo[right];
                    vis[right] = true;
                    vis[local] = true;
                    dsu.merge(local, right);
                    continue;
                }
                ans += dsu.custo[left];
                vis[left] = true;
                vis[local] = true;
                dsu.merge(local, left);
            }
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}