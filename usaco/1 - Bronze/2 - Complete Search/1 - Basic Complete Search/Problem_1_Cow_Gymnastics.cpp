#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){

    int k, n; cin >> k >> n;
    
    vector<vector<int>> rank(k, vector<int> (n));

    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            cin >> rank[i][j];
        }
    }

    vector<int> val(n);
    iota(val.begin(), val.end(), 1);

    vector<bool> vis(n+1);

    int ans = 0;
    for (int i = 0; i < n; i++){
        int elem = val[i];
        vis[elem] = true;
        for (int j = 0; j < k; j++){
            for (int l = 0; l < n; l++){
                if (rank[j][l] == elem) break;
                vis[rank[j][l]] = true;
            }
        }

        for (int p = 1; p <= n; p++){
            if (!vis[p]) ans++;
        }
        vis.assign(n+1, 0);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    solve();
}