#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef struct {
    int t, x, y;
} mov;

void solve(){
    int n; cin >> n;

    vector<pair<char, int>> steps;
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        int s; cin >> s;
        steps.push_back({c, s});
    }

    vector<mov> grid;
    pair<int, int> passos = {0, 0};
    int tempo = 0;
    for (int i = 0; i < n; i++){
        int aux = 0;
        while (aux < steps[i].second){
            aux++;
            tempo++;
            if (steps[i].first == 'N') {
                passos.second++;
            }
            else if (steps[i].first == 'S') {
                passos.second--;
            }
            else if (steps[i].first == 'E') {
                passos.first++;
            }
            else if (steps[i].first == 'W') {
                passos.first--;
            }
            grid.push_back({tempo, passos.first, passos.second});
        }
    }

    int ans = INF;
    for (int i = 0; i < grid.size(); i++){
        for (int j = i+1; j < grid.size(); j++){
            if (grid[i].x == grid[j].x && grid[i].y == grid[j].y){
                ans = min(ans, grid[j].t - grid[i].t);
            }
        }
    }

    if (ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    solve();
}