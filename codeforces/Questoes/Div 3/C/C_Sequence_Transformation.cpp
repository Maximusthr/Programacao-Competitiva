#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    vector<vector<int>> a(n+1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a[x].push_back(i);
    }

    if (n == 1){
        cout << 0 << "\n";
        return;
    }

    int ans = INF;
    for (int i = 0; i <= n; i++){
        int aux = INF;
        for (int j = 0; j < a[i].size(); j++){

            if (a[i].size() == 1){
                if (a[i][j] != 0 && a[i][j] != n-1) aux = 2;
                else aux = 1;
                break;
            }

            if (j == 0){
                aux = 0;
                if (a[i][j] != 0) aux++;
            }
            else if (j == a[i].size()-1) {
                if (a[i][j] != n-1) {
                    if (a[i][j] != a[i][j-1] + 1) aux++;
                    aux++;
                }
                else if (a[i][j] != a[i][j-1] + 1) aux++;
            }
            else {
                if (a[i][j] != a[i][j-1] + 1) aux++;
            }
        }
        ans = min(ans, aux);
    }

    if (ans == INF) ans = 0;
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}