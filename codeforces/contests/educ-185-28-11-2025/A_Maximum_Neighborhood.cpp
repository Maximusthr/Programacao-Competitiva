#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<vector<int>> mat(n, vector<int> (n));
    int c = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            mat[i][j] = c++;
        }
    }

    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, 1, -1, 0};

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && x < n && y >= 0 && y < n);
    };

    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int aux = 0;
            for (int k = 0; k < 4; k++){
                int cx = i + dx[k];
                int cy = j + dy[k];

                if (isValid(cx, cy)){
                    aux += mat[cx][cy];
                }
            }
            aux += mat[i][j];

            ans = max(ans, aux);
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