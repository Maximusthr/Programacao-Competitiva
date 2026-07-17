#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back(i);
        g[y].push_back(i);
    }
    
    bool ok = false;
    vector<int> edge(n-1, -1);
    for (int i = 0; i < n; i++){
        if (g[i].size() >= 3){
            edge[g[i][0]] = 0;
            edge[g[i][1]] = 1;
            edge[g[i][2]] = 2;
            ok = true;
            break;
        }
    }

    int k = (ok ? 3 : 0);
    for (int i = 0; i < n-1; i++){
        if (edge[i] == -1){
            edge[i] = k++;
        }
    }

    for (auto &i : edge) cout << i << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}