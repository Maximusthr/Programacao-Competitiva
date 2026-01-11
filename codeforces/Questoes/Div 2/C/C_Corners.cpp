#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<char>> mat(n, vector<char> (m));

    int um = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
            if (mat[i][j] == '1') um++;
        }
    }

    int dx[8] = {-1, 0, 0, 1, 1, -1, 1, -1};
    int dy[8] = {0, 1, -1, 0, 1, -1, -1, 1};

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && y >= 0 && x < n && y < m);
    };

    bool pode = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (mat[i][j] == '1') continue;

            int tem = 1;

            for (int k = 0; k < 8; k++){
                int cx = dx[k] + i;
                int cy = dy[k] + j;

                if (isValid(cx, cy)){
                    if (mat[cx][cy] == '0') tem++;
                }
            }

            if (tem >= 2){
                cout << um << "\n";
                return;
            }
            if (tem == 1){
                pode = true;
            }
        }
    }

    if (pode){
        cout << um-1 << "\n";
    }
    else {
        cout << um-2 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}