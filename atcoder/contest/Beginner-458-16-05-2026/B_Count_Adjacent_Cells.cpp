#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<int>> arr(n, vector<int> (m));

    int dx[4] = {0, -1, 1, 0};
    int dy[4] = {1, 0, 0, -1};

    auto isValid = [&](int x, int y) -> bool {
        return (x >= 0 && y >= 0 && x < n && y < m);
    };

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for (int k = 0; k < 4; k++){
                int cx = i + dx[k];
                int cy = j + dy[k];

                if (isValid(cx, cy)) arr[i][j]++;
            }
        }
    }   
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << arr[i][j] << " \n"[j==m-1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}