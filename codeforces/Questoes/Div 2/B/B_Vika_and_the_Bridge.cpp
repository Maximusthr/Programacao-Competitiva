#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<vector<int>> arr(k);
    vector<int> last(k, -1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        x--;
        arr[x].push_back(i - 1 - last[x]);
        last[x] = i;
    }

    int ans = INF;
    for (int i = 0; i < k; i++){
        arr[i].push_back(n - 1 - last[i]);
        sort(arr[i].begin(), arr[i].end(), greater<int> ());

        int res = arr[i][0]/2;
        if (arr[i].size() > 1){
            res = max(res, arr[i][1]);
        }

        ans = min(res, ans);
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