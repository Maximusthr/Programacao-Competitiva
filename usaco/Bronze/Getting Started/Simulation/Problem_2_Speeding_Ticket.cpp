#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    int s, speed;

    vector<pair<int, int>> seg;
    for (int i = 0; i < n; i++){
        cin >> s >> speed;
        seg.push_back({s, speed});
    }
    
    vector<pair<int, int>> cow;
    for (int i = 0; i < m; i++){
        cin >> s >> speed;
        cow.push_back({s, speed});
    }

    int ans = 0;

    int i = 0, j = 0;
    int road = seg[0].first;
    int c = cow[0].first;

    while(i < n && j < m){
        int overlap = min(road, c);
        ans = max(ans, cow[j].second - seg[i].second);

        road -= overlap;
        c -= overlap;

        if (road == 0){
            i++;
            if (i < n) road = seg[i].first;
        }
        if (c == 0){
            j++;
            if (j < m) c = cow[j].first;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    solve();
}
