#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> arr(m+1);
    for (int i = 1; i <= m; i++){
        cin >> arr[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;

        ans += min(arr[x], y);
        arr[x] -= min(arr[x], y);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}