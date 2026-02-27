// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    vector<pair<int, int>> arr(n);
    for (auto &i : arr) cin >> i.first;
    for (auto &i : arr) cin >> i.second;
    
    map<int, vector<int>> mapa;
    for (int i = 0; i < n; i++){
        mapa[arr[i].first].push_back(arr[i].second);
    }
    
    mapa[x2].push_back(y2);

    ll dp[mapa.size()+2][2];
    memset(dp, 0, sizeof(dp));

    pair<int, int> L, H;
    L = H = {x1, y1};

    int j = 1;
    for (auto [x, y] : mapa){
        sort(y.begin(), y.end());

        ll dist = 0;
        for (int i = 1; i < y.size(); i++){
            dist += abs(y[i] - y[i-1]);
        }        

        ll low_low = abs(L.first - x) + abs(L.second - y[0]);
        ll high_low = abs(H.first - x) + abs(H.second - y[0]);

        ll high_high = abs(H.first - x) + abs(H.second - y[y.size()-1]);
        ll low_high = abs(L.first - x) + abs(L.second - y[y.size()-1]);

        // dp[x][0] -> high
        // dp[x][1] -> low

        dp[j][0] = min(dp[j-1][0] + high_low, dp[j-1][1] + low_low) + dist;
        dp[j][1] = min(dp[j-1][1] + low_high, dp[j-1][0] + high_high) + dist;

        L = {x, y[0]};
        H = {x, y[y.size()-1]};

        j++;
    }

    cout << min(dp[j-1][0], dp[j-1][1]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}