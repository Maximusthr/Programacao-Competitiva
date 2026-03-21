#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    vector<vector<int>> dist(n, vector<int> (m, INF));
    vector<vector<pair<int, int>>> t(26);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (arr[i][j] != '#' && arr[i][j] != '.'){
                t[arr[i][j] - 'a'].push_back({i, j});
            }
        }
    }

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m);
    };

    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});

    vector<bool> foi(26);

    while(!q.empty()){
        auto [u, v] = q.front();
        q.pop();

        if (u+1 == n && v+1 == m){
            cout << dist[u][v] << "\n";
            return;
        }

        if (arr[u][v] != '.' && !foi[arr[u][v] - 'a']){
            int tipo = arr[u][v] - 'a';

            for (int i = 0; i < t[tipo].size(); i++){
                int x = t[tipo][i].first;
                int y = t[tipo][i].second;

                if (dist[u][v] + 1 < dist[x][y]){
                    dist[x][y] = dist[u][v] + 1;
                    q.push({x, y});
                }
            }
            foi[tipo] = 1;
        }

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;

            if (isValid(cx, cy)){
                if (arr[cx][cy] == '#') continue;

                if (dist[u][v] + 1 < dist[cx][cy]){
                    q.push({cx, cy});
                    dist[cx][cy] = dist[u][v] + 1;
                }
            }
        }
    }

    cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}