#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+1;

vector<vector<int>> g(MAX);
vector<int> c(MAX, -1);

void dfs(int u, int color){
    if (c[u] == -1){
        c[u] = color;
    }

    for (auto v : g[u]){
        if (c[v] == -1){
            dfs(v, color^1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    ll n; cin >> n;
    
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(0, 0);

    ll a = 0, b = 0;
    for (int i = 0; i < n; i++){
        if (c[i] == 0) a++;
        else b++;
    }

    cout << (a*b) - n+1 << "\n";
}