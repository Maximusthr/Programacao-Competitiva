#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    map<ll, bool> vis;

    ll ans = 0;
    for (int i = 0; i < n-1; i++){
        if (!vis[arr[i]] && (arr[i+1] - arr[i] + 1 + k) <= (2 + 2*k)){
            vis[arr[i]] = true;
            vis[arr[i+1]] = true;
            ans += (arr[i+1] - arr[i] + 1 + k);
        }
        else if (vis[arr[i]]){
            if (arr[i+1] - arr[i] <= 1 + k){
                ans += (arr[i+1] - arr[i]);
                vis[arr[i+1]] = true;
            }
        }
        else {
            ans += 1 + k;
            vis[arr[i]] = true;
        }
    }

    if (!vis[arr[n-1]]) ans += 1 + k;

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    solve();
}
