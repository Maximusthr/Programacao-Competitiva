#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;

const int MAX = 2e5+1;
vector<vector<int>> g(MAX);
vector<int> deg(MAX);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }

    // greedy
    int best = 0;
    int minsize = deg[0] + 1;
    for (int i = 1; i < n; i++){
        if (deg[i] + 1 < minsize){
            minsize = deg[i] + 1;
            best = i;
        }
    }

    vector<int> ans(n, 1);
    ans[best] = 0;
    for (int v : g[best]){
        ans[v] = 0;
    }

    for (int x : ans) cout << x << " ";

    cout << "\n";
}
