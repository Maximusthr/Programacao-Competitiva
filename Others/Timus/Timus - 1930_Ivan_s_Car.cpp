#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct P {
    int u, g;
};

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        x--, y--;
        g[x].push_back({y, 1});
        g[y].push_back({x, 0});
    }

    int st, end; cin >> st >> end;
    st--, end--;

    vector<vector<int>> dist(n, vector<int> (2, INF));
    dist[st][0] = dist[st][1] = 0;

    deque<P> dq;
    dq.push_back({st, 0});
    dq.push_back({st, 1});

    while(!dq.empty()){
        int u = dq.front().u;
        int gear = dq.front().g;
        dq.pop_front();

        if (u == end){
            cout << min(dist[end][0], dist[end][1]) << "\n";
            return;
        }

        for (auto [v, gr] : g[u]){
            if (gear == gr && dist[u][gear] < dist[v][gear]){
                dist[v][gear] = dist[u][gear];
                dq.push_front({v, gr});
            }
            else if (gear != gr && dist[u][gear] + 1 < dist[v][gr]){
                dist[v][gr] = dist[u][gear] + 1;
                dq.push_back({v, gr});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}