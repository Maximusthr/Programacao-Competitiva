#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
vector<int> comp;
map<int, char> idx;

int maior = 0;

void dfs(int u, int c){

    if (comp[u] == -1) comp[u] = c;

    for (auto v : g[u]){
        if (idx[v] != idx[u] && comp[v] == -1){
            maior = max(maior, c);
            maior++;
            dfs(v, maior);
        }
        else if (idx[v] == idx[u] && comp[v] == -1){
            dfs(v, c);
        }
    }
}

void solve(){
    int n, q; cin >> n >> q;

    g.resize(n);
    comp.resize(n, -1);

    string s; cin >> s;

    for (int i = 0; i < s.size(); i++){
        idx[i] = s[i];
    }

    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, 0);

    while(q--){
        int x, y; cin >> x >> y;
        char c; cin >> c;

        x--, y--;
        if (comp[x] != comp[y]) cout << 1;
        else if (c == idx[x]) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    solve();
}