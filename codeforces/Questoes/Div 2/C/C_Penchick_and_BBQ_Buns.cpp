#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    if (n & 1 && n < 27) {
        cout << -1 << "\n";
        return;
    }

    if ((n & 1) == 0){
        int x = 1;
        for (int i = 0; i < n; i += 2){
            cout << x << " " << x << " ";
            x++;
        }
        cout << "\n";
    }
    else {
        vector<int> ans(n+1);
        ans[1] = 1;
        ans[10] = 1;
        ans[26] = 1;
        ans[11] = 2;
        ans[27] = 2;
        int x = 3;
        for (int i = 2; i <= n; i += 2){
            if (ans[i] != 0) {
                // i--;
                continue;
            }
            ans[i] = x;
            ans[i+1] = x;
            x++;
        }
        for (int i = 1; i <= n; i++){
            cout << ans[i] << " \n"[i == n];
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