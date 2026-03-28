#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<char>> arr(n+2, vector<char> (m+2, '.'));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }

    vector<pair<int, int>> aux;
    bool ok = false;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (arr[i][j] == '$'){
                aux.push_back({i, j});
            }
        }
    }

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x <= n+1 && y >= 0 && y <= m+1);
    };

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    vector<vector<int>> dist(n+2, vector<int> (m+2)), distp1(n+2, vector<int> (m+2)), distp2(n+2, vector<int> (m+2));
    for (int i = 0; i <= n+1; i++){
        for (int j = 0; j <= m+1; j++){
            dist[i][j] = INF;
            distp1[i][j] = INF;
            distp2[i][j] = INF;
        }
    }

    struct P {
        int u, v, d;
    };

    auto bfs01 = [&](vector<vector<int>> &dist, int x, int y) -> void {
        deque<P> deq;
        dist[x][y] = 0;
        deq.push_back({x, y, 0});
        while(!deq.empty()){
            int u, v, d;
            u = deq.front().u;
            v = deq.front().v;
            d = deq.front().d;

            deq.pop_front();

            for (int i = 0; i < 4; i++){
                int cx = dx[i] + u;
                int cy = dy[i] + v;

                if (isValid(cx, cy) && arr[cx][cy] != '*'){
                    int c = (arr[cx][cy] == '#' ? 1 : 0);

                    if (d + c < dist[cx][cy]){
                        if (c) deq.push_back({cx, cy, d + c});
                        else deq.push_front({cx, cy, d});

                        dist[cx][cy] = d + c;
                    }
                }
            }
        }
    };

    bfs01(dist, 0, 0);
    bfs01(distp1, aux[0].first, aux[0].second);
    bfs01(distp2, aux[1].first, aux[1].second);

    int ans = INF;
    for (int i = 0; i <= n+1; i++){
        for (int j = 0; j <= m+1; j++){
            if (dist[i][j] == INF) continue;

            int c = 0;
            if (arr[i][j] == '#'){
                c = 2;
            }
            ans = min(ans, dist[i][j] + distp1[i][j] + distp2[i][j] - c);
        }
    }

    cout << ans << "\n";
    
} 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}