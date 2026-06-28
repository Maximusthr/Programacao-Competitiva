#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;
    
    vector<vector<int>> a(n, vector<int> (m));
    vector<vector<int>> b(n, vector<int> (m));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char c; cin >> c;
            a[i][j] = (c - '0');
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            char c; cin >> c;
            b[i][j] = (c - '0');
        }
    }

    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < m - 1; j++){
            if (a[i][j] == b[i][j]) continue;
            else {
                if (a[i][j] == 0 && b[i][j] == 1 || a[i][j] == 1 && b[i][j] == 2 || a[i][j] == 2 && b[i][j] == 0){
                    a[i][j]++;
                    a[i][j] %= 3;
                    a[i][j+1] += 2;
                    a[i][j+1] %= 3;
                    a[i+1][j] += 2;
                    a[i+1][j] %= 3;
                    a[i+1][j+1]++;
                    a[i+1][j+1] %= 3;
                }
                else {
                    a[i][j] += 2;
                    a[i][j] %= 3;
                    a[i][j+1]++;
                    a[i][j+1] %= 3;
                    a[i+1][j]++;
                    a[i+1][j] %= 3;
                    a[i+1][j+1] += 2;
                    a[i+1][j+1] %= 3;
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (a[i][j] != b[i][j]){
                cout << "NO" << "\n";
                return;
            }
        }
    }

    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}