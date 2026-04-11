#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
// upsolve
void solve(){
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int> (n));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> dist(n, vector<int> (n, INF));

    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (k == i || k == j) continue;
                dist[i][j] = min(dist[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            if (arr[i][j] > dist[i][j]){
                cout << -1 << "\n";
                return;
            }
            if (arr[i][j] == dist[i][j]) ans++;
        }
    }

    cout << ans/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}