#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    set<int> dif;
    for (auto &i : arr) {
        cin >> i;
        dif.insert(i);
    }

    if (dif.size() <= k) {
        cout << 1 << "\n";
        return;
    }

    int ans = 0;
    vector<int> vis(n);
    while(true){
        bool flag = false;
        for (int i = 0; i < n; i++){
            if (arr[i] != 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << ans << "\n";
            return;
        }

        int dif = 0;
        int last = 0;
        set<int> choiced;
        for (int i = 0; i < n; i++){
            if (choiced.size() < k){
                choiced.insert(arr[i]);
                last = arr[i];
                arr[i] = 0;
            }
            else if (choiced.size() == k){
                vis[i]++;
                if (vis[i] > 1 && arr[i] == arr[i] - last){
                    cout << -1 << "\n";
                    return;
                }
                arr[i] -= last;
            }
        }
        ans++;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}