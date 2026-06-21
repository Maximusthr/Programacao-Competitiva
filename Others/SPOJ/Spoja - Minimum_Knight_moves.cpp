#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<int>> g;
// vector<vector<bool>> vis;
vector<vector<int>> dist;

int n = 8;

int pos_X[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int pos_Y[] = {-2, -2, -1, -1, 1, 1, 2, 2};

bool isValid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < n && dist[x][y] == -1);
}

char a, b, lixo, c, d;

void bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});

    // vis[i][j] = true;
    dist[i][j] = 0;

    while(!q.empty()){
        auto [v, w] = q.front();

        q.pop();

        if (v == c-'a' && w == d-'0'-1) {
            cout << dist[v][w] << "\n";
            return;
        }

        for (int i = 0; i < 8; i++){
            int x = pos_X[i] + v;
            int y = pos_Y[i] + w;

            if (isValid(x, y)){
                // vis[x][y] = true;
                dist[x][y] = dist[v][w] + 1;
                q.push({x, y});
            }
        }
    }
}

void solve(){

    cin >> a >> b >> c >> d;

    g.assign(n, vector<int> (n, 0));
    // vis.assign(n, vector<bool> (n, 0));
    dist.assign(n, vector<int> (n, -1));

    bfs(a-'a', b-'0'-1);

    g.clear();
    // vis.clear();
    dist.clear();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}