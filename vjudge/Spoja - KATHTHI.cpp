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

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < m);
    };

    struct P {
        char c;
        int u, v;
    };

    deque<P> deq;
    dist[0][0] = 0;
    deq.push_front({arr[0][0], 0, 0});

    while(!deq.empty()){
        auto [c, u, v] = deq.front();
        deq.pop_front();

        for (int i = 0; i < 4; i++){
            int cx = dx[i] + u;
            int cy = dy[i] + v;

            if (isValid(cx, cy)){
                if (c != arr[cx][cy]){
                    if (dist[u][v] + 1 < dist[cx][cy]){
                        dist[cx][cy] = dist[u][v] + 1;
                        deq.push_back({arr[cx][cy], cx, cy});
                    }
                }
                else if (dist[u][v] < dist[cx][cy]){
                    dist[cx][cy] = dist[u][v];
                    deq.push_front({arr[cx][cy], cx, cy});
                }
            }
        }
    }   

    cout << dist[n-1][m-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    while(t--){
        solve();   
    }
}