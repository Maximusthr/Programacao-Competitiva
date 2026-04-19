#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
// upsolve
void solve(){
    int n, m; cin >> n >> m;

    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    string start; cin >> start;

    vector<vector<int>> mat(n+1, vector<int> (m+1));

    //          UL, UR, DL, DR
    int dx[4] = {-1, -1, 1, 1};
    int dy[4] = {-1, 1, -1, 1};

    int ans = 0;
        
    while (true){
        if (mat[x2][y2] > 0){
            cout << --ans << "\n";
            return;
        }
        if (start == "UL"){
            while (x1 >= 1 && y1 >= 1){
                if (mat[x1][y1] > 10){
                    cout << -1 << "\n";
                    return;
                }
                mat[x1][y1]++;
                x1 += dx[0];
                y1 += dy[0];
            }
            x1++, y1++;
            ans++;
            if (x1 == 1 && y1 == 1){
                start = "DR";
            }
            else if (x1 == 1){
                start = "DL";
            }
            else if (y1 == 1){
                start = "UR";
            }
        }
        else if (start == "UR"){
            while (x1 >= 1 && y1 <= m){
                if (mat[x1][y1] > 10){
                    cout << -1 << "\n";
                    return;
                }
                mat[x1][y1]++;
                x1 += dx[1];
                y1 += dy[1];
            }
            x1++, y1--;
            ans++;
            if (x1 == 1 && y1 == m){
                start = "DL";
            }
            else if (x1 == 1){
                start = "DR";
            }
            else if (y1 == m){
                start = "UL";
            }
        }
        else if (start == "DL"){
            while (x1 <= n && y1 >= 1){
                if (mat[x1][y1] > 10){
                    cout << -1 << "\n";
                    return;
                }
                mat[x1][y1]++;
                x1 += dx[2];
                y1 += dy[2];
            }
            x1--, y1++;
            ans++;
            if (x1 == n && y1 == 1){
                start = "UR";
            }
            else if (x1 == n){
                start = "UL";
            }
            else if (y1 == 1){
                start = "DR";
            }
        }
        else if (start == "DR") {
            while (x1 <= n && y1 <= m){
                if (mat[x1][y1] > 10){
                    cout << -1 << "\n";
                    return;
                }
                mat[x1][y1]++;
                x1 += dx[3];
                y1 += dy[3];
            }
            x1--, y1--;
            ans++;
            if (x1 == n && y1 == m){
                start = "UL";
            }
            else if (x1 == n){
                start = "UR";
            }
            else if (y1 == m){
                start = "DL";
            }
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