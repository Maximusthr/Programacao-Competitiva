#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    int stx, sty, endx, endy; cin >> stx >> sty >> endx >> endy;
    stx--, sty--, endx--, endy--;

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m);
    };

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    vector<vector<int>> dist(n, vector<int> (m, INF));
    dist[stx][sty] = 0;

    struct P{
        int w, x, y;
        bool operator>(P const p) const {
            return w > p.w;
        };
    };

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, stx, sty});

    while(!pq.empty()){
        auto [ch, u, v] = pq.top();
        pq.pop();

        if (ch > dist[u][v]) continue;

        if (u == endx && v == endy){
            cout << dist[u][v] << "\n";
            return;
        }

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;

            if (isValid(cx, cy)){
                if (arr[cx][cy] == '.'){
                    if (dist[u][v] < dist[cx][cy]){
                        dist[cx][cy] = dist[u][v];
                        pq.push({dist[cx][cy], cx, cy});
                    }
                }
                else {
                    // aplico um chute
                    if (dist[u][v] + 1 < dist[cx][cy]){
                        dist[cx][cy] = dist[u][v] + 1;
                        pq.push({dist[cx][cy], cx, cy});
                    }
                    // abro mais uma parede (mas ela precisa ser valida)
                    int ccx = cx + dx[i];
                    int ccy = cy + dy[i];

                    if (isValid(ccx, ccy)){
                        if (dist[u][v] + 1 < dist[ccx][ccy]){
                            dist[ccx][ccy] = dist[u][v] + 1;
                            pq.push({dist[ccx][ccy], ccx, ccy});
                        }
                    }
                }
            }
        }

    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}