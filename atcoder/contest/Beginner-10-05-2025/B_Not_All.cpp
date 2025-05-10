#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> arr(n);
    vector<int> vis(m+1);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        vis[arr[i]]++;
    }

    int ans = 0;
    bool ok = true;
    for (int i = 1; i <= m; i++){
        if (vis[i] == 0) {
            ok = false;
            break;
        }
    }

    if (!ok) cout << ans << "\n";
    else {
        for (int i = n-1; i >= 0; i--){
            vis[arr[i]]--;
            ans++;
            if (vis[arr[i]] == 0) {
                cout << ans << "\n";
                break;
            }
        }
    }

}