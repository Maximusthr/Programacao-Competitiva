#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct DSU{
    vector<int> p, sz;
    int comp;
    
    DSU (int n) : p(n), sz(n, 1){
        iota(p.begin(), p.end(), 0);
        comp = n;
    }

    int get(int a){
        if (p[a] != a) p[a] = get(p[a]);
        return p[a];
    }

    void merge(int a, int b){
        a = get(a);
        b = get(b);
        if (a == b) return;
        if (sz[a] > sz[b]) swap(a, b);
        sz[b] += sz[a];
        p[a] = p[b];
        comp--;
    }
};

void solve(){
    int n; cin >> n;

    n *= 2;

    string s; cin >> s;
    stack<int> foi;

    DSU dsu(n);

    int k = 0, l = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '('){
            foi.push(i);
        }
        else {
            int u = foi.top();
            dsu.merge(u, i);
            foi.pop();


            // )(
            if (u > 0 && s[u-1] == ')'){
                dsu.merge(u-1, u);
            }
        }
    }

    cout << dsu.comp << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}