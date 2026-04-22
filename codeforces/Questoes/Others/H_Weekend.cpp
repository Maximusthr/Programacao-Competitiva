#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int c = 1;
void solve(){
    int n, m, f; cin >> n >> m >> f;

    vector<vector<int>> dist(n, vector<int> (n, INF));

    for (int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w;
        x--, y--;
        dist[x][y] = min(dist[x][y], w);
        dist[y][x] = min(dist[y][x], w);
    }

    for (int i = 0; i < n; i++){
        dist[i][i] = 0;
    }

    vector<int> friends(f);
    for (auto &i : friends) {
        cin >> i;
        i--;
    }

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    sort(friends.begin(), friends.end());

    int ans = INF;
    do {
        int aux = dist[0][friends[0]];

        for (int i = 1; i < f; i++){
            aux += dist[friends[i-1]][friends[i]];
        }

        aux += dist[friends.back()][n-1];
        ans = min(ans, aux);

    } while (next_permutation(friends.begin(), friends.end()));

    cout << "Case " << c++ << ": " << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}