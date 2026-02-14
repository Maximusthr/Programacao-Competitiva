#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    map<int, int> mapa;

    int ans = 0;
    int l = 0, r = 0;
    while (r < n){
        while(r < n && mapa[arr[r]] == 0){
            mapa[arr[r]]++;
            ans = max(ans, r - l + 1);
            r++;
        }

        if (r == n) break;

        while(l < r && mapa[arr[r]] > 0){
            mapa[arr[l]]--;
            l++;
        }
    }
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}