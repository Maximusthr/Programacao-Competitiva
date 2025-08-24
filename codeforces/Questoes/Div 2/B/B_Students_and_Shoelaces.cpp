#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 105;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<vector<int>> g(MAX, vector<int> (MAX));
    vector<vector<int>> temp(MAX, vector<int> (MAX));

    for (int i = 0; i < m; i++){
        int x, y; cin >> x >> y;

        x--, y--;

        g[x][y] = 1;
        g[y][x] = 1;
        temp[x][y] = 1;
        temp[y][x] = 1;
    }

    int ans = 0;

    while(true){
        bool tirou = false;

        for (int i = 0; i < n; i++){
            vector<pair<int, int>> idx;
            
            for (int j = 0; j < n; j++){
                if (g[i][j]) idx.push_back({i, j});
                if (idx.size() > 1) break;
            }

            if (idx.size() == 1){
                tirou = true;
                temp[idx[0].first][idx[0].second] = 0;
                temp[idx[0].second][idx[0].first] = 0;
            }
        }
        
        if (!tirou) break;
        ans++;
        g = temp;
    }

    cout << ans << "\n";
}