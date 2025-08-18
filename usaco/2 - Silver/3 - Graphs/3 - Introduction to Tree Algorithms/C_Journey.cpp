#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;
vector<int> dist;
vector<double> prob;

void bfs(int u){
    queue<int> q;
    q.push(u);

    while(!q.empty()){
        int v = q.front();
        q.pop();

        double atual = prob[v];
        double c = 0;
        for (auto w : g[v]){
            if (dist[w] == -1){
                c++;
            }
        }

        atual /= c;

        for (auto w : g[v]){
            if (dist[w] == -1){
                dist[w] = dist[v] + 1;
                prob[w] = atual; 
                q.push(w);
            }
        }
    }
}

void solve(){
    int n; cin >> n;

    g.resize(n);
    dist.resize(n, -1);
    prob.resize(n);

    for (int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y;
        x--, y--;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    dist[0] = 0;
    prob[0] = 1;
    bfs(0);

    double ans = 0;
    for (int i = 1; i < n; i++){
        if (g[i].size() == 1){
            ans += (double(dist[i]) * prob[i]);
        }
    }

    cout << fixed << setprecision(10) << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    solve();
}