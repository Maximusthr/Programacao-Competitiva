#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1005;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    

    int n; cin >> n;
    vector<pair<int, int>> p;

    vector<int> vis(MAX);

    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        p.push_back({x, y});


        for (int j = x; j < y; j++) vis[j]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = p[i].first; j < p[i].second; j++) vis[j]--;

        int temp = 0;
        for (int k = 0; k < MAX; k++){
            if (vis[k] > 0) temp++;
        }
        ans = max(ans, temp);

        for (int j = p[i].first; j < p[i].second; j++) vis[j]++;
    }

    cout << ans << "\n";
}
