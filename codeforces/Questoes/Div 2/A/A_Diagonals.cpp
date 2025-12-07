#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> a(2*n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            a[i + j]++;
        }
    }

    sort(a.begin(), a.end(), greater<int> ());

    int ans = 0;
    for (int i = 0; i < 2*n; i++){
        if (k > 0){
            k -= min(k, a[i]);
            ans++;
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