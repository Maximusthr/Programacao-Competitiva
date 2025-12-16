#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n = 10;

    vector<string> mat(n);
    for (auto &i : mat) cin >> i;

    int ans = 0;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (mat[i][j] == 'X'){
                int x = i, y = j;

                x = min({abs(n - x - 1), abs(0 - x)});
                y = min(abs(n - y - 1), abs(0 - y));

                int v = min(x, y);
                if (v == 0) ans += 1;
                else if (v == 1) ans += 2;
                else if (v == 2) ans += 3;
                else if (v == 3) ans += 4;
                else ans += 5;
            }
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