#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

struct DSU {
    vector<int> p, sz;
    int comp;
    
    DSU (int n) : p(n), sz(n, 1) {
        iota(p.begin(), p.end(), 0);
        comp = n;
    };

    int get(int a){
        if (a != p[a]) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a), b = get(b);
        if (a == b) return;

        if (sz[a] > sz[b]) swap(a, b);
        p[a] = b;
        sz[b] += sz[a];
        comp--;
    }
};

ll binpow(ll a, ll b){
    ll x = 1;
    while(b > 0){
        if (b & 1) x = x * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return x;
}

void solve(){
    ll n, m, k; cin >> n >> m >> k;

    DSU dsu(n);

    int qtd = 0;
    for (int i = 0; i < n; i++){
        qtd++;
        if (qtd == k){
            int j = i - k + 1;
            int l = i;
            while(j <= l){
                dsu.merge(j, l);
                j++;
                l--;
            }
            qtd--;
        }
    }

    cout << binpow(m, dsu.comp) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}