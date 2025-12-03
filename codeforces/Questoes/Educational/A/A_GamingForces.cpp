#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    int one = 0;
    for (auto &i : arr) {
        cin >> i;
        if (i == 1){
            one++;
        }
    }

    int ans = one/2 + n - one + (one % 2 ? 1 : 0);
    
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}