#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;
    
    if (n >= m){
        cout << "YES" << "\n";
        return;
    }
    
    vector<ll> arr(n);
    for (auto &i : arr) {
        cin >> i;
        i %= m;
    }

    map<int, bool> dp;

    for (auto x : arr){
        map<int, bool> new_dp = dp;

        for (int i = 0; i < m; i++){
            if (dp[i]) new_dp[(x+i) % m] = 1;
        }

        new_dp[x%m] = 1;

        dp = new_dp;

        if (dp[0]){
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}