#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = 0;
    int menor = INF;
    bool flag = false;
    for (int i = n-1; i > 0; i--){
        if (arr[i] < arr[i-1]){
            flag = true;
            menor = min(menor, arr[i]);
            ans++;
        }
        else if (flag && arr[i-1] <= menor){
            cout << -1 << "\n";
            return;
        }
        else if (flag){
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