#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

//upsolve

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<char>> arr(n, vector<char> (m));
    pair<int, int> start, end;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            if (arr[i][j] == 'S') start = {i, j};
            if (arr[i][j] == 'G') end = {i, j};
        }
    }

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#');
    };

    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};

    bool ok = false;
    int times = 0;

    // o precisa andar na mesma direção
    // x precisa mudar a direção

    struct P {
        int u, v, idx, tipo;
    };

    queue<P> q;
    vector<vector<vector<bool>>> vis(n, vector<vector<bool>> (m, vector<bool> (4)));
    
    q.push({start.first, start.second, -1, -1});
    for (int i = 0; i < 4; i++){
        vis[start.first][start.second][i] = true;
    }

    struct t {
        int u, v, i;
    };

    vector<vector<vector<t>>> pai(n, vector<vector<t>> (m, vector<t> (4)));

    while(!q.empty()){
        int u = q.front().u;
        int v = q.front().v;
        int idx = q.front().idx;
        int tipo = q.front().tipo;
        q.pop();

        if (u == end.first && v == end.second){
            vector<char> path;

            for (t at = {u, v, idx}; at.u != start.first || at.v != start.second;){
                if (at.u - pai[at.u][at.v][at.i].u == -1){
                    path.push_back('U');
                }
                else if (at.u - pai[at.u][at.v][at.i].u == 1){
                    path.push_back('D');
                }
                else if (at.v - pai[at.u][at.v][at.i].v == -1){
                    path.push_back('L');
                }
                else {
                    path.push_back('R');
                }
                
                at = pai[at.u][at.v][at.i];
            }
            
            reverse(path.begin(), path.end());
            
            cout << "Yes" << "\n";
            for (auto &i : path) cout << i;
            cout << "\n";
            return;
        }

        for (int i = 0; i < 4; i++){
            if (tipo == 1) {
                if (i != idx) continue;
            }
            else if (tipo == 0) {
                if (i == idx) continue;          
            }

            int cx = dx[i] + u;
            int cy = dy[i] + v;

            if (isValid(cx, cy) && !vis[cx][cy][i]){
                if (arr[cx][cy] == '.'){
                    q.push({cx, cy, i, -1});
                    pai[cx][cy][i] = {u, v, idx};
                    vis[cx][cy][i] = true;
                }
                else if (arr[cx][cy] == 'o'){
                    // so pode andar pra frente
                    q.push({cx, cy, i, 1});
                    pai[cx][cy][i] = {u, v, idx};
                    vis[cx][cy][i] = true;
                }
                else {
                    // pode andar em qualquer direção, menos na que veio
                    q.push({cx, cy, i, 0});
                    pai[cx][cy][i] = {u, v, idx};
                    vis[cx][cy][i] = true;
                }
            }
        }
    }

    cout << "No" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}