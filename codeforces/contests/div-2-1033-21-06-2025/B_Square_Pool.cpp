#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, s; cin >> n >> s;

    vector<vector<int>> m(n, vector<int> (4));

    for (int i = 0; i < n; i++){
        for (int j = 0 ; j < 4; j++){
            cin >> m[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        if ((m[i][2] == m[i][3]) && ((m[i][0] == -1 && m[i][1] == -1) || (m[i][0] == 1 && m[i][1] == 1))){
            ans++;
            continue;
        }

        // diag secundaria
        int dist = s - max(m[i][2], m[i][3]);
        if (min(m[i][2], m[i][3]) - dist == 0){
            if ((m[i][0] == -1 && m[i][1] == 1) || (m[i][0] == 1 && m[i][1] == -1)) ans++;
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
