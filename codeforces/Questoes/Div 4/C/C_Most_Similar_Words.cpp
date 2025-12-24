#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<string> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = INF;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            int aux = 0;
            for (int l = 0; l < k; l++){
                aux += abs(arr[i][l] - arr[j][l]);
            }
            ans = min(aux, ans);
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