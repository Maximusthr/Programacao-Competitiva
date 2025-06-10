#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+1;
vector<int> g[MAX];
vector<int> sum(MAX);

void dfs(int u, int e){
    sum[u] = 1;

    for (auto v : g[u]){
        if (v == e) continue;
        dfs(v, u);
        sum[u] += sum[v];
    }
}

void solve(){
    int n; cin >> n;

    int id = 2;
    for (int i = 0; i < n-1; i++){
        int x; cin >> x;
        g[x].push_back(id);
        id++;
    }
    dfs(1, -1);

    for (int i = 1; i <= n; i++){
        cout << sum[i] - 1 << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    solve();
}
