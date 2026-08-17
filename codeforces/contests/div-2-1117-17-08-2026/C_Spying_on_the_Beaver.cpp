#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++){
        int x; cin >> x;
        x--;

        g[i].push_back(x);
        g[x].push_back(i);
    }

    int m; cin >> m;
    vector<bool> nodes(n);
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        x--;
        nodes[x] = true;
    }

    if (m == 1){
        cout << 0 << "\n";
        return;
    }

    vector<int> prof(n, -1);
    queue<int> q;
    prof[0] = 0;
    q.push(0);
    
    vector<pair<int, int>> p;
    if (nodes[0]){
        p.push_back({prof[0], 0});
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (auto v : g[u]){
            if (prof[v] == -1){
                prof[v] = prof[u] + 1;
                q.push(v);

                if (nodes[v]){
                    p.push_back({prof[v], v});
                }
            }
        }
    }

    sort(p.begin(), p.end());

    cout << p.size() - 1 << " ";
    for (int i = 1; i < p.size(); i++){
        cout << p[i].second + 1 << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
