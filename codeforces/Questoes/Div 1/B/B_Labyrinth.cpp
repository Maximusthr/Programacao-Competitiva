#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    int x0, y0; cin >> x0 >> y0;
    x0--, y0--;
    int lef, rig; cin >> lef >> rig;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    vector<vector<int>> dist(n, vector<int> (m, INF));

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && y >= 0 && x < n && y < m && arr[x][y] != '*');
    };

    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};

    struct P {
        int u, v, l, r, w;
    };

    deque<P> q;
    dist[x0][y0] = 0;
    q.push_front({x0, y0, lef, rig, 0});

    while(!q.empty()){
        auto [u, v, l, r, w] = q.front();
        q.pop_front();

        if (w > dist[u][v]) continue;

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;
            if (isValid(cx, cy)){
                if (i == 0){
                    // dy vai pra esquerda
                    if (l > 0 && dist[u][v] + 1 < dist[cx][cy]){
                        dist[cx][cy] = dist[u][v] + 1;
                        q.push_back({cx, cy, l-1, r, dist[cx][cy]});
                    }
                }
                else if (i == 1){
                    // dy vai pra direita
                    if (r > 0 && dist[u][v] + 1 < dist[cx][cy]){
                        dist[cx][cy] = dist[u][v] + 1;
                        q.push_back({cx, cy, l, r-1, dist[cx][cy]});
                    }
                }
                else if (dist[u][v] + 1 < dist[cx][cy]) {
                    dist[cx][cy] = dist[u][v] + 1;
                    q.push_front({cx, cy, l, r, dist[cx][cy]});
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (dist[i][j] != INF) ans++;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}