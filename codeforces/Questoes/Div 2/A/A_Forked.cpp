#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int x, y; cin >> x >> y;

    int kx, ky; cin >> kx >> ky;
    int qx, qy; cin >> qx >> qy;

    set<pair<int, int>> cord = {{x, y}, {-x, y}, {x, -y}, {-x, -y},
                                    {y, x}, {y, -x}, {-y, x}, {-y, -x}};

    vector<pair<int, int>> coord = {cord.begin(), cord.end()};

    int ans = 0;
    for (int i = 0; i < coord.size(); i++){
        int cx = kx + coord[i].first;
        int cy = ky + coord[i].second;

        for (int j = 0; j < coord.size(); j++){
            int dx = cx + coord[j].first;
            int dy = cy + coord[j].second;

            if (dx == qx && dy == qy) ans++;
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