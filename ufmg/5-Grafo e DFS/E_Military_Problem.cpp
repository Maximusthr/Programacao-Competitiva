#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+1;
vector<int> g[MAX];
vector<int> sum(MAX);

vector<int> elem;

void dfs(int u, int e){
    sum[u] = 1;

    elem.push_back(u);

    for (auto v : g[u]){
        if (v == e) continue;
        dfs(v, u);
        sum[u] += sum[v];
    }
}

void solve(){
    int n, q; cin >> n >> q;

    int id = 2;
    for (int i = 0; i < n-1; i++){
        int x; cin >> x;
        g[x].push_back(id);
        id++;
    }
    dfs(1, -1);

    vector<int> index(n+1);
    for (int i = 1; i <= n; i++){
        index[elem[i-1]] = i;
    }

    while(q--){
        int of, pos; cin >> of >> pos;

        if (sum[of] < pos) cout << -1 << "\n";
        else {
            int pos_elem = index[of] + pos - 2;
            cout << elem[pos_elem] << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    solve();
}
