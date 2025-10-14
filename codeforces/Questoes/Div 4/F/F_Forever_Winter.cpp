#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> g(n);

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    map<int, int> freq;
    
    for (int i = 0; i < n; i++){
        freq[g[i].size()]++;
    }

    int root = -1;
    int sec = 0;
    for (auto [x, y] : freq){
        if (y == 1) root = x;
        if (y > 1 && x != 1) sec = x-1;
    }
    if (root == -1) {
        root = sec + 1;
    }
    cout << root << " " << sec << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}