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
        p[b] = p[a];
        sz[a] += sz[b];
    }
};  

int c = 0;
void solve(){
    string s; cin >> s;
    string ori = s;

    DSU dsu(s.size());

    vector<pair<int, int>> queries;
    int q; cin >> q;
    while(q--){
        int x, y; cin >> x >> y;
        queries.push_back({x, y});
        if (x == 2) s[y] = '#';
    }

    for (int i = 0; i < s.size(); i++){
        if (s[i] == '#') continue;

        if (i > 0) {
            if (s[i] == s[i-1]) dsu.merge(i-1, i);
        }
    }

    cout << "Case " << ++c << ":\n";

    vector<int> ans;
    for (int i = queries.size()-1; i >= 0; i--){
        int idx = queries[i].second;
        if (queries[i].first == 1){
            ans.push_back(dsu.sz[dsu.get(idx)]);
        }
        else {
            s[idx] = ori[idx];

            if (idx > 0){
                if (s[idx] == s[idx-1]) dsu.merge(idx, idx-1);
            }
            if (idx + 1 < s.size()){
                if (s[idx] == s[idx+1]) dsu.merge(idx, idx+1);
            }
        }
    }
    
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}