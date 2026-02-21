#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    map<int, vector<int>> mapa;
    vector<bool> vis(n+1); // visitado nos indices
    vector<int> qtd(n+1); // indices que herdam do anterior

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        mapa[arr[i]].push_back(i);
    }

    auto dfs = [&](auto &&self, int u) -> int {
        if (vis[u]) return qtd[u];
        else vis[u] = true;

        if (mapa[arr[u]+1].size() == 0){
            mapa.erase(arr[u]+1);
            return 0;
        }

        int l = 0, r = mapa[arr[u]+1].size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if (u <= mapa[arr[u]+1][mid]) r = mid;
            else l = mid + 1;
        }
        if (mapa[arr[u]+1][l] <= u) return 0;

        return qtd[u] = self(self, mapa[arr[u]+1][l]) + 1;
    };

    bool usado = false;
    int ans = 1;
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            int v = dfs(dfs, i);
            ans = max(ans, v+1);
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}