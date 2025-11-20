#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

int n, m;

bool isValid(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

void solve(){
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int> (m));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int aux = 0;
            for (int k = 0; k < 4; k++){
                int cx = dx[k] + i;
                int cy = dy[k] + j;

                if (isValid(cx, cy)){
                    aux = max(aux, mat[cx][cy]);
                }
            }
            if (mat[i][j] < aux) continue;
            mat[i][j] = aux;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << mat[i][j] << " \n"[j == m-1];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}