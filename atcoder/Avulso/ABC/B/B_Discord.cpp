#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    swap(n, m);

    vector<vector<int>> arr(n, vector<int> (m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];
            arr[i][j]--;
        }
    }

    vector<vector<bool>> pode(m, vector<bool> (m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (j > 0){
                pode[arr[i][j]][arr[i][j-1]] = 1;
                pode[arr[i][j-1]][arr[i][j]] = 1;
            }
            if (j + 1 < m){
                pode[arr[i][j]][arr[i][j+1]] = 1;
                pode[arr[i][j+1]][arr[i][j]] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if (i == j) continue;
            if (!pode[i][j]) ans++;
        }
    }

    cout << ans/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}