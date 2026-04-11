#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<ll>> dist(n, vector<ll> (n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> dist[i][j];
        }
    }

    vector<int> nodes(n);
    for (auto &i : nodes) {
        cin >> i;
        i--;
    }

    vector<bool> vis(n);
    vector<ll> ans;
    for (int L = n-1; L >= 0; L--){

        int k = nodes[L];
        vis[k] = true;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }

        ll sum = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (vis[i] && vis[j]) sum += dist[i][j];
            }
        }

        ans.push_back(sum);
    }

    reverse(ans.begin(), ans.end());
    for (auto &i : ans) cout << i << " ";

    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}