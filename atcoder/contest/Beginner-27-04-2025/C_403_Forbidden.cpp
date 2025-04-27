#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10;
vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m, q; cin >> n >> m >> q;

    for (int i = 0; i < q; i++){
        int x; cin >> x;
        if (x == 1){
            int y, z; cin >> y >> z;
            y--;
            z--;
            g[z].push_back(y);
        }
        else if (x == 2){
            int y; cin >> y;
            y--;
            vis[y] = true;
        }
        else if (x == 3){
            int y, z; cin >> y >> z;
            y--;
            z--;
            if (vis[y]) cout << "Yes" << "\n";
            else {
                bool ok = false;
                for (auto a : g[z]){
                    if (a == y){
                        cout << "Yes" << "\n";
                        ok = true;
                        break;
                    }
                }
                if (!ok) cout << "No" << "\n";
            }
        }
    }
}
